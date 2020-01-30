#ifndef UTILITIES_HEADER_GUARD
#define UTILITIES_HEADER_GUARD 
#include "drive.hpp"

#define ADD_USER "add_user"
#define LOGIN "login"
#define LOGOUT "logout"
#define ADD_GROUP "add_group"
#define ADD_TO_GROUP "add_to_group"
#define UPLOAD "upload"
#define DOWNLOAD "download"
#define MAKE_DIRECTORY "make_directory"
#define COPY "copy"
#define MOVE "move"
#define REMOVE "remove"
#define PRINT_DIRECTORY "print_directory"
#define CHANGE_DIRECTORY "change_directory"
#define ELEM_INFO "elem_info"
#define FILE_SIZE "file_size"
#define CHANGE_MODE "change_mode"
#define CHANGE_OWNER "change_owner"
#define CHANGE_GROUP "change_group"
#define PROMOTE "promote"
#define DEMOTE "demote"
#define USERLIST "userlist"
#define STORAGE "storage"

#define DRIVE_NAME "savoji cloud"
#define DRIVE_PATH argv[1]
void command_split(std::string command_line , std::vector<std::string> &command_splited);
void get_command(std::string command_line , std::vector<std::string> &command_splited);
void execute_command(std::vector<std::string> &command_splited ,Drive &drive);
void check_if_path_is_given(int argc);
std::string unify_main_path(const char* argv[], int argc);
#endif