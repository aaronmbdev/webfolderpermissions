all: PermissionSetter

PermissionSetter: PermissionSetter.o
	g++ -ansi -O2 -DNDEBUG -D_GLIBCXX_DEBUG -Wall -Wextra -Werror -Wno-sign-compare -Wshadow -o PermissionSetter PermissionSetter.o

PermissionSetter.o: src/PermissionSetter.cc
	g++ -ansi -O2 -DNDEBUG -D_GLIBCXX_DEBUG -Wall -Wextra -Werror -Wno-sign-compare -Wshadow -c src/PermissionSetter.cc

clean:
	rm PermissionSetter.o

fclean: clean
	rm PermissionSetter