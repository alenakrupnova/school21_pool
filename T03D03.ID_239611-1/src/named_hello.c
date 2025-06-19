#include <stdio.h>

int main() {
    int name;
    printf("Как тебя зовут?");
    scanf("%d", &name);
    printf("Hello, %d!\n", name);
    return 0;
}