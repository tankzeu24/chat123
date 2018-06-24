#include "PushdownAutomatonConfiguration.h"
#include<iostream>
using namespace std;

#include <string>
using namespace std;



PushdownAutomatonConfiguration::PushdownAutomatonConfiguration(PushdownAutomatonState pas, string currentWord, RightSide topOfStack)
	:
	state(pas),
	currentWord(currentWord),
	topOfStack(topOfStack)
{
}

void PushdownAutomatonConfiguration::print()
{
    //cout<<"("<< state.getLabel()<<","<<currentWord<<","<<topOfStack.toString()<<")"<<endl;
}


PushdownAutomatonConfiguration::~PushdownAutomatonConfiguration()
{
}

const PushdownAutomatonState PushdownAutomatonConfiguration::getState() const
{
	return this->state;
}

const string PushdownAutomatonConfiguration::getCurrentWord() const
{
	return this->currentWord;
}

const RightSide PushdownAutomatonConfiguration::getTopOfStack() const
{
	return this->topOfStack;
}

const bool PushdownAutomatonConfiguration::isAccepting() const
{
	return this->currentWord == "" && this->topOfStack.empty();
}

const vector<PushdownAutomatonConfiguration> PushdownAutomatonConfiguration::getAdjacentConfigurations(const vector<PushdownAutomatonTransition> rules) const
{
	vector<PushdownAutomatonConfiguration> possibleConfigurations;

	for (auto rule : rules)
	{
		if (rule.getCurrentState() == this->getState() &&
			(rule.getCharacterInWord() == Terminal(this->currentWord[0]) ||
				rule.getCharacterInWord().isBlankWord()) &&
			this->getTopOfStack().startsWith(rule.getTopOfStack()))
		{


			possibleConfigurations.push_back(this->goToNextConfiguration(rule));
		}
	}

	return possibleConfigurations;
}

PushdownAutomatonConfiguration PushdownAutomatonConfiguration::goToNextConfiguration(const PushdownAutomatonTransition rule) const
{
	if (rule.getCharacterInWord().isBlankWord())
	{
		return PushdownAutomatonConfiguration(
			rule.getNextState(),
			this->currentWord,
			this->getTopOfStack().replaceBeginning(rule.getNextTopOfStack())
			);

			//
	}

	else
	{
		return 	PushdownAutomatonConfiguration(
			rule.getNextState(),
			this->currentWord.substr(1, this->currentWord.length() - 1),
			this->getTopOfStack().replaceBeginning(rule.getNextTopOfStack())
			);
	}

}

bool operator==(const PushdownAutomatonConfiguration & pac1, const PushdownAutomatonConfiguration & pac2)
{
	return pac1.currentWord == pac2.currentWord &&
		pac1.state == pac2.state &&
		pac1.topOfStack == pac2.topOfStack;
}
