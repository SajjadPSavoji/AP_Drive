#ifndef NORMAL_USER_HEADER_GUARD
#define NORMAL_USER_HEADER_GUARD

#include "user.hpp"

class Normal : public User
{
public:
	Normal(std::string name ,std::string pass):User(name,pass){}
	void validate_promote_type(std::string type);
	void validate_demote_type(std::string type);
	~Normal(){}
	
};
#endif