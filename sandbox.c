#include <stdio.h>

int main(void) {

    int a = 0;
    int b = 0;
    int c = (a <= 0) && (0 <= b);
    printf("a: %d | b: %d | c: %d\n\n", a, b, c);

    return 0;
}