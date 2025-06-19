CC=gcc
FLAGS= -Wall -Wextra -Werror -std=c11

all: door_struct

door_struct: dmanager_module.c
	$(CC) $(FLAGS) dmanager_module.c -o ../build/Quest_1
	cd .. && cppcheck --enable=all --suppress=missingIncludeSystem src/

clean:
	rm -f *.o ../build/*
rebuild: clean all