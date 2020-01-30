#include "utilities.hpp"
using namespace std;
void command_split(string command_line , vector<string> &command_splited)
{
	string delimiter=" ";
	size_t pos = 0;
	string token;

	while ((pos = command_line.find(delimiter)) != std::string::npos) {
	    token = command_line.substr(0, pos);
	    command_splited.push_back(token);
	    command_line.erase(0, pos + delimiter.length());
	}
	command_splited.push_back(command_line);
}
void get_command(string command_line , vector<string> &command_splited)
{
	command_splited.clear();
	command_split(command_line , command_splited);
}
void execute_command(vector<string> &command_splited ,Drive &drive)
{
	     if(command_splited[0] ==  ADD_USER)              drive.add_user(command_splited);	
	else if(command_splited[0] ==  LOGIN)                 drive.login(command_splited);
	else if(command_splited[0] ==  LOGOUT)                drive.logout(command_splited); 
 	else if(command_splited[0] ==  ADD_GROUP)             drive.add_group(command_splited);
	else if(command_splited[0] ==  ADD_TO_GROUP)          drive.add_to_group(command_splited);
	else if(command_splited[0] ==  UPLOAD)                drive.upload(command_splited);
	else if(command_splited[0] ==  DOWNLOAD)              drive.download(command_splited);
	else if(command_splited[0] ==  MAKE_DIRECTORY)        drive.make_directory(command_splited);
	else if(command_splited[0] ==  COPY)                  drive.copy(command_splited);
	else if(command_splited[0] ==  MOVE)                  drive.move(command_splited);
	else if(command_splited[0] ==  REMOVE)                drive.remove(command_splited);
	else if(command_splited[0] ==  PRINT_DIRECTORY)       drive.print_directory(command_splited);
	else if(command_splited[0] ==  CHANGE_DIRECTORY)      drive.change_directory(command_splited);
	else if(command_splited[0] ==  ELEM_INFO)             drive.elem_info(command_splited);
	else if(command_splited[0] ==  FILE_SIZE)             drive.file_size(command_splited);
	else if(command_splited[0] ==  CHANGE_MODE)           drive.chmod(command_splited);//!change
	else if(command_splited[0] ==  CHANGE_OWNER)          drive.change_owner(command_splited);
	else if(command_splited[0] ==  CHANGE_GROUP)          drive.change_group(command_splited);
	else if(command_splited[0] ==  PROMOTE)               drive.promote(command_splited);
	else if(command_splited[0] ==  DEMOTE)                drive.demote(command_splited);
	else if(command_splited[0] ==  USERLIST)              drive.user_list(command_splited);
	else if(command_splited[0] ==  STORAGE)               drive.storage(command_splited);
	else
	{
		throw Exp("invalid command :"+command_splited[0]);
	}
}
void check_if_path_is_given(int argc)
{
	if(argc<2)
		throw std::exception();
}
string unify_main_path(const char* argv[] , int argc)
{
	string cat="";
	for (int i = 1; i < argc-1; ++i)
	{
		string temp(argv[i]);
		cat+=temp;
		cat+=" ";
	}
	string temp(argv[argc-1]);
	cat+=temp;
	return cat;
}