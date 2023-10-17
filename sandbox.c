#include <stdio.h>

int main(void) {

    int x[3] = {0, 0, 0};

    x[0] = 3/4;
    x[1] = 6/4;
    x[2] = 12/4;

    printf("{%d %d %d}", x[0], x[1], x[2]);

    return 0;
}