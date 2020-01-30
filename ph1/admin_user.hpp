#ifndef ADMIN_USER_HEADER_GUARD
#define ADMIN_USER_HEADER_GUARD
#include "normal_user.hpp"
class Admin : public Normal
{
public:
	Admin(std::string name,std::string pass):Normal(name ,pass){}
	~Admin(){}
	User* make_new_user(std::string user_name, std::string pass);
	void  validate_promote_type(std::string type);
	void  validate_demote_type(std::string type);
	void  user_list(std::vector<User*> users){std::cout<<users;}
	void validate_storage(){}
};
#endif



