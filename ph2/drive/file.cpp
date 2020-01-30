#include "file.hpp"
using namespace std;
File::File(std::string name,std::string conteiner_path,User* creator,Group* group_named_by_creator,
	std::string content_path):Element(name, conteiner_path,creator,group_named_by_creator)
{
	read_file(content_path);
}
File::File(std::string name, std::string conteiner_path,User* creator,Group* group_named_by_creator
		,File& source_file):Element(name, conteiner_path,creator,group_named_by_creator)
{
	*(this) = source_file;
}
void File::read_file(std::string content_path)
{
	ifstream file (content_path, ios::in|ios::binary|ios::ate);
	if (file.good())
	{
		_size = file.tellg();
		_content = new char [_size];
		file.seekg (0, ios::beg);
		file.read (_content, _size);
		file.close();
	}
	else 
		throw Exp("could not read file");
}
void File::write_file(std::string destination_path)
{
	ofstream file(destination_path,ios::out|ios::binary);
	if (file.good())
	{
		file.write(_content, _size);
		file.close();
	}
	else 
		throw Exp("could not write file");	
}
std::ostream& operator<<(std::ostream& out , File* file)
{
	cout<<"file"<<SPACE;
	cout<<file->_creator_permission<<SPACE;
	cout<<file->_owners.second<<SPACE;
	cout<<file->_creator<<SPACE;
	cout<<file->_owners.first->get_name()<<SPACE;
	cout<<file->_path;
}
void File::announce_file_size()
{

	cout<<double(_size)/K<<endl;
}
File& File::operator=(File& source)
{
	char* source_content=source.get_content();
	_size=source.get_size();
	delete [] _content;
	_content=(char*)malloc(_size*sizeof(char));
	for (int i = 0; i < _size; ++i)
	{
		_content[i]=source_content[i];
	}
	return *(this);
}