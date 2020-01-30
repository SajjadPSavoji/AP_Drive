#include "utilities.hpp"
using namespace std;


int main(int argc, char const *argv[])
{
	vector<string> command_splited;
	string command_line;
	try{
		check_if_path_is_given(argc);
	}catch(Exp e){
		cerr<<e<<endl;
		throw;
	}
	string drive_path=unify_main_path(argv, argc);
	cerr<<drive_path<<endl;
	Drive drive(DRIVE_NAME,drive_path);
	while(getline(cin, command_line))
	{
		get_command(command_line,command_splited);
		try
		{
			execute_command(command_splited , drive);
		}catch(Exp e)
		{
			cerr<<e<<endl;
		}
	}	
	return 0;
}