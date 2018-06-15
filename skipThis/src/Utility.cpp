#include "Utility.h"

set<Terminal> Utility::getTerminals(const set<Rule>& rules)
{
	set<Terminal> result;

	for (auto rule : rules)
	{
		set<Terminal> terminalsInCurrentRule = rule.getTerminals();
		result.insert(terminalsInCurrentRule.begin(), terminalsInCurrentRule.end());
	}

	return result;
}
