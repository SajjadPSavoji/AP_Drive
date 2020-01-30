#ifndef DRIVE_HEADER_GUARD
#define DRIVE_HEADER_GUARD
#include <algorithm>

#include "group.hpp"
#include "directory.hpp"
#include "exception.hpp"

#define ROOT "root"
#define ROOT_DIRECTORY ""
#define ROOT_PATH "/"
#define BYTES " Bytes"

#define LOGIN_LEN 3
#define LOGOUT_LEN 1
#define ADD_USER_LEN 3
#define ADD_GROUP_LEN 2
#define ADD_TO_GROUP_LEN 3
#define UPLOAD_LEN 3
#define CHANGE_DIRECTORY_LEN 2
#define PIRNT_DIRECTORY_LEN 1
#define MAKE_DIRECTORY_LEN 2
#define ELEM_INFO_LEN_MAX 2
#define REMOVE_LEN 2
#define DOWN_LEN 3
#define COPY_LEN 3
#define MOVE_LEN 3
#define FILE_SIZE_LEN 2
#define CHANGE_OWNER_LEN 3
#define USER_LIST_LEN 1
#define CHMOD_LEN 5

#define USER_NOT_FOUND _users.size()
#define GROUP_NOT_FOUND _groups.size()
class Drive
{
public:
	Drive(std::string name , std::string main_path);
	~Drive(){}
	void doo(std::vector<std::string> command_splited){}
	void login(std::vector<std::string> command_splited);
	void go_to_current_user_directory();
	int search_users(std::string user_name);
	void check_pass(User* user,std::string pass);
	int check_user_exist(std::string user_name);
	void change_current_user(User* user);
	void check_some_user_loged_in();
	void check_no_user_loged_in();
	void logout(std::vector<std::string> command_splited);
	void add_user(std::vector<std::string> command_splited);
	void check_user_not_exist(std::string user_name);
	void check_directory_of_user_not_exist(std::string user_name);
	void make_new_user(std::string user_name , std::string pass);
	User* make_similar_user(User* user,std::string type);
	void add_group(std::vector<std::string> command_splited);
	int search_groups(std::string group_name);
	void check_group_not_exist(std::string group_name);
	int check_group_exist(std::string group_name);
	void make_new_group(std::string group_name);
	void add_to_group(std::vector<std::string> command_splited);
	std::pair<Directory*,Permission> find_furthest_valid_directory(
	std::vector<std::string> path_splited ,
	std::vector<std::string> &rest_of_directories);
	void upload(std::vector<std::string> command_splited);
	void change_directory(std::vector<std::string> command_splited);
	Directory* set_base_directory(std::vector<std::string> &path_splited);
	std::pair<Directory* , Permission> 
	search_directories_and_calculate_permission(
		std::vector<std::string>left_path_splited,Directory* current_base);
	void print_directory(std::vector<std::string> command_splited);
	void make_directory(std::vector<std::string> command_splited);
	void elem_info(std::vector<std::string> command_splited);
	void remove(std::vector<std::string> command_splited);
	void download(std::vector<std::string> command_splited);
	void file_size(std::vector<std::string> command_splited);
	void copy(std::vector<std::string> command_splited);
	void move(std::vector<std::string> command_splited);
	void make_path_splited_formal(std::vector<std::string> &path_splited);
	std::pair<Directory* ,Permission> get_directory_and_permission(
		std::vector<std::string>path_splited);
	void change_owner(std::vector<std::string> command_splited);
	void change_group(std::vector<std::string> command_splited);
	void promote(std::vector<std::string> command_splited);
	void demote(std::vector<std::string> command_splited);
	void user_list(std::vector<std::string> command_splited);
	void storage(std::vector<std::string> command_splited);
	void chmod(std::vector<std::string> command_splited);

protected:
	std::string _name;
	Super* _root=NULL;
	std::string _main_path;
	Directory* _root_directory=NULL;
	std::vector<User*> _users;
	std::vector<Group*> _groups;
	User* _current_user=NULL; 
	Directory* _current_directory=NULL;

};
#endif