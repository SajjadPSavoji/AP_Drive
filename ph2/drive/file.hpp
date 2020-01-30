#ifndef FILE_HEADER_GUARD
#define FILE_HEADER_GUARD
#include <fstream>

#include "element.hpp"

#define K 1000.0
#define KB "KByte"
class File : public Element
{
public:
	File(std::string name, std::string conteiner_path,User* creator,Group* group_named_by_creator
		,std::string content_path);
	File(std::string name, std::string conteiner_path,User* creator,Group* group_named_by_creator
		,File& source_file);
	void read_file(std::string content_path);
	void write_file(std::string destination_path);
	void announce_file_size();
	std::streampos get_size(){return _size;}
	void set_size(std::streampos new_size){_size=new_size;}
	char* get_content(){return _content;}
	File& operator=(File& source);
	~File(){delete[] _content;}


protected:
	char* _content=NULL;
	std::streampos _size;
	friend class Directory;
	friend std::ostream& operator<<(std::ostream& out , File* file);
};
std::ostream& operator<<(std::ostream& out , File* file);
#endif