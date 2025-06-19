CC = gcc
CFLAGS = -Wall -Wextra -Werror
TARGET = ../build/graph
TEST_TARGET = ../build/test
SRC = graph.c rpn.c stack.c calculation.c draw.c my_libs.c rpn.h stack.h calculation.h draw.h my_libs.h
TEST_SRC = test.c rpn.c stack.c calculation.c my_libs.c rpn.h stack.h calculation.h

all: format $(TARGET) $(TEST_TARGET)

$(TARGET): $(SRC)
	mkdir -p ../build/
	$(CC) $(CFLAGS) $^ -o $@ -lm

$(TEST_TARGET): $(TEST_SRC)
	$(CC) $(CFLAGS) $^ -o $@ -lm

clean:
	rm -rf ../build *.out

test: $(TEST_TARGET)
	./$(TEST_TARGET)

rebuild: clean all

format:
	clang-format -i *.c
	clang-format -i *.h