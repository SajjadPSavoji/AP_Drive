#include "directory.hpp"
using namespace std;
Directory* plus_directories(Directory* a, Directory* b)
{
	if(a==NULL)
		return b;
	else if(b==NULL)
		return a;
	else
		throw Exp("at least one directory pointer must be NULL");
}
Directory::~Directory()
{
	for (int i = 0; i < _sub_directories.size(); ++i)
	{
		delete _sub_directories[i];
	}
	for (int i = 0; i < _files.size(); ++i)
	{
		delete _files[i];
	}
}
std::pair<Directory* ,Permission>
plus_directory_permissions(std::pair<Directory* ,Permission> a,std::pair<Directory* ,Permission> b)
{
	return pair<Directory* ,Permission>(plus_directories(a.first,b.first), a.second+b.second);
}
std::pair<Directory* ,Permission>&
plus_equal(std::pair<Directory* ,Permission>& a,std::pair<Directory* ,Permission> b)
{
	(a=plus_directory_permissions(a,b));
	return a; 
}
int Directory::search_sub_directories(std::string name)
{
	for (int i = 0; i < _sub_directories.size(); ++i)
	{
		if(_sub_directories[i]->_name == name)
			return i;
	}
	return _sub_directories.size();
}
void Directory::check_sub_directory_not_exist(std::string name)
{
	int	sub_index=search_sub_directories(name);
	if(sub_index != SUB_DIRECTORY_NOT_FOUND)
		throw Exp("directory "+_sub_directories[sub_index]->_name+" already exists");

}
int Directory::check_sub_directory_exist(std::string name)
{
	int sub_index=search_sub_directories(name);
	if(sub_index == SUB_DIRECTORY_NOT_FOUND)
		throw Exp("directory "+name+" not found");
	return sub_index;
}
int Directory::search_files(std::string file_name)
{
	for (int i = 0; i < _files.size(); ++i)
	{
		if(_files[i]->_name == file_name)
			return i;
	}
	return _files.size();
}
int Directory::check_file_exist(std::string file_name)
{
	int file_index=search_files(file_name);
	if(file_index == FILE_NOT_FOUND)
		throw Exp("file "+file_name+" not found");
	return file_index;
}
void Directory::check_file_not_exist(std::string file_name)
{
	int file_index=search_files(file_name);
	if(file_index != FILE_NOT_FOUND)
		throw Exp("file "+file_name+"already exists");
}
void Directory::add_new_sub_directory(
		std::string name, User* creator, Group* group_named_by_creator)
{
	Directory::check_sub_directory_not_exist(name);
	Directory* new_dir= new Directory(name , _path, creator ,group_named_by_creator);
	_sub_directories.push_back(new_dir);
}
std::ostream& operator<<(std::ostream& out , Directory* directory)
{
	cout<<"dir"<<SPACE;
	cout<<directory->_creator_permission<<SPACE;
	cout<<directory->_owners.second<<SPACE;
	cout<<directory->_creator<<SPACE;
	cout<<directory->_owners.first->get_name()<<SPACE;
	cout<<directory->_path;
}
void Directory::elem_info_file(std::string file_name)
{
	int file_index=check_file_exist(file_name);
	cout<<_files[file_index]<<endl;
}
void Directory::elem_info_r()
{
	for (int i = 0; i < _sub_directories.size(); ++i)
	{
		cout<<_sub_directories[i]<<endl;
	}
	for (int i = 0; i < _files.size(); ++i)
	{
		cout<<_files[i]<<endl;
	}
}
void allowed_write_access_dir(Permission permission)
{
	if(permission == None || permission == Read)
		throw Exp("Access Denied:you can not write in this directory");
}
void allowed_read_access_dir(Permission permission)
{
	if(permission == None || permission == Write)
		throw Exp("Access Denied:you dont have write access");
}
void Directory::delete_file(std::string file_name , Permission upper_permission, User* current_user){
	int file_index=check_file_exist(file_name);
	allowed_write_access_dir(upper_permission + _files[file_index]->get_permission(current_user));
	delete _files[file_index];
	_files.erase(_files.begin()+file_index);
}
void Directory::delete_sub_dir(std::string sub_dir , Permission upper_permission, User* current_user){
	int dir_index=check_sub_directory_exist(sub_dir);
	allowed_write_access_dir(upper_permission + _sub_directories[dir_index]->get_permission(current_user));
	delete _sub_directories[dir_index];
	_sub_directories.erase(_sub_directories.begin()+dir_index);
}
Directory* Directory::make_nested_directories(std::vector<std::string> rest_of_directoires
	, User* creator, Group* group_named_by_creator,Permission upper_permission)
{
	if(rest_of_directoires.size() == 0)
		return this;
	allowed_write_access_dir(this->get_permission(creator)+upper_permission);
	add_new_sub_directory(rest_of_directoires[0],creator,group_named_by_creator);
	rest_of_directoires.erase(rest_of_directoires.begin());
	Directory* new_head=_sub_directories.back();
	return 
		(new_head->make_nested_directories(rest_of_directoires,creator,group_named_by_creator,RW));
}
void Directory::upload(std::string real_file_name ,std::string vir_file_name
	, std::string main_path,User* creator , Group* owners)
{
	check_file_not_exist(vir_file_name);
	string content_path =main_path+"/"+real_file_name;
	File* new_file=NULL;
	try{
		new_file = new File(vir_file_name,_path,creator,owners,content_path);
	}catch(Exp e){
		throw Exp("can not upload file");
	}
	_files.push_back(new_file);
}
void Directory::download(string file_name ,string down_name,Permission upper_permission,User* current_user ,string main_path)
{
	int file_index=check_file_exist(file_name);
	allowed_read_access_dir(_files[file_index]->get_permission(current_user)+upper_permission);
	_files[file_index]->write_file(main_path+"/"+down_name);
}
void Directory::file_size(std::string file_name,Permission upper_permission,User* current_user)
{
	int file_index=check_file_exist(file_name);
	allowed_read_access_dir(upper_permission+_files[file_index]->get_permission(current_user));
	_files[file_index]->announce_file_size();
}
void Directory::copy(File* source_ptr,std::string des_name,User* creator 
	,Group* owners,Permission upper_permission)
{
	int file_index=search_files(des_name);
	if(file_index == FILE_NOT_FOUND)
	{
		allowed_write_access_dir(upper_permission);
		File* new_file = new File(des_name,_path,creator,owners,*(source_ptr));
		_files.push_back(new_file);
	}
	else
	{
		allowed_write_access_dir(upper_permission+_files[file_index]->get_permission(creator));
		*(_files[file_index])=*(source_ptr);
	}
}
File* Directory::get_file_ptr(std::string source_name)
{
	int file_index=check_file_exist(source_name);
	return _files[file_index];
}
void Directory::change_file_owner(std::string file_name,std::string user_name,std::string current_user)
{
	int file_index=check_file_exist(file_name);
	_files[file_index]->change_owner(user_name,current_user);
}
void Directory::change_file_group(std::string file_name,Group* group,std::string current_user)
{
	int file_index=check_file_exist(file_name);
	_files[file_index]->change_group(group,current_user);
}
int Directory::calculate_total_used_storage()
{
	int node_sum=0;
	for (int i = 0; i < _files.size(); ++i)
	{
		node_sum+=_files[i]->_size;
	}
	for (int i = 0; i < _sub_directories.size(); ++i)
	{
		node_sum+=_sub_directories[i]->calculate_total_used_storage();
	}
	return node_sum;
}
void Directory::chmod_file(std::string file_name,std::string groupORuser,std::string action,
	Permission permission,User* user)
{
	int file_index=check_file_exist(file_name);
	_files[file_index]->chmod(groupORuser,action,permission,user);
}