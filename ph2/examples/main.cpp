#include "handlers.hpp"
#include "my_server.hpp"
#include "../drive/utilities.hpp"
#include <cstdlib> // for rand and srand
#include <ctime>   // for time
#include <iostream>

using namespace std;

int main(int argc,char const *argv[]) {
  srand(time(NULL)); // for rand
  try{
		check_if_path_is_given(argc);
	}catch(Exp e){
		cerr<<e<<endl;
		throw;
	}
	string drive_path=unify_main_path(argv, argc);
	Drive drive(DRIVE_NAME,drive_path);
  try {

    MyServer server (5000);
    server.setNotFoundErrPage("static/404.html");
    server.get("/login", new LoginGetHandler(&server , &drive));
    server.post("/login", new LoginPostHandler(&server , &drive));
    server.get("/up", new ShowPage("static/upload_form.html"));
    server.post("/up", new UploadHandler());
    server.get("/rand", new RandomNumberHandler());
    server.get("/logo.png", new ShowImage("static/logo.png"));
    server.get("/userlist.png", new ShowImage("static/userlist.png"));
    server.get("/fileslist.png", new ShowImage("static/fileslist.png"));
    server.get("/userprofile.png", new ShowImage("static/userprofile.png"));
    server.get("/filelogo.jpeg", new ShowImage("static/filelogo.jpeg"));
    server.get("/directorylogo.jpeg", new ShowImage("static/directorylogo.jpeg"));
    server.get("/", new ShowPage("static/home.html"));
    server.get("/manage",new ShowPage("static/manage.html"));
    server.get("/manage.css",new ShowPage("static/manage.css"));
    server.get("/logout",new LogoutHandler(&server , &drive));
    server.get("/userlist",new UserListHandler(&server , &drive));
    server.get("/userlist.css",new ShowPage("static/userlist.css"));
    server.get("/fileslist",new ElementListHandler(&server , &drive));
    server.get("/fileslist.css",new ShowPage("static/fileslist.css"));
    server.get("/adduser",new ShowPage("static/adduser.html"));
    server.get("/adduser.css",new ShowPage("static/adduser.css"));
    server.post("/adduser", new AddUserHandler(&server , &drive));
    server.get("/userpage",new ElementListHandler(&server , &drive));
    server.get("/userpage.css",new ShowPage("static/userpage.css"));
    server.post("/adddirectory", new AddDirectoryHandler(&server , &drive));



    server.run();
  } catch (Server::Exception e) {
    cerr << e.getMessage() << endl;
  }
}
