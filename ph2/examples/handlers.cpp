#include "handlers.hpp"

using namespace std;

Response *RandomNumberHandler::callback(Request *req) {
  Response *res = new Response;
  res->setHeader("Content-Type", "text/html");
  string body;
  body += "<!DOCTYPE html>";
  body += "<html>";
  body += "<body style=\"text-align: center;\">";
  body += "<h1>AP HTTP</h1>";
  body += "<p>";
  body += "a random number in [1, 10] is: ";
  body += to_string(rand() % 10 + 1);
  body += "</p>";
  body += "<p>";
  body += "SeddionId: ";
  body += req->getSessionId();
  body += "</p>";
  body += "</body>";
  body += "</html>";
  res->setBody(body);
  return res;
}

Response *LoginPostHandler::callback(Request *req) {
  string username = req->getBodyParam("username");
  string password = req->getBodyParam("password");
  vector<string> command_splited;
  Response *res;
  make_login_command(username, password , command_splited);
  cout << "username: " << username << ",\tpassword: " << password << endl;
  try
	{
		execute_command(command_splited , *drive);
	}catch(Exp e)
	{
		cerr<<e<<endl;
    res = Response::redirect("/login");
    return res;
	}
  make_userlist_command(command_splited);
  try
  {
    execute_command(command_splited , *drive);
    res = Response::redirect("/manage");
  }catch(Exp e)
  {
    cerr<<e<<endl;
    res = Response::redirect("/userpage");
  }
  string SID=server->session_gen();
  res->setSessionId(SID);
  server->add_session_id(username , password , SID);
  make_logout_command(command_splited);
  try
	{
		execute_command(command_splited , *drive);
	}catch(Exp e)
	{
		cerr<<e<<endl;
	}
  return res;
}
Response *LoginGetHandler::callback(Request *req) {
  string SID = req->getSessionId();
  RequestHandler* handler;
  if(server->is_session_valid(SID))
  {
    Response *res = Response::redirect("/userpage");
    return res;
  }
  // if (username == "root")
  //   throw Server::Exception("Remote root access has been disabled.");
  Response *res=new Response;
  res->setHeader("Content-Type", "text/html");
  string body= readFile("static/logincss.html");
  res->setBody(body);
  return res;
}
Response *AddUserHandler::callback(Request *req) {
  string SID = req->getSessionId();
  RequestHandler* handler;
  if(! server->is_session_valid(SID))
  {
    Response *res = Response::redirect("/login");
    return res;
  }
  server->login_with_session_id(SID ,drive);
  string username = req->getBodyParam("username");
  string password = req->getBodyParam("password");
  vector<string> command_splited;
  make_adduser_command(command_splited,username,password);
  Response *res;
  try
	{
		execute_command(command_splited , *drive);
    res=Response::redirect("/userlist");
	}catch(Exp e)
	{
		cerr<<e<<endl;
    res = Response::redirect("/adduser");
	}
  make_logout_command(command_splited);
  try
	{
		execute_command(command_splited , *drive);
	}catch(Exp e)
	{
		cerr<<e<<endl;
	}
  return res;
}
Response *LogoutHandler::callback(Request *req) {
  string SID = req->getSessionId();
  server->expire_session_id(SID);
  RequestHandler* handler;
  Response *res = Response::redirect("/");
  std::vector<string> command_splited;
  make_logout_command(command_splited);
  try
	{
		execute_command(command_splited , *drive);
	}catch(Exp e)
	{
		cerr<<e<<endl;
	}
  return res;

}
Response *UploadHandler::callback(Request *req) {
  string name = req->getBodyParam("file_name");
  string file = req->getBodyParam("file");
  cout << name << " (" << file.size() << "B):\n" << file << endl;
  Response *res = Response::redirect("/");
  return res;
}
Response *UserListHandler::callback(Request *req) {
  string SID = req->getSessionId();
  RequestHandler* handler;
  if(! server->is_session_valid(SID))
  {
    Response *res = Response::redirect("/login");
    return res;
  }
  server->login_with_session_id(SID ,drive);
  Response *res = new Response;
  string body;
  string body_begin;
  string body_end;
  string body_between;
  res->setHeader("Content-Type", "text/html");
  body=readFile("static/userlist.html");
  size_t pos=0;
  pos=body.find(CONTENT_REPLACE);
  body_begin = body.substr(0, pos);
  body.erase(0, pos + CONTENT_REPLACE_SIZE);
  body_end=body;
  std::vector<string> users_listed;
  drive->user_list_back(users_listed);
  for (size_t i = 0; i < users_listed.size(); i++) {
    string a_user=readFile("static/eachuser.html");
    replaceAll(a_user,USERNAME_REPLACE,users_listed[i]);
    body_between+=a_user;
  }
  res->setBody(body_begin+body_between+body_end);
  std::vector<string> command_splited;
  make_logout_command(command_splited);
  try
	{
		execute_command(command_splited , *drive);
	}catch(Exp e)
	{
		cerr<<e<<endl;
	}
  return res;

}


Response *ElementListHandler::callback(Request *req) {
  string SID = req->getSessionId();
  RequestHandler* handler;
  if(! server->is_session_valid(SID))
  {
    Response *res = Response::redirect("/login");
    return res;
  }
  server->login_with_session_id(SID ,drive);
  Response *res = new Response;
  string body;
  string body_begin;
  string body_end;
  string body_between;
  res->setHeader("Content-Type", "text/html");
  body=readFile("static/fileslist.html");
  size_t pos=0;
  pos=body.find(CONTENT_REPLACE);
  body_begin = body.substr(0, pos);
  body.erase(0, pos + CONTENT_REPLACE_SIZE);
  body_end=body;
  std::vector<string> files_listed;
  std::vector<string> directory_listed;
  drive->files_list_back(files_listed ,directory_listed);
  for (size_t i = 0; i < directory_listed.size(); i++) {
    string a_directory=readFile("static/eachdirectory.html");
    replaceAll(a_directory,DIRECTORYNAME,directory_listed[i]);
    body_between+=a_directory;
  }
  for (size_t i = 0; i < files_listed.size(); i++) {
    string a_file=readFile("static/eachfile.html");
    replaceAll(a_file,FILENAME,files_listed[i]);
    body_between+=a_file;
  }
  body_between+=readFile("static/newdir.html");
  res->setBody(body_begin+body_between+body_end);
  std::vector<string> command_splited;
  make_logout_command(command_splited);
  try
	{
		execute_command(command_splited , *drive);
	}catch(Exp e)
	{
		cerr<<e<<endl;
	}
  return res;
}


Response *AddDirectoryHandler::callback(Request *req) {
  string SID = req->getSessionId();
  RequestHandler* handler;
  if(! server->is_session_valid(SID))
  {
    Response *res = Response::redirect("/login");
    return res;
  }
  server->login_with_session_id(SID ,drive);
  string new_dir = req->getBodyParam("newdirectory");
  std::vector<string> command_splited;
  make_mk_dir_command(command_splited,new_dir);
  try
	{
		execute_command(command_splited , *drive);
	}catch(Exp e)
	{
		cerr<<e<<endl;
	}
  Response *res = Response::redirect("/userpage");;

  make_logout_command(command_splited);
  try
	{
		execute_command(command_splited , *drive);
	}catch(Exp e)
	{
		cerr<<e<<endl;
	}
  return res;
}
