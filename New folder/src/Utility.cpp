#include "Utility.h"
#include <string>
using namespace std;
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
