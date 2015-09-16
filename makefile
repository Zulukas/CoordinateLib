NAME=libcoordinate.so
CPPFLAGS=-g -o $(NAME) -fPIC -shared
FILE=coordinate.cpp

$(NAME): $(FILE)
	g++ $(FILE) $(CPPFLAGS)
