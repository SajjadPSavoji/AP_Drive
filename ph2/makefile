CC=g++
STD=-std=c++11 -Wall -pedantic
CF=$(STD)
BUILD_DIR=build

all: $(BUILD_DIR) myserver.out

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

$(BUILD_DIR)/response.o: utils/response.cpp utils/response.hpp utils/include.hpp
	$(CC) $(CF) -c utils/response.cpp -o $(BUILD_DIR)/response.o

$(BUILD_DIR)/request.o: utils/request.cpp utils/request.hpp utils/include.hpp utils/utilities.hpp
	$(CC) $(CF) -c utils/request.cpp -o $(BUILD_DIR)/request.o

$(BUILD_DIR)/utilities.o: utils/utilities.cpp utils/utilities.hpp
	$(CC) $(CF) -c utils/utilities.cpp -o $(BUILD_DIR)/utilities.o

$(BUILD_DIR)/server.o: server/server.cpp server/server.hpp server/route.hpp utils/utilities.hpp utils/response.hpp utils/request.hpp utils/include.hpp
	$(CC) $(CF) -c server/server.cpp -o $(BUILD_DIR)/server.o

$(BUILD_DIR)/route.o: server/route.cpp server/route.hpp utils/utilities.hpp utils/response.hpp utils/request.hpp utils/include.hpp
	$(CC) $(CF) -c server/route.cpp -o $(BUILD_DIR)/route.o

$(BUILD_DIR)/handlers.o: examples/handlers.cpp server/server.hpp utils/utilities.hpp utils/response.hpp utils/request.hpp utils/include.hpp
	$(CC) $(CF) -c examples/handlers.cpp -o $(BUILD_DIR)/handlers.o

$(BUILD_DIR)/my_server.o: examples/my_server.cpp server/server.hpp utils/utilities.hpp utils/response.hpp utils/request.hpp utils/include.hpp
	$(CC) $(CF) -c examples/my_server.cpp -o $(BUILD_DIR)/my_server.o

$(BUILD_DIR)/main.o: examples/main.cpp server/server.hpp utils/utilities.hpp utils/response.hpp utils/request.hpp utils/include.hpp
	$(CC) $(CF) -c examples/main.cpp -o $(BUILD_DIR)/main.o





$(BUILD_DIR)/drive_utilities.o: drive/utilities.cpp drive/utilities.hpp
	$(CC) $(CF) -c drive/utilities.cpp -o $(BUILD_DIR)/drive_utilities.o
$(BUILD_DIR)/user.o: drive/user.cpp drive/user.hpp
	$(CC) $(CF) -c drive/user.cpp -o $(BUILD_DIR)/user.o
$(BUILD_DIR)/normal_user.o: drive/normal_user.cpp drive/normal_user.hpp $(BUILD_DIR)/user.o
	$(CC) $(CF) -c drive/normal_user.cpp -o $(BUILD_DIR)/normal_user.o
$(BUILD_DIR)/admin_user.o: drive/admin_user.cpp drive/admin_user.hpp $(BUILD_DIR)/user.o
	$(CC) $(CF) -c drive/admin_user.cpp -o $(BUILD_DIR)/admin_user.o
$(BUILD_DIR)/super_user.o: drive/super_user.cpp drive/super_user.hpp $(BUILD_DIR)/user.o
	$(CC) $(CF) -c drive/super_user.cpp -o $(BUILD_DIR)/super_user.o
$(BUILD_DIR)/group.o: drive/group.cpp drive/group.hpp
	$(CC) $(CF) -c drive/group.cpp -o $(BUILD_DIR)/group.o
$(BUILD_DIR)/element.o: drive/element.cpp drive/element.hpp
	$(CC) $(CF) -c drive/element.cpp -o $(BUILD_DIR)/element.o
$(BUILD_DIR)/file.o: drive/file.cpp drive/file.hpp $(BUILD_DIR)/element.o
	$(CC) $(CF) -c drive/file.cpp -o $(BUILD_DIR)/file.o
$(BUILD_DIR)/directory.o: drive/directory.cpp drive/directory.hpp $(BUILD_DIR)/element.o
	$(CC) $(CF) -c drive/directory.cpp -o $(BUILD_DIR)/directory.o
$(BUILD_DIR)/drive.o: drive/drive.cpp drive/drive.hpp
	$(CC) $(CF) -c drive/drive.cpp -o $(BUILD_DIR)/drive.o
$(BUILD_DIR)/exception.o: drive/exception.cpp drive/exception.hpp
	$(CC) $(CF) -c drive/exception.cpp -o $(BUILD_DIR)/exception.o


myserver.out: $(BUILD_DIR)/my_server.o $(BUILD_DIR)/main.o $(BUILD_DIR)/handlers.o $(BUILD_DIR)/response.o $(BUILD_DIR)/request.o $(BUILD_DIR)/utilities.o $(BUILD_DIR)/server.o $(BUILD_DIR)/route.o   $(BUILD_DIR)/drive_utilities.o $(BUILD_DIR)/user.o $(BUILD_DIR)/normal_user.o $(BUILD_DIR)/admin_user.o $(BUILD_DIR)/super_user.o $(BUILD_DIR)/group.o $(BUILD_DIR)/element.o $(BUILD_DIR)/file.o $(BUILD_DIR)/directory.o $(BUILD_DIR)/drive.o $(BUILD_DIR)/exception.o 
	$(CC) $(CF) $(BUILD_DIR)/my_server.o $(BUILD_DIR)/main.o $(BUILD_DIR)/handlers.o $(BUILD_DIR)/response.o $(BUILD_DIR)/request.o $(BUILD_DIR)/utilities.o $(BUILD_DIR)/server.o $(BUILD_DIR)/route.o   $(BUILD_DIR)/drive_utilities.o $(BUILD_DIR)/user.o $(BUILD_DIR)/normal_user.o $(BUILD_DIR)/admin_user.o $(BUILD_DIR)/super_user.o $(BUILD_DIR)/group.o $(BUILD_DIR)/element.o $(BUILD_DIR)/file.o $(BUILD_DIR)/directory.o $(BUILD_DIR)/drive.o $(BUILD_DIR)/exception.o  -o myserver.out


.PHONY: clean
clean:
	rm -rf $(BUILD_DIR) *.o *.out &> /dev/null
