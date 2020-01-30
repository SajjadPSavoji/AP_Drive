#include "super_user.hpp"
using namespace std;
void Super::validate_demote_type(std::string type)
{
	if(type != NORMAL && type !=ADMIN)
	{
		throw Exp("invalid demotion type : "+type);
	}
}
