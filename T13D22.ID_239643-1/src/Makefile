CC=gcc
FLAGS= -Wall -Wextra -Werror -std=c11

all: cipher

cipher: cipher.c
	$(CC) $(FLAGS) cipher.c -o ../build/cipher

cppcheck:
	cd .. && cppcheck --enable=all --suppress=missingIncludeSystem src/

clean:
	rm -f *.o ../build/*

rebuild: clean all