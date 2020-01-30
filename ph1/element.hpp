#ifndef ELEMENT_HEADER_GUARD
#define ELEMENT_HEADER_GUARD
#include <iostream>
#include <vector>
#include "group.hpp"
#include "user.hpp"
#define SLASH "/"
#define SPACE " "
#define COMMA ","
#define READ_print "read,-"
#define WRITE_print "-,write"
#define READ_WRITE_print "read,write"
#define NONE_print "-,-"

enum Permission
{
	Read,
	Write,
	RW,
	None
};
class Element
{
public:
	Element(std::string name, std::string conteiner_path, User* creator , Group* group_named_by_creator);
	virtual ~Element()=0;
	void set_owners(Group* Group , Permission permission);
	virtual Permission get_permission(User* a_user);
	virtual void change_owner(std::string user_name,std::string current_user);
	virtual void change_group(Group* group,std::string current_user);
	virtual void chmod(std::string groupORuser,std::string action,Permission permission,User* current_user);
protected:
	std::string _path;
	std::string _name;
	std::string _creator;
	Permission _creator_permission=RW; 
	std::pair<Group* , Permission> _owners;
	std::vector<std::pair<Group*, Permission> > _shared;
	friend class User;
	friend class Drive;

};
Permission str_to_permission(std::string str);
Permission operator+(Permission a, Permission b);
Permission operator-(const Permission a,const Permission b);
std::ostream& operator<<(std::ostream& out , Permission permission);

#endif