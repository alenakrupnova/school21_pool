#include <stdio.h>
#define HEIGHT 25
#define WIDTH 80
void graphic();

int main() {
    
    graphic();
    return 0;
}

void graphic() {
    int ball_x = 39; // начальная позиция мяча (посередине поля)
    int ball_y = 12;  
    int sc1 = 0; // начальный счет игрока слева
    int sc2 = 0; // начальный счет игрока справа
    int position_racket_left = 12; // начальная позиция ракеток (по центру по вертикали Y)
    int position_racket_right = 12;

    // очистка экрана (25 пустых строк)
    for (int i = 0; i <= HEIGHT; i++) {
        printf("\n");
    }
 
    // вывод счета
    printf("Player1 %d\n", sc1);
    printf("Player2 %d\n", sc2);

    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {

            // Верхняя и нижняя границы
            if (y == 0 || y == HEIGHT - 1) {
                printf("-");
            }

            // Боковые границы
            else if ((y > 0 && y < (HEIGHT - 1)) && (x == 0 || x == WIDTH - 1)) {
                printf("|");
            }

            // Левая ракетка: 3 символа по вертикали (y-1, y, y+1, в колонке х==1)
            else if (x == 1 && (y == position_racket_left - 1 || y == position_racket_left || y == position_racket_left + 1)) {
                printf("|");
            }

            // Правая ракетка: 3 символа по вертикали (y-1, y, y+1, в колонке х==78)
            else if (x == 78 && (y == position_racket_right  - 1 || y == position_racket_right  || y == position_racket_right  + 1)) {
                printf("|");
            }

            // Мяч 
            else if (y == ball_y && x == ball_x) {
                printf("o");
            }

            // Остальное пустое пространство
            else {
                printf(" ");
            }

        }
        printf("\n"); // переход на новую строку после одного цикла по Х (полной строки)
    }

}

