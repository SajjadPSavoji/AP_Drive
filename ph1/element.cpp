#include "element.hpp"
using namespace std;
Element::~Element(){}
Element::Element(std::string name, std::string conteiner_path, User* creator , Group* group_named_by_creator)
:_name(name),_path(conteiner_path+SLASH+name),_creator(creator->_user_name)
{
	if(conteiner_path =="/")
		_path = conteiner_path+name;
	set_owners(group_named_by_creator,RW);
}
void Element::set_owners(Group* group , Permission permission)
{
	_owners=pair<Group*, Permission>(group , permission);
}
Permission operator+(const Permission a,const Permission b)
{
	if(a == None)
		return b;
	else if(b == None)
		return a;
	else if(a == RW || b == RW)
		return RW;
	else if(a == b)
		return a;
	else if(a == Read && b==Write || b == Read && a == Write)
		return RW;
	else 
		throw Exp("permission summation failed");
	
}
Permission operator-(const Permission a,const Permission b)
{
	if(a == None)
		return a;
	else if(b == None)
		return a;
	else if(a == RW && b == Write)
		return Read;
	else if(a == RW && b == Read)
		return Write;
	else if(a == b)
		return None;
	else if(b == RW)
		return None;
	else if(a==Read && b==Write)
		return a;
	else if(a==Write && b==Read)
		return a;
	else 
		throw Exp("permission summation failed");
	
}
Permission Element::get_permission(User* a_user)
{
	Permission permission=None;
	if(a_user->_user_name == _creator)
		return RW;
	if(_owners.first->is_member(a_user))
		permission=permission+_owners.second;
	for (int i = 0; i < _shared.size(); ++i)
	{
		if(_shared[i].first->is_member(a_user))
			permission=permission+_shared[i].second;
	}
	return permission;
}
std::ostream& operator<<(std::ostream& out , Permission permission)
{
	 	 if(permission == Read)      out<<READ_print;
	else if(permission == Write)     out<<WRITE_print;
	else if(permission == RW)        out<<READ_WRITE_print;
	else if(permission == None)      out<<NONE_print;
	return out;
}
void Element::change_owner(std::string user_name,std::string current_user)
{
	if(current_user != _creator)
		throw Exp("only "+_creator+" can change creator role");
	_creator=user_name;

}
void Element::change_group(Group* group,std::string current_user)
{
	
	if(current_user != _creator)
		throw Exp("only "+_creator+" can change owner group");
	_owners =pair <Group*,Permission>(group,_owners.second);
}
void Element::chmod(std::string groupORuser,std::string action,
	Permission permission,User* current_user)
{
	if(current_user->_user_name != _creator)
		throw Exp("only "+_creator+" can change mode");
	if(groupORuser =="group")
	{
		if(action == "+")
			_creator_permission =_creator_permission + permission;
		else if(action == "-")
			_owners.second = _owners.second-permission;
		else 
			throw Exp("invalid action "+action);

	}
	else if(groupORuser =="user")
	{
		if(action == "+")
			_creator_permission =_creator_permission + permission;
		else if(action == "-")
			_creator_permission = _creator_permission-permission;
		else 
			throw Exp("invalid action "+action);
	}
	else
		throw Exp("first argument must be 'group' or 'user'");

}
Permission str_to_permission(std::string str)
{
		 if (str == "write")  return Write;
	else if (str == "read")   return Read;
	else if (str == "rw")     return RW;
	else if (str == "none")   return None;
	else 
		throw Exp("invalid convetion form "+str+" to Permission");
}
