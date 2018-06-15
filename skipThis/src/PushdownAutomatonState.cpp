#include "PushdownAutomatonState.h"
#include <string>
#include <sstream>
int PushdownAutomatonState::n = 1;

PushdownAutomatonState::PushdownAutomatonState(string label) :
	label(label)
{
}

PushdownAutomatonState::~PushdownAutomatonState()
{
}

const string PushdownAutomatonState::getLabel() const
{
	return this->label;
}

const bool PushdownAutomatonState::operator==(const PushdownAutomatonState & other) const
{
	return this->getLabel() == other.getLabel();
}
namespace patch
{
    template < typename T > std::string to_string( const T& n )
    {
        std::ostringstream stm ;
        stm << n ;
        return stm.str() ;
    }
}

PushdownAutomatonState PushdownAutomatonState::generate()
{
	return PushdownAutomatonState("AUTO " + patch::to_string(PushdownAutomatonState::n++));
}
