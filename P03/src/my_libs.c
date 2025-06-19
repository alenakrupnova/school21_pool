#include "my_libs.h"

int is_digit(char c) { return (c >= '0' && c <= '9'); }

int is_space(char c) { return (c == ' ' || c == '\t' || c == '\n' || c == '\r'); }

int check_func(const char *input, int pos, const char *func) {
    int i = 0;
    int res = 1;
    while (func[i] != '\0' && res != 0) {
        if (input[pos + i] != func[i]) {
            res = 0;
        }
        i++;
    }
    return res;
}

int is_operator(char op) {
    int res = (op == '*' || op == '+' || op == '-' || op == '/' || op == '^');
    return res;
}