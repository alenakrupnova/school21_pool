CC=gcc
FLAGS= -Wall -Wextra -Werror -std=c11

all: strlen_tests strcmp_tests strcpy_tests strcat_tests

strlen_tests: s21_string_test.c s21_string.c
	$(CC) $(FLAGS) -D S21_STRLEN_TEST s21_string_test.c s21_string.c -o ../build/Quest_1
	cd .. && cppcheck --enable=all --suppress=missingIncludeSystem src/

strcmp_tests: s21_string_test.c s21_string.c
	$(CC) $(FLAGS) -D S21_STRCMP_TEST s21_string_test.c s21_string.c -o ../build/Quest_2
	cd .. && cppcheck --enable=all --suppress=missingIncludeSystem src/

strcpy_tests: s21_string_test.c s21_string.c
	$(CC) $(FLAGS) -D S21_STRCPY_TEST s21_string_test.c s21_string.c -o ../build/Quest_3
	cd .. && cppcheck --enable=all --suppress=missingIncludeSystem src/

strcat_tests: s21_string_test.c s21_string.c
	$(CC) $(FLAGS) -D S21_STRCAT_TEST s21_string_test.c s21_string.c -o ../build/Quest_4
	cd .. && cppcheck --enable=all --suppress=missingIncludeSystem src/

clean:
	rm -f *.o *.a *.so ../build/*

rebuild: clean all
