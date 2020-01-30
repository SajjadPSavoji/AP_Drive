#ifndef SUPER_USER_EADER_GUARD
#define SUPER_USER_EADER_GUARD 
#include "admin_user.hpp"
class Super :public Admin 
{
public:
	Super(std::string name,std::string pass):Admin(name ,pass){}
	~Super(){}
	void validate_promote_type(std::string type){throw Exp("can not be permoted");}
	void validate_demote_type(std::string type);
	User* promote(User* user , std::string type){user->validate_promote_type(type);}
	User* demote(User* user , std::string type){user->validate_demote_type(type);}
	
};
#endif