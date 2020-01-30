#include "drive.hpp"
using namespace std;

void path_split(string path , vector<string> &path_splited)
{
	string delimiter="/";
	size_t pos = 0;
	string token;

	while ((pos = path.find(delimiter)) != std::string::npos) {
	    token = path.substr(0, pos);
	    path_splited.push_back(token);
	    path.erase(0, pos + delimiter.length());
	}
	if(!path.empty())	
		path_splited.push_back(path);

	if(path_splited.size() == 2 && path_splited.back() == "root")
		path_splited.erase(path_splited.end());
}
std::vector<std::string>
delete_first_element(std::vector<std::string> &left_path_splited)
{
	if(!left_path_splited.size())
		return left_path_splited;
	left_path_splited.erase(left_path_splited.begin());
	return left_path_splited;
}
bool is_file(string element_name)
{
	vector<string> split;
	string delimiter=".";
	size_t pos = 0;
	string token;
	while ((pos = element_name.find(delimiter)) != std::string::npos) {
	    token = element_name.substr(0, pos);
	    split.push_back(token);
	    element_name.erase(0, pos + delimiter.length());
	}
	split.push_back(element_name);
	return(split.size() == 2);	
}
void check_string_not_empty(std::string path)
{
	if(path == "")
		throw Exp("string can not be empty");
}
void check_not_file(string element_name)
{
	if(is_file(element_name))
		throw Exp("directory can not contain char '.'");
}
void check_be_file(string elem_name)
{
	if(!is_file(elem_name))
		throw Exp("must have char '.' to point at file");
}
void check_no_file_in_path(vector<string> path_splited)
{
	for (int i = 0; i < path_splited.size(); ++i)
	{
		check_not_file(path_splited[i]);
	}
}
void check_directory_found(Directory* directory,string path)
{
	if(directory == NULL)
		throw Exp("requested path: "+path+" was not found");
}
void check_directory_not_found(Directory* directory,string path)
{
	if(directory != NULL)
		throw Exp("requested path: "+path+" already exists");
}
void check_no_slash(std::string str)
{
	vector<string> split;
	path_split(str , split);
	if(split.size()!=1)
		throw Exp("argument can not contain char '/'");
}
void check_path_not_root(std::string path)
{
	if(path == "/")
		throw Exp("can not remove root");
}
void allowed_general_access(Permission permission)
{
	if(permission == None)
		throw Exp("Access Denied");
}
void allowed_write_access(Permission permission)
{
	if(permission == None || permission == Read)
		throw Exp("Access Denied:you can not write in this directory");
}
void allowed_read_access(Permission permission)
{
	if(permission == None || permission == Write)
		throw Exp("Access Denied:you can not read this directory");
}
void validate_logout_command_len(std::vector<std::string> command_splited)
{
	if(command_splited.size()!= LOGOUT_LEN)
		throw Exp("log out does not get any arguments");
}
void validate_login_command_len(std::vector<std::string> command_splited)
{
	if(command_splited.size() != LOGIN_LEN)
		throw Exp("login command gets exactly 2 arguments");
}
void validate_add_user_command_len(std::vector<std::string> command_splited)
{
	if(command_splited.size()!= ADD_USER_LEN)
		throw Exp("add user gets exactly 2 arguments");
}
void validate_add_group_len(std::vector<std::string> command_splited)
{
	if(command_splited.size()!= ADD_GROUP_LEN)
		throw Exp("add group gets exactly 1 argument");
}
void validate_add_to_group_len(std::vector<std::string> command_splited)
{
	if(command_splited.size()!= ADD_TO_GROUP_LEN)
		throw Exp("add_to_group gets exactly 2 argument");	
}
void validate_upload_len(std::vector<std::string> command_splited)
{
	if(command_splited.size()!= UPLOAD_LEN)
		throw Exp("upload gets exactly 2 argument");
}
void validate_change_dirctory_len(std::vector<std::string> command_splited)
{
	if(command_splited.size()!= CHANGE_DIRECTORY_LEN)
		throw Exp("change_directory gets exactly 2 argument");	
}
void validate_print_dirctory_len(std::vector<std::string> command_splited)
{
	if(command_splited.size()!= PIRNT_DIRECTORY_LEN)
		throw Exp("print_directory gets no argument");	
}
void validate_make_dirctory_len(std::vector<std::string> command_splited)
{
	if(command_splited.size()!= MAKE_DIRECTORY_LEN)
		throw Exp("make_directory gets 1 argument");	
}
void validate_elem_info_len(std::vector<std::string> command_splited)
{
	if(command_splited.size()> ELEM_INFO_LEN_MAX)
		throw Exp("make_directory gets at most 1 argument");	
}
void validate_remove_len(std::vector<std::string> command_splited)
{
	if(command_splited.size()!= REMOVE_LEN)
		throw Exp("remove gets only only 1 argument");	
}
void validate_download_len(std::vector<std::string> command_splited)
{
	if(command_splited.size()!= DOWN_LEN)
		throw Exp("download gets only 2 arguments");	
}
void validate_file_size_len(std::vector<std::string> command_splited)
{
	if(command_splited.size()!= FILE_SIZE_LEN)
		throw Exp("download gets only 1 argument");	
}
void validate_copy_len(std::vector<std::string> command_splited)
{
	if(command_splited.size()!= COPY_LEN)
		throw Exp("copy gets only 2 arguments");	
}
void validate_move_len(std::vector<std::string> command_splited)
{
	if(command_splited.size()!= MOVE_LEN)
		throw Exp("copy gets only 2 arguments");	
}
void validate_change_owner_len(std::vector<std::string> command_splited)
{
	if(command_splited.size()!= CHANGE_OWNER_LEN)
		throw Exp("copy gets only 2 arguments");	
}
void validate_user_list_len(std::vector<std::string> command_splited)
{
	if(command_splited.size()!= USER_LIST_LEN)
		throw Exp("copy gets no arguments");	
}
void validate_chmod_len(std::vector<std::string> command_splited)
{
	if(command_splited.size()!= CHMOD_LEN)
		throw Exp("change mode gets 4 arguments");	
}










Drive::Drive(std::string name , std::string main_path):_main_path(main_path), _name(name)
{
	_root=new Super(ROOT,ROOT);
	_users.push_back(_root);
	_groups.push_back(new Group(ROOT,_root));
	_root_directory=new Directory("","",_root,_groups[0]);
}
int Drive::search_users(std::string user_name)
{
	for (int i = 0; i < _users.size(); ++i)
	{
		if(_users[i]->_user_name == user_name)
			return i;
	}
	return _users.size();
}
int Drive::check_user_exist(std::string user_name)
{
	int user_index=search_users(user_name);
	if(user_index == USER_NOT_FOUND)
		throw Exp("user "+user_name+" not found");
	return user_index;
}
void Drive::check_user_not_exist(std::string user_name)
{
	int user_index=search_users(user_name);
	if(user_index != USER_NOT_FOUND)
		throw Exp("there is already a user by name "+user_name);
}
void Drive::check_pass(User* user,std::string pass)
{
	if(!user->is_pass(pass))
		throw Exp("wrong password");

}
void Drive::change_current_user(User* user)
{
	_current_user=user;
}
void Drive::go_to_current_user_directory()
{
	vector<string> command;
	command.push_back("change_directory");
	command.push_back("/"+_current_user->_user_name);
	change_directory(command);
}
void Drive::login(std::vector<std::string> command_splited)
{
	validate_login_command_len(command_splited);
	check_no_user_loged_in();
	check_string_not_empty(command_splited[1]);
	check_string_not_empty(command_splited[2]);
	int user_index=check_user_exist(command_splited[1]);
	check_pass(_users[user_index],command_splited[2]);
	change_current_user(_users[user_index]);
	go_to_current_user_directory();
}
void Drive::check_some_user_loged_in()
{
	if(_current_user == NULL)
		throw Exp("no user loged in");
}
void Drive::check_no_user_loged_in()
{
	if(_current_user != NULL)
		throw Exp("user "+_current_user->_user_name+" is loged in");
}
void Drive::logout(std::vector<std::string> command_splited)
{
	validate_logout_command_len(command_splited);
	check_some_user_loged_in();
	_current_user=NULL;
}
void Drive::check_directory_of_user_not_exist(std::string user_name)
{
	vector<string> new_user_dir_path;
	new_user_dir_path.push_back("");
	new_user_dir_path.push_back(user_name);
	string user_path=new_user_dir_path[0]+new_user_dir_path[1];
	check_directory_not_found(
		get_directory_and_permission(new_user_dir_path).first,user_path);
}
void Drive::make_new_user(std::string user_name , std::string pass)
{
	check_directory_of_user_not_exist(user_name);
	User* new_user=_current_user->make_new_user(user_name,pass);
	_users.push_back(new_user);
	_groups.push_back(new Group(user_name,new_user));
	_root_directory->_sub_directories.push_back(new Directory(user_name,ROOT_DIRECTORY,new_user,_groups.back()));
}
void Drive::add_user(std::vector<std::string> command_splited)
{
	validate_add_user_command_len(command_splited);
	check_some_user_loged_in();
	check_string_not_empty(command_splited[1]);
	check_string_not_empty(command_splited[2]);
	string user_name=command_splited[1];
	string pass=command_splited[2];
	check_user_not_exist(user_name);
	check_group_not_exist(user_name);
	make_new_user(user_name,pass);
}
int Drive::search_groups(std::string group_name)
{
	for (int i = 0; i < _groups.size(); ++i)
	{
		if(_groups[i]->_name == group_name)
			return i;
	}
	return _groups.size();
}
void Drive::check_group_not_exist(std::string group_name)
{
	int group_index=search_groups(group_name);
	if(group_index != GROUP_NOT_FOUND)
		throw Exp("there is already a group by name "+group_name);
}
int Drive::check_group_exist(std::string group_name)
{
	int group_index=search_groups(group_name);
	if(group_index == GROUP_NOT_FOUND)
		throw Exp("there is no group by name "+group_name);
	return group_index;
}
void Drive::make_new_group(std::string group_name)
{
	_groups.push_back(new Group(group_name,_current_user));
}
void Drive::add_group(std::vector<std::string> command_splited)
{
	validate_add_group_len(command_splited);
	string group_name=command_splited[1];
	check_some_user_loged_in();
	check_group_not_exist(group_name);
	make_new_group(group_name);
}
void Drive::add_to_group(std::vector<std::string> command_splited)
{
	validate_add_to_group_len(command_splited);
	check_string_not_empty(command_splited[1]);
	check_string_not_empty(command_splited[2]);
	string group_name=command_splited[1];
	string user_name=command_splited[2];
	check_some_user_loged_in();
	int group_index=check_group_exist(group_name);
	int user_index=check_user_exist(user_name);
	_groups[group_index]->add_user(_current_user,_users[user_index]);
}
Directory* Drive::set_base_directory(std::vector<std::string> &path_splited)
{
	Directory* base_directory;
	if(path_splited[0]==ROOT_DIRECTORY){
		base_directory = _root_directory;
		//delete_first_element(path_splited);
	}
	else
		base_directory= _current_directory;
	return base_directory;
}
void Drive::make_path_splited_formal
(std::vector<std::string> &path_splited)
{
	Directory* base_dir= set_base_directory(path_splited);
	if(base_dir == _root_directory && path_splited[0]==ROOT_DIRECTORY)
		return;
	std::vector<std::string> base_splited;
	path_split(base_dir->_path , base_splited);
	//delete_first_element(base_splited);
	for (int i = base_splited.size()-1; i>=0;i--)
	{
		path_splited.insert(path_splited.begin(),base_splited[i]);
	}
}
pair<Directory* ,Permission> 
Drive::get_directory_and_permission(std::vector<std::string>path_splited)
{
	make_path_splited_formal(path_splited);
	delete_first_element(path_splited);
	return search_directories_and_calculate_permission(path_splited,_root_directory);
}
pair<Directory* , Permission> 
Drive::search_directories_and_calculate_permission
(std::vector<std::string>left_path_splited,Directory* current_base)
{
	if(left_path_splited.size()==0)
	{
		return pair<Directory* , Permission> (current_base,current_base->get_permission(_current_user));
	}
	pair<Directory* , Permission> result(NULL,current_base->get_permission(_current_user));
	for (int i = 0; i < current_base->_sub_directories.size(); ++i)
	{
		if(current_base->_sub_directories[i]->_name == left_path_splited[0])
		{
			result=plus_equal(result,search_directories_and_calculate_permission
			(delete_first_element(left_path_splited),current_base->_sub_directories[i]));
			break;

		}
	}
	if(result.first == NULL)
		result.second = None;
	return result;
}
std::pair<Directory*,Permission> Drive::find_furthest_valid_directory(
	std::vector<std::string> path_splited ,
	std::vector<std::string> &rest_of_directories)
{
	pair<Directory* , Permission> result(NULL , None);
	while(result.first == NULL)
	{
		result=get_directory_and_permission(path_splited);
		if(path_splited.size() != 0 && result.first == NULL){
			rest_of_directories.push_back(path_splited.back());
			path_splited.pop_back();
		}
	}
	reverse(rest_of_directories.begin(),rest_of_directories.end());
	return pair<Directory* , Permission>(result.first,result.second);
}
void Drive::change_directory(std::vector<std::string> command_splited)
{
	validate_change_dirctory_len(command_splited);
	check_some_user_loged_in();
	string path = command_splited[1];
	check_string_not_empty(path);
	vector<string> path_splited;
	path_split(path,path_splited);
	check_no_file_in_path(path_splited);
	pair<Directory* , Permission> result=
	get_directory_and_permission(path_splited);
	check_directory_found(result.first,path);
	allowed_general_access(result.second);
	_current_directory=result.first;
}
void Drive::print_directory(std::vector<std::string> command_splited)
{
	validate_print_dirctory_len(command_splited);
	check_some_user_loged_in();
	cout<<_current_directory->_path<<endl;
}
void Drive::make_directory(std::vector<std::string> command_splited)
{
	validate_make_dirctory_len(command_splited);
	check_some_user_loged_in();
	string new_dir_name=command_splited[1];
	check_not_file(new_dir_name);
	check_no_slash(new_dir_name);
	string current_path = _current_directory->_path;
	vector<string> path_splited;
	path_split(current_path,path_splited);
	pair<Directory* , Permission> result=
	get_directory_and_permission(path_splited);
	allowed_write_access(result.second);
	Group* owner_group=_groups[search_groups(_current_user->_user_name)];
	_current_directory->add_new_sub_directory(
		new_dir_name,_current_user,owner_group);
}
void Drive::elem_info(std::vector<std::string> command_splited)
{
	validate_elem_info_len(command_splited);
	check_some_user_loged_in();
	if(command_splited.size() == 1)
	{
		_current_directory->elem_info_r();
	}
	else
	{
		string path=command_splited[1];
		check_string_not_empty(path);
		vector<string> path_splited;
		path_split(path,path_splited);
		make_path_splited_formal(path_splited);
		string file_name="";
		if(is_file(path_splited.back()))
		{
			file_name=path_splited.back();
			path_splited.erase(path_splited.end());
		}
		check_no_file_in_path(path_splited);
		pair<Directory* , Permission> result=
		get_directory_and_permission(path_splited);
		check_directory_found(result.first,path);
		allowed_general_access(result.second);
		if(!file_name.empty())
			result.first->elem_info_file(file_name);
		else
		{

			cout<<result.first<<endl;
		}
	}
}
void Drive::remove(std::vector<std::string> command_splited)
{
	validate_remove_len(command_splited);
	check_some_user_loged_in();
	string path=command_splited[1];
	check_string_not_empty(path);
	check_path_not_root(path);
	vector<string> path_splited;
	path_split(path,path_splited);
	make_path_splited_formal(path_splited);
	string file_name="";
	string sub_directory="";
	if(is_file(path_splited.back()))
	{
		file_name=path_splited.back();
		path_splited.erase(path_splited.end());
	}
	check_no_file_in_path(path_splited);
	if(file_name.empty())
	{
		sub_directory=path_splited.back();
		path_splited.erase(path_splited.end());
	}
	pair<Directory* , Permission> result=
	get_directory_and_permission(path_splited);
	check_directory_found(result.first,path);
	if(file_name.empty())
	{
		result.first->delete_sub_dir(sub_directory,result.second, _current_user);
	}
	else
	{
		result.first->delete_file(file_name,result.second, _current_user);
	}
}
void Drive::upload(std::vector<std::string> command_splited)
{
	validate_upload_len(command_splited);
	check_some_user_loged_in();
	string real_file_name = command_splited[1];
	string path = command_splited[2];
	check_string_not_empty(path);
	check_string_not_empty(real_file_name);
	vector<string> path_splited;
	path_split(path, path_splited);
	make_path_splited_formal(path_splited);
	string vir_file_name=path_splited.back();
	path_splited.pop_back();
	check_be_file(real_file_name);
	check_be_file(vir_file_name);
	check_no_file_in_path(path_splited);
	vector<string> rest_of_directories;
	Group* owner_group=_groups[search_groups(_current_user->_user_name)];
	pair<Directory* , Permission> result=find_furthest_valid_directory(
		path_splited,rest_of_directories);
	Directory* upper_dir = result.first;
	Directory* container=upper_dir->make_nested_directories(
		rest_of_directories,_current_user,owner_group,result.second);
	allowed_write_access(container->get_permission(_current_user));
	container->upload(real_file_name,vir_file_name,_main_path,
		_current_user,owner_group);
}
void Drive::download(std::vector<std::string> command_splited)
{
	validate_download_len(command_splited);
	check_some_user_loged_in();
	string path=command_splited[1];
	string down_name=command_splited[2];
	check_string_not_empty(path);
	check_string_not_empty(down_name);
	vector<string> path_splited;
	path_split(path, path_splited);
	make_path_splited_formal(path_splited);
	string file_name=path_splited.back();
	check_be_file(file_name);
	path_splited.pop_back();
	check_no_file_in_path(path_splited);
	pair<Directory* , Permission> result=
	get_directory_and_permission(path_splited);
	check_directory_found(result.first,path);
	result.first->download(file_name ,down_name,result.second,_current_user,_main_path);
}
void Drive::file_size(std::vector<std::string> command_splited)
{
	validate_file_size_len(command_splited);
	check_some_user_loged_in();
	string path=command_splited[1];
	check_string_not_empty(path);
	vector<string> path_splited;
	path_split(path, path_splited);
	make_path_splited_formal(path_splited);
	string file_name=path_splited.back();
	check_be_file(file_name);
	path_splited.pop_back();
	check_no_file_in_path(path_splited);
	pair<Directory* , Permission> result=
	get_directory_and_permission(path_splited);
	check_directory_found(result.first,path);
	result.first->file_size(file_name,result.second,_current_user);
}
void Drive::copy(std::vector<std::string> command_splited)
{
	validate_copy_len(command_splited);
	check_some_user_loged_in();
	string source=command_splited[1];
	string destination=command_splited[2];
	check_string_not_empty(source);
	check_string_not_empty(destination);
	vector<string> source_splited;
	path_split(source, source_splited);
	make_path_splited_formal(source_splited);
	string source_name=source_splited.back();
	check_be_file(source_name);
	source_splited.pop_back();
	check_no_file_in_path(source_splited);
	pair<Directory* , Permission> result=
	get_directory_and_permission(source_splited);
	check_directory_found(result.first,source);
	File* source_ptr=result.first->get_file_ptr(source_name);
	allowed_read_access(source_ptr->get_permission(_current_user)+result.second);
	vector<string> des_splited;
	path_split(destination, des_splited);
	make_path_splited_formal(des_splited);
	string des_name=des_splited.back();
	check_be_file(des_name);
	des_splited.pop_back();
	check_no_file_in_path(des_splited);
	vector<string> rest_of_directories;
	result=find_furthest_valid_directory(des_splited,rest_of_directories);
	Directory* upper_dir = result.first;
	Group* owner_group=_groups[search_groups(_current_user->_user_name)];
	Directory* container=upper_dir->make_nested_directories(rest_of_directories
		,_current_user,owner_group,result.second);
	container->copy(source_ptr,des_name,_current_user,owner_group,result.second);
}
void Drive::move(std::vector<std::string> command_splited)
{
	validate_move_len(command_splited);
	check_some_user_loged_in();
	string source_path=command_splited[1];
	string des_path=command_splited[2];
	check_string_not_empty(source_path);
	check_string_not_empty(des_path);
	vector<string> source_splited;
	path_split(source_path, source_splited);
	make_path_splited_formal(source_splited);
	string source_name=source_splited.back();
	check_be_file(source_name);
	source_splited.pop_back();
	check_no_file_in_path(source_splited);
	pair<Directory* , Permission> result=
	get_directory_and_permission(source_splited);
	check_directory_found(result.first,source_path);
	File* source_ptr=result.first->get_file_ptr(source_name);
	allowed_write_access(source_ptr->get_permission(_current_user)+result.second);
	vector<string> des_splited;
	path_split(des_path, des_splited);
	make_path_splited_formal(des_splited);
	string des_name=des_splited.back();
	if(is_file(des_name))
		des_splited.pop_back();
	else
		des_name=source_name;
	check_no_file_in_path(des_splited);
	vector<string> rest_of_directories;
	result=find_furthest_valid_directory(des_splited,rest_of_directories);
	Directory* upper_dir=result.first;
	Group* owner_group=_groups[search_groups(_current_user->_user_name)];
	Directory* container=upper_dir->make_nested_directories(rest_of_directories
		,_current_user,owner_group,result.second);
	container->copy(source_ptr,des_name,_current_user,owner_group,result.second);
	command_splited[0]="remove";
	command_splited.pop_back();
	remove(command_splited);
}
void Drive::change_owner(std::vector<std::string> command_splited)
{
	validate_change_owner_len(command_splited);
	check_some_user_loged_in();
	string user_name=command_splited[1];
	string path=command_splited[2];
	check_string_not_empty(path);
	check_string_not_empty(user_name);
	int user_index=check_user_exist(user_name);
	vector<string> path_splited;
	path_split(path,path_splited);
	make_path_splited_formal(path_splited);
	string file_name="";
	if(is_file(path_splited.back()))
	{
		file_name=path_splited.back();
		path_splited.erase(path_splited.end());
	}
	check_no_file_in_path(path_splited);
	pair<Directory* , Permission> result=
	get_directory_and_permission(path_splited);
	check_directory_found(result.first,path);
	if(file_name.empty())
	{
		result.first->change_owner(user_name,_current_user->_user_name);
	}
	else
	{
		result.first->change_file_owner(file_name,user_name,_current_user->_user_name);
	}
}
void Drive::change_group(std::vector<std::string> command_splited)
{
	validate_change_owner_len(command_splited);
	check_some_user_loged_in();
	string group_name=command_splited[1];
	string path=command_splited[2];
	check_string_not_empty(path);
	check_string_not_empty(group_name);
	int group_index=check_group_exist(group_name);
	vector<string> path_splited;
	path_split(path,path_splited);
	make_path_splited_formal(path_splited);
	string file_name="";
	if(is_file(path_splited.back()))
	{
		file_name=path_splited.back();
		path_splited.erase(path_splited.end());
	}
	check_no_file_in_path(path_splited);
	pair<Directory* , Permission> result=
	get_directory_and_permission(path_splited);
	check_directory_found(result.first,path);
	if(file_name.empty())
	{
		result.first->change_group(_groups[group_index],_current_user->_user_name);
	}
	else
	{
		result.first->change_file_group(file_name,_groups[group_index],_current_user->_user_name);
	}
}
User* Drive::make_similar_user(User* user ,std::string type)
{
		 if(type==NORMAL)   		return new Normal(user->_user_name , user->_pass); 
	else if(type == ADMIN) 			return new Admin (user->_user_name , user->_pass);
	else if(type == SUPER_USER)     return new Super (user->_user_name , user->_pass);
}
void Drive::promote(std::vector<std::string> command_splited)
{
	validate_change_owner_len(command_splited);
	check_some_user_loged_in();
	string user_name=command_splited[1];
	string type=command_splited[2];
	check_string_not_empty(type);
	check_string_not_empty(user_name);
	int user_index=check_user_exist(user_name);
	_current_user->promote(_users[user_index],type);
	User* promoted_user=make_similar_user(_users[user_index],type);
	delete _users[user_index];
	_users.erase(_users.begin()+user_index);
	_users.push_back(promoted_user);
}
void Drive::demote(std::vector<std::string> command_splited)
{
	validate_change_owner_len(command_splited);
	check_some_user_loged_in();
	string user_name=command_splited[1];
	string type=command_splited[2];
	check_string_not_empty(type);
	check_string_not_empty(user_name);
	int user_index=check_user_exist(user_name);
	_current_user->demote(_users[user_index],type);
	User* promoted_user=make_similar_user(_users[user_index],type);
	delete _users[user_index];
	_users.erase(_users.begin()+user_index);
	_users.push_back(promoted_user);
}
void Drive::user_list(std::vector<std::string> command_splited)
{
	validate_user_list_len(command_splited);
	check_some_user_loged_in();
	_current_user->user_list(_users);
}
void Drive::storage(std::vector<std::string> command_splited)
{
	validate_user_list_len(command_splited);
	check_some_user_loged_in();
	_current_user->validate_storage();
	cout<<_root_directory->calculate_total_used_storage()<<BYTES<<endl;
}
void Drive::chmod(std::vector<std::string> command_splited)
{
	validate_chmod_len(command_splited);
	check_some_user_loged_in();
	string groupORuser = command_splited[1];
	string action = command_splited[2];
	string type =command_splited[3];
	string path =command_splited[4];
	vector<string> path_splited;
	path_split(path, path_splited);
	make_path_splited_formal(path_splited);
	string file_name="";
	if(is_file(path_splited.back()))
	{
		file_name=path_splited.back();
		path_splited.erase(path_splited.end());
	}
	check_no_file_in_path(path_splited);
	pair<Directory* , Permission> result=
	get_directory_and_permission(path_splited);
	check_directory_found(result.first,path);
	if(file_name.empty())
	{
		result.first->chmod(groupORuser,action,str_to_permission(type),_current_user);
	}
	else
	{
		result.first->chmod_file(file_name,groupORuser,action,
			str_to_permission(type),_current_user);
	}
}

