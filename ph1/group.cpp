#include "group.hpp"
Group::Group(std::string name,User* creator):_name(name)
{
	_users.push_back(creator->_user_name);
}
void Group::membership_check(User* current_user)
{
	int member_index=search_users(current_user->_user_name);
	if(member_index == MEMBER_NOT_FOUND)
		throw Exp("user "+current_user->_user_name+" is not a member of group "+_name);
}
void Group::non_member_check(User* current_user)
{
	int member_index=search_users(current_user->_user_name);
	if(member_index != MEMBER_NOT_FOUND)
		throw Exp("user "+current_user->_user_name+" is already a member of group "+_name);
}
void Group::add_user(User* current_user,User* new_user)
{	
	membership_check(current_user);
	non_member_check(new_user);
	_users.push_back(new_user->_user_name);
}
int Group::search_users(std::string user_name)
{
	for (int i = 0; i < _users.size(); ++i)
	{
		if(_users[i]== user_name)
			return i;
	}
	return _users.size();
}
bool Group::is_member(User* a_user)
{
	return  (search_users(a_user->_user_name)!= MEMBER_NOT_FOUND);
}
