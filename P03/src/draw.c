#include "draw.h"

#include <stdio.h>

void init_graph(char graph[HEIGHT][WIDTH]) {
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            graph[y][x] = '.';
        }
    }
}

void draw_graph(char graph[HEIGHT][WIDTH]) {
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            putchar(graph[y][x]);
        }
        putchar('\n');
    }
}