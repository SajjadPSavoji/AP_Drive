#include "user.hpp"
using namespace std;
User::~User(){}
std::ostream& operator<<(std::ostream& out ,  std::vector<User*> users)
{
	for (int i = 0; i < users.size(); ++i)
	{
		out<<i+1<<"."<<users[i]->_user_name<<endl;
	}
}
