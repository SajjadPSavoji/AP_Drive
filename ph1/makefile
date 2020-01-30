all:ca4.o
ca4.o:  user.o normal_user.o super_user.o admin_user.o group.o file.o directory.o drive.o main.o utilities.o exception.o element.o   
	g++ user.o normal_user.o super_user.o admin_user.o group.o file.o directory.o drive.o main.o utilities.o exception.o element.o -o ca4.o
main.o: main.cpp
	g++ -c main.cpp
utilities.o: utilities.cpp utilities.hpp
	g++ -c utilities.cpp 
user.o: user.cpp user.hpp
	g++ -c user.cpp 
normal_user.o: normal_user.cpp normal_user.hpp user.o
	g++ -c normal_user.cpp 
admin_user.o: admin_user.cpp admin_user.hpp user.o
	g++ -c admin_user.cpp 
super_user.o: super_user.cpp super_user.hpp user.o
	g++ -c super_user.cpp
group.o: group.cpp group.hpp
	g++ -c group.cpp 
element.o: element.cpp element.hpp
	g++ -c element.cpp 
file.o: file.cpp file.hpp element.o
	g++ -c file.cpp 
directory.o: directory.cpp directory.hpp element.o
	g++ -c directory.cpp 
drive.o: drive.cpp drive.hpp
	g++ -c drive.cpp 
exception.o: exception.cpp exception.hpp
	g++ -c exception.cpp 
func.o: func.cpp func.hpp
	g++ -c func.cpp
clean:
	rm *.o