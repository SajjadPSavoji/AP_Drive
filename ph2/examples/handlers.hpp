
#include "../examples/my_server.hpp"
#include "../drive/utilities.hpp"
#include <cstdlib> // for rand and srand
#include <ctime>   // for time
#include <iostream>
#define CONTENT_REPLACE "CONTENT_REPLACE"
#define CONTENT_REPLACE_SIZE 15
#define USERNAME_REPLACE "USERNAME_REPLACE"
#define DIRECTORYNAME "DIRECTORYNAME"
#define DIRECTORYNAME_SIZE 13
#define FILENAME "FILENAME"
class RandomNumberHandler : public RequestHandler {
public:
  Response *callback(Request *);
};

class LoginPostHandler : public RequestHandler {
public:
  LoginPostHandler(MyServer* a_server , Drive * a_drive):server(a_server),drive(a_drive){}
  Response *callback(Request*);
private:
  MyServer* server;
  Drive* drive;
};
class LogoutHandler : public RequestHandler {
public:
  LogoutHandler(MyServer* a_server , Drive * a_drive):server(a_server),drive(a_drive){}
  Response *callback(Request*);
private:
  MyServer* server;
  Drive* drive;
};


class UploadHandler : public RequestHandler {
public:
  Response *callback(Request *);
};
class LoginGetHandler:public RequestHandler{
public:
  LoginGetHandler(MyServer* a_server , Drive* a_drive):server(a_server),drive(a_drive){}
  Response *callback(Request*);
private:
  MyServer* server;
  Drive* drive;
};
class AddUserHandler:public RequestHandler{
public:
  AddUserHandler(MyServer* a_server , Drive* a_drive):server(a_server),drive(a_drive){}
  Response *callback(Request*);
private:
  MyServer* server;
  Drive* drive;
};
class UserListHandler:public RequestHandler{
public:
  UserListHandler(MyServer* a_server , Drive* a_drive):server(a_server),drive(a_drive){}
  Response *callback(Request*);
private:
  MyServer* server;
  Drive* drive;
};
class ElementListHandler:public RequestHandler{
public:
  ElementListHandler(MyServer* a_server , Drive* a_drive):server(a_server),drive(a_drive){}
  Response *callback(Request*);
private:
  MyServer* server;
  Drive* drive;
};
class AddDirectoryHandler:public RequestHandler{
public:
  AddDirectoryHandler(MyServer* a_server , Drive* a_drive):server(a_server),drive(a_drive){}
  Response *callback(Request*);
private:
  MyServer* server;
  Drive* drive;
};
