#include <stdio.h>
int racket_left_input(char key);
int racket_right_input(char key);

int main() {
    return 0;
}


// Функция обработки клавиш для левой ракетки (не используется в main!)
int racket_left_input(char key) {
    switch(key) {
        case 'A': case 'a': return 1; // вверх
        case 'Z': case 'z': return -1; // вниз
        default: return 0;
    }
}

// Функция обработки клавиш для правой ракетки (не используется в main!)
int racket_right_input(char key) {
    switch(key) {
        case 'K': case 'k': return 1; // вверх
        case 'M': case 'm': return -1; // вниз
        default: return 0;
    }
}