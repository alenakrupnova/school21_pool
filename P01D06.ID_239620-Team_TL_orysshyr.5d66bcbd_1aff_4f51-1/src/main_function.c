#include <stdio.h>
#define HEIGHT 25
#define WIDTH 80

int racket_left(int coord, int step);
int racket_right(int coord, int step);
void graphic(int ball_x, int ball_y, int pos_racket_left, int pos_racket_right, int score1, int score2);
void win(int sc1, int sc2);
int input(char symbol);

int main() {
    int ball_x = 39; // начальная позиция мяча
    int ball_y = 12;  
    int sc1 = 0; // счет
    int sc2 = 0;
    int pos_racket_left = 12; // начальная позиция центра ракеток
    int pos_racket_right = 12;
    
    
    while (1) {
        char symbol;
        graphic(ball_x, ball_y, pos_racket_left, pos_racket_right, sc1, sc2);

        if (scanf("%c", &symbol) == 1 && input(symbol)) {
            if (symbol == 'A' || symbol == 'a') {
                pos_racket_left = racket_left(pos_racket_left, -1);
            }
            else if (symbol == 'Z' || symbol == 'z') {
                pos_racket_left = racket_left(pos_racket_left, 1);
            }
            
            else if (symbol == 'K' || symbol == 'k') {
                pos_racket_right = racket_right(pos_racket_right, -1);
            } else if (symbol == 'M' || symbol == 'm') {
                pos_racket_right = racket_right(pos_racket_right, 1);
            }
            scanf("%*[^\n]");
        }

        // ход мяча ...

        if (sc1 >= 21 || sc2 >= 21) {
            win(sc1, sc2);
            break;
        }
    }
    
}

int input(char symbol) {
    return symbol == 'A' || symbol == 'a' || symbol == 'Z' || symbol == 'z' || symbol == 'K' || symbol == 'k' || symbol == 'M' || symbol == 'm' || symbol == ' ';
}

// Движение левой ракетки
int racket_left(int coord, int step) {
    int new_pos = coord + step;
    if (new_pos < 2) { 
        return 2;
    }
    else if (new_pos > 22) {
        return 22;
    }
    return new_pos;
}

// Движение правой ракетки 
int racket_right(int coord, int step) {
    int new_pos = coord + step;
    if (new_pos < 2) {
        return 2;
    } else if (new_pos > 22) {
        return 22;
    }
    return new_pos;
}

// Подсчет очков
int score1(int sc1, int ball_x, int ball_y, int pos_racket_left) {
    if ((ball_x == 1) &&
        (ball_y != pos_racket_left || ball_y != pos_racket_left + 1 || ball_y != pos_racket_left - 1)) {
        sc1++;
    }
    return sc1;
}

int score2(int sc2, int ball_x, int ball_y, int pos_racket_right) {
    if ((ball_x == 79) &&
        (ball_y != pos_racket_right || ball_y != pos_racket_right + 1 || ball_y != pos_racket_right - 1)) {
        sc2++;
    }
    return sc2;
}

// Условие победы
void win(int sc1, int sc2) {
    if (sc1 >= 21) {
        printf("Congratulations! Player 1 WON! Final score: %d - %d\n", sc1, sc2);
    } else {
        printf("Congratulations! Player 2 WON! Final score: %d - %d\n", sc1, sc2);
    }
}

void graphic(int ball_x, int ball_y, int pos_racket_left, int pos_racket_right, int score1, int score2) {
    
    for (int i = 0; i <= HEIGHT; i++) {
        printf("\n");
    }
 
    printf("Player1 %d\n", score1);
    printf("Player2 %d\n", score2);

    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {

            if (y == 0 || y == HEIGHT - 1) {
                printf("-");
            }

            else if ((y > 0 && y < (HEIGHT - 1)) && (x == 0 || x == WIDTH - 1)) {
                printf(" ");
            }

            // Левая ракетка
            else if (x == 1 && (y == pos_racket_left - 1 || y == pos_racket_left || y == pos_racket_left + 1)) {
                printf("|");
            }

            // Правая ракетка
            else if (x == 78 && (y == pos_racket_right  - 1 || y == pos_racket_right  || y == pos_racket_right  + 1)) {
                printf("|");
            }

            else if (y == ball_y && x == ball_x) {
                printf("o");
            }

            else {
                printf(" ");
            }

        }
        printf("\n");
    }

}