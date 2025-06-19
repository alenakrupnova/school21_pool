#ifndef DRAW_H
#define DRAW_H

#define WIDTH 80
#define HEIGHT 25
#define X_MIN 0
#define X_MAX (4 * M_PI)

void init_graph(char graph[HEIGHT][WIDTH]);
void draw_graph(char graph[HEIGHT][WIDTH]);

#endif