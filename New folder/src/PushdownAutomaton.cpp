#include "PushdownAutomaton.h"
#include<iostream>
using namespace std;
#include <string>
using namespace std;


PushdownAutomaton::PushdownAutomaton(const set<Rule> & rules, const Variable & pds)
{
	this->initialVariableOfGrammar = pds;
	this->initialState = PushdownAutomatonState::generate();

	set<Terminal> terminals = Utility::getTerminals(rules);
    //see howtoPDA
	for   (auto terminal :terminals)
	{
		this->addTransition(PushdownAutomatonTransition(
			this->initialState,
			terminal,
			new Terminal(terminal),
			this->initialState,
			RightSide()));
         //  cout<<"( "<<initialState.getLabel()<<" "<<terminal.getLabel()<<" "<<terminal.getLabel()<< ")"<<" ("<<initialState.getLabel()<<" "<<RightSide().toString()<< " )"<<endl;

	}

	for   (auto rule :rules)
	{
		this->addTransition(PushdownAutomatonTransition(
			this->initialState,
			Terminal(),
			new Variable(rule.getLeftSide()),
			this->initialState,
			rule.getRightSide()));

           // cout<<this->initialState.getLabel()<<" "<<Terminal().getLabel()<<" "<<rule.getLeftSide().getLabel()<< " "<<this->initialState.getLabel()<< " "<<rule.getRightSide().toString()<<endl;

	}
}

PushdownAutomaton::PushdownAutomaton()
{
}


PushdownAutomaton::~PushdownAutomaton()
{
}

void PushdownAutomaton::addTransition(const PushdownAutomatonTransition & newTransition)
{
	this->transitions.push_back(newTransition);
}

const vector<PushdownAutomatonTransition> PushdownAutomaton::getTransitions() const
{
	return this->transitions;
}

const bool PushdownAutomaton::wordBelongsToLanguage(string word) const
{
	RightSide initialStack;

	initialStack.append(this->initialVariableOfGrammar);

	PushdownAutomatonConfiguration initialConfiguration(
		this->initialState,
		word,
		initialStack);
   //configuration is : state," word given " ,top of the stack Transition

	// perform Breadth-first search
	queue<PushdownAutomatonConfiguration> q;

	q.push(initialConfiguration);
	//cout<<"initial state added: "<<endl;
	initialConfiguration.print();
	//initialConfiguration.print();

	while (!q.empty())
	{
		PushdownAutomatonConfiguration current = q.front();
		q.pop();

		if (current.isAccepting())
		{
			return true;
		}
		else
		{
			auto configurations = current.getAdjacentConfigurations(this->transitions); //pass all transitions ( ... ) ( ..) calling on PAconfig
			for   (auto configuration :configurations)
			{
				q.push(configuration);
			}
		}
	}

	return false;
}
