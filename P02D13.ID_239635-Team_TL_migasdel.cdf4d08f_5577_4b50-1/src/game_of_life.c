#include <ncurses.h>
#include <stdio.h>
#define N 25
#define M 80
#define MAX_SPEED 15
#define MIN_SPEED 1

int count_neighbours(int matr[N][M], int i, int j);
void new_state(int matr1[N][M], int matr2[N][M]);
void draw_matrix(int matr[N][M]);
int count_alive(int matr[N][M]);
void update(int matr2[N][M], int matr1[N][M]);
int handle_input(int *speed);
void load_pattern(int matr[N][M]);

int main() {
    int matr1[N][M] = {0}, matr2[N][M] = {0};
    int flag = 1;
    int speed = 7;

    load_pattern(matr1);

    if (freopen("/dev/tty", "r", stdin) != NULL) {  // ввод через терминал
        initscr();
    }
    cbreak();               // Режим без буферизации
    noecho();               // Не отображать ввод
    nodelay(stdscr, TRUE);  // Неблокирующий ввод
    keypad(stdscr, TRUE);   // Включаем расширенную обработку клавиш
    curs_set(0);            // Скрыть курсор

    draw_matrix(matr1);
    while (flag != 0) {
        clear();
        flag = handle_input(&speed);
        if (count_alive(matr1) == 0) {
            flag = 0;
        }
        new_state(matr1, matr2);
        draw_matrix(matr2);
        update(matr2, matr1);
        refresh();
        napms(1000 / speed);
    }

    endwin();
    return 0;
}

int handle_input(int *speed) {  // Обработка ввода с клавиатуры
    int res = 1;
    int ch = getch();
    if (ch != ERR) {
        if (ch == 'a' || ch == 'A') {
            if (*speed < MAX_SPEED) (*speed)++;
        } else if (ch == 'z' || ch == 'Z') {
            if (*speed > MIN_SPEED) (*speed)--;
        } else if (ch == ' ') {
            res = 0;
        }
    }
    return res;
}

void load_pattern(int matr[N][M]) {  // Считывание из файла
    int y = 0, x = 0;
    char c;
    while ((c = getchar()) != EOF && y < N) {
        if (c == '\n') {
            y++;
            x = 0;
            continue;
        }
        if (x < M) {
            if (c == '1') {
                matr[y][x] = 1;
            } else {
                matr[y][x] = 0;
            }
            x++;
        }
    }
}

int count_neighbours(int matr[N][M], int i, int j) {  // Высчитываем количество живых соседей
    int counter = 0;
    i += N;
    j += M;
    counter += matr[(i - 1) % N][(j - 1) % M];
    counter += matr[(i - 1) % N][j % M];
    counter += matr[(i - 1) % N][(j + 1) % M];
    counter += matr[i % N][(j + 1) % M];
    counter += matr[(i + 1) % N][(j + 1) % M];
    counter += matr[(i + 1) % N][j % M];
    counter += matr[(i + 1) % N][(j - 1) % M];
    counter += matr[i % N][(j - 1) % M];
    return counter;
}

void new_state(int matr1[N][M], int matr2[N][M]) {  // Прописываем логику живых/мертвых клеток
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            int neighbours = count_neighbours(matr1, i, j);
            if (neighbours == 3 && matr1[i][j] == 0) {
                matr2[i][j] = 1;
            } else if ((neighbours == 2 || neighbours == 3) && matr1[i][j] == 1) {
                matr2[i][j] = 1;
            } else {
                matr2[i][j] = 0;
            }
        }
    }
}

void draw_matrix(int matr[N][M]) {  // Отрисовка
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (matr[i][j] == 1) {
                printw("0");
            } else {
                printw(" ");
            }
        }
        printw("\n");
    }
}

int count_alive(int matr[N][M]) {  // Подсчет живых клеток
    int cnt = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cnt += matr[i][j];
        }
    }
    return cnt;
}

void update(int matr2[N][M], int matr1[N][M]) {  // Обновление основного поля
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            matr1[i][j] = matr2[i][j];
        }
    }
}