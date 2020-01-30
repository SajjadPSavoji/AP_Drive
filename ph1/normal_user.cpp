#include "normal_user.hpp"
using namespace std;
void Normal::validate_promote_type(std::string type)
{
	if(type != ADMIN && type != SUPER_USER)
	{
		throw Exp("invalid permotion type");
	}
}
void Normal::validate_demote_type(std::string type)
{
	throw Exp("this user can not be demoted");
}