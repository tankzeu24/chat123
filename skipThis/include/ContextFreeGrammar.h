#pragma once
#include <set>
#include <map>
#include <stack>
#include <string>
#include "Variable.h"
#include "Terminal.h"
#include "Rule.h"

using namespace std;

class WordBelongsToLanguageMethodSelector;

class ContextFreeGrammar
{
public:
    void printRules();
	ContextFreeGrammar();
	ContextFreeGrammar(const set<Rule> & rules, const Variable & variable);
	~ContextFreeGrammar();

	void addVariable(const Variable & v);
	void addTerminal(const Terminal & t);
	void addRule(const Rule & r);
	void RemoveRule(const Rule &r);

	void setInitialVariable(const Variable & v);

	const set<Variable> & getVariables() const;
	const set<Terminal>& getTerminals() const;
	const set<Terminal>& getTerminals(set<Terminal> & terminals) const;
	const set<Rule> & getRules() const;
	const Variable getInitialVariable() const;
	const set<Rule> & getUnitRules(set<Rule>& result) const;

	WordBelongsToLanguageMethodSelector wordBelongsToLanguage(string word) const;

	const bool isChomskyNormal() const;
	void convertToChomskyNormal();
	void epsilonRulesElimination();
	void eliminateCyclicUnitRules();

	void eliminateUncyclicUnitRules();
	const Rule getUnitRuleWithRightSideNotInGraph(const set<Rule> & unitRules);
	const set<Rule> getRulesFrom(const Variable & v, const set<Rule> & rules);
	void removeUnitRulesThatGoTo(const Variable & v);

	void eliminateMixedRules();

	void eliminateRulesWithLongRightSide();
	const Rule existsRuleWithLongRightSide() const;

	// extracts the strongly connected components from the graph
	// which is a result from the rules
	const set<set<Variable> > extractStronglyConnectedComponents(const set<Rule> & rules) const;

	const set<Variable> getUnitVariables(const set<Rule> & rules) const;

	const Variable existsRuleThatGoesToEpsilonSet(const set<Variable> & epsilonSet) const;
	const Rule & existsRuleContainingVariableFromEpsilonSet(const set<Variable> & epsilonSet, Rule & result) const;
	// returns all variable that should be replaced

	void unifyAllVariables(const set<Variable> & variables, set<Rule>& rules);
	void replaceVariableWith(const Variable & v, const Variable & replacing, set<Rule> & rulesToBeReplaced);

	const set<Variable> & extractEpsilonSet(set<Variable> & epsilonSet) const;
	void addRulesWithoutEpsilonVariables(set<Variable> & epsilonSet);
	void removeRulesWithEmptyRightSide();

	const Variable & generateVariable(Variable & v) const;

	static int autoGeneratedVariables;

	friend ContextFreeGrammar & operator<<(ContextFreeGrammar & cfg, string toRead);

	void createAsUnionOf(const ContextFreeGrammar & cfg1, const ContextFreeGrammar & cfg2);
	void createAsConcatenationOf(const ContextFreeGrammar & cfg1, const ContextFreeGrammar & cfg2);
	void createAsIterationOf(const ContextFreeGrammar & cfg);

	const bool languageIsEmpty() const;
	const bool languageIsFinite() const;
private:
	set<Variable> variables;
	set<Terminal> terminals;
	set<Rule> rules;
	Variable initialVariable;

	// extracts a strongly component using the Tarjan component
	void tarjanStronglyConnected(
		const Variable & unitVariable,
		const set<Variable> & unitVariables,
		const set<Rule> & unitRules,
		stack<Variable> & s,
		int & globalIndex,
		map<Variable, int> & index,
		map<Variable, int> & lowlink,
		map<Variable, bool> & onStack,
		set<set<Variable>> & result) const;
};
