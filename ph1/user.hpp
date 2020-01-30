#ifndef USER_HEADER_GUARD
#define USER_HEADER_GUARD
#include <iostream>
#include <vector>

#include "exception.hpp"

#define ADMIN "admin"
#define SUPER_USER "superuser"
#define NORMAL "normal"
class User
{
public:
	User(std::string user_name, std::string pass) : _user_name(user_name),_pass(pass){}
	bool is_pass(std::string pass){return _pass==pass;}
	virtual User* make_new_user(std::string user_name, std::string pass){
		throw Exp("this user can not add new users");}
	virtual ~User()=0;
	virtual void validate_promote_type(std::string type)=0;
	virtual void validate_demote_type(std::string type)=0;
	virtual User* promote(User* user,std::string type){throw Exp("this user can not promote");}
	virtual User* demote(User* user,std::string type){throw Exp("this user can not deomote");}
	virtual void user_list(std::vector<User*> users){
		throw Exp("this user does not have access to user list");}
	virtual void validate_storage(){throw Exp("storage stat access denied");} 
protected:
	std::string _user_name;
	std::string _pass;
	friend class Group;
	friend class Drive;
	friend class Element;
	friend std::ostream& operator<<(std::ostream& out ,  std::vector<User*> users);
};
std::ostream& operator<<(std::ostream& out ,  std::vector<User*> users);
#endif