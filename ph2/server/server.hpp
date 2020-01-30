#ifndef __SERVER__
#define __SERVER__
#include "../drive/utilities.hpp"
#include "../utils/include.hpp"
#include "../utils/request.hpp"
#include "../utils/response.hpp"
#include "route.hpp"
#include <exception>
#include <string>
#include <vector>

#define SESSION_NOT_FOUND "session_not_found"

class Server;
class RequestHandler {
public:
  virtual ~RequestHandler();
  virtual Response *callback(Request *req) = 0;
};

class ShowFile : public RequestHandler {
  std::string filePath;
  std::string fileType;

public:
  ShowFile(std::string filePath, std::string fileType);
  Response *callback(Request *req);
};

class ShowPage : public ShowFile {

public:
  ShowPage(std::string _filePath);
};

class ShowImage : public ShowFile {

public:
  ShowImage(std::string _filePath);
};

class Server {
public:
  Server(int port = 5000);
  ~Server();
  void run();
  void get(std::string path, RequestHandler *handler);
  void post(std::string path, RequestHandler *handler);
  void setNotFoundErrPage(std::string);
  bool is_session_valid(std::string session_id);
  std::pair<std::string,std::string> get_user_by_session_ID(std::string session_id);
  void expire_session_id(std::string session_id);
  void add_session_id(std::string username, std::string pass, std::string SID);
  std::string session_gen();
  void login_with_session_id(std::string sid , Drive* drive);
    class Exception : public std::exception {
    public:
      Exception() {}
      Exception(const std::string);
      std::string getMessage();
    protected:
      std::string message;
    };

protected:
  friend class RequestHandler;
  int sc;
  int port;
  std::vector<Route *> routes;
  RequestHandler *notFoundHandler;
public:
  std::map<std::string, std::pair<std::string,std::string> > session_IDs;
};
#endif
