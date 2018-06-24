#include "IRightHandSideElement.h"
#include <string>
using namespace std;



const bool areEqual(const IRightHandSideElement * r1, const IRightHandSideElement * r2)
{
	return ((r1->isTerminal() && r2->isTerminal()) ||
		(r1->isVariable() && r2->isVariable())) &&
		(r1->toString() == r2->toString());
}
