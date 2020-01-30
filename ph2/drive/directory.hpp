	#ifndef DIRECTORY_HEADER_GUARD
#define DIRECTORY_HEADER_GUARD
#include "element.hpp"
#include "file.hpp"
#define SUB_DIRECTORY_NOT_FOUND _sub_directories.size()
#define FILE_NOT_FOUND _files.size()
class Directory : public Element
{
public:
	Directory(std::string name, std::string conteiner_path, User* creator, Group* group_named_by_creator)
	:Element(name,conteiner_path,creator,group_named_by_creator){}
	~Directory();
	int search_sub_directories(std::string name);
	void check_sub_directory_not_exist(std::string name);
	int search_files(std::string file_name);
	int check_file_exist(std::string file_name);
	void check_file_not_exist(std::string file_name);
	void add_new_sub_directory(
		std::string name, User* creator, Group* group_named_by_creator);
	void elem_info_file(std::string file_name);
	void elem_info_r();
	void delete_file(std::string file_name , Permission upper_permission, User* current_user);
	void delete_sub_dir(std::string sub_dir , Permission upper_permission, User* current_user);
	int check_sub_directory_exist(std::string name);
	Directory* make_nested_directories(std::vector<std::string> rest_of_directoires
	,User* creator, Group* group_named_by_creator,Permission upper_permission);
	void upload(std::string real_file_name ,std::string vir_file_name
	,std::string main_path,User* creator , Group* owners);
	void download(std::string file_name ,std::string down_name 
		,Permission upper_permission,User* current_user,std::string main_path);
	void file_size(std::string file_name,Permission upper_permission,User* current_user);
	void copy(File* source_ptr,std::string des_name,User* creator , 
		Group* owners,Permission upper_permission);
	File* get_file_ptr(std::string source_name);
	void change_file_owner(std::string file_name,std::string user_name,std::string current_user);
	void change_file_group(std::string file_name,Group* group,std::string current_user);
	int calculate_total_used_storage();
	void chmod_file(std::string file_name,std::string groupORuser,std::string action,
			Permission permission,User* user);
protected:
	std::vector<File*> _files;
	std::vector<Directory*> _sub_directories;
	friend class Drive;	
	friend std::ostream& operator<<(std::ostream& out , Directory* directory);
};
Directory* plus_directorie(Directory* a, Directory* b);
std::pair<Directory* ,Permission>
plus_directory_permissions(std::pair<Directory* ,Permission> a,std::pair<Directory* ,Permission> b);
std::pair<Directory* ,Permission>&
plus_equal(std::pair<Directory* ,Permission>& a,std::pair<Directory* ,Permission> b);
std::ostream& operator<<(std::ostream& out , Directory* directory);
#endif