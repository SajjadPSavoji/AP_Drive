#include "admin_user.hpp"
using namespace std;
User* Admin::make_new_user(std::string user_name, std::string pass)
{
	return new Normal(user_name, pass);
}
void Admin::validate_promote_type(std::string type)
{
	if(type != SUPER_USER)
	{
		throw Exp("invalid permotion type : "+type);
	}
}
void Admin::validate_demote_type(std::string type)
{
	if(type != NORMAL)
	{
		throw Exp("invalid demotion type : "+type);
	}
}