#include <stdio.h>

int move_racket_left(int coord_left, int racket_step);
int move_racket_right(int coord_left, int racket_step);

int main() {
    return 0;
}

// Функция движения левой ракетки
int move_racket_left(int coord_left, int racket_step) {
    int new_pos = coord_left + racket_step;
    // Проверка границ (не даем выйти за пределы поля)
    if (new_pos < 2) { // Верхняя граница (учитываем длину ракетки 3 клетки)
        return 2;
    }
    else if (new_pos > 22) { // Нижняя граница (учитываем длину ракетки 3 клетки)
        return 22;
    }
    return new_pos;
}

// Функция движения правой ракетки (аналогична левой)
int move_racket_right(int coord_right, int racket_step) {
    int new_pos = coord_right + racket_step;
    if (new_pos < 2) {
        return 2;
    } else if (new_pos > 22) {
        return 22;
    }
   return new_pos;
}