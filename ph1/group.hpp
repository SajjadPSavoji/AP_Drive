#ifndef GROUP_HEADER_GUARD
#define GROUP_HEADER_GUARD
#include "normal_user.hpp"
#include "super_user.hpp"
#include "admin_user.hpp"
#include "exception.hpp"
#define MEMBER_NOT_FOUND _users.size()

class Group
{
public:
	Group(std::string name,User* creator);
	void add_user(User* current_user,User* new_user);
	int search_users(std::string user_name);
	void membership_check(User* current_user);
	void non_member_check(User* current_user);
	bool is_member(User* a_user);
	std::string get_name(){return _name;}
protected:
	std::string _name;
	std::vector<std::string> _users;
	friend class Drive;
	friend class Directory;
};
#endif