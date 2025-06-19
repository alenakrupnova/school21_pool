#include <stdio.h>

void encoding_mode();
void decoding_mode();

int main() {
    printf("Введите режим работы: 0 - кодирование или 1 - декодирование");
    int mode;
    scanf("%d", &mode);
    if (mode == 0) {
        encoding_mode();
    }
    else if (mode == 1) {
        decoding_mode();
    }
    else
        printf("n/a\n");
    
    return 0;    
}

void encoding_mode() {

}

void decoding_mode() {

}