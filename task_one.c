#include <stdio.h>
#define MAP_SIZE 5

void PrintArray(int values[MAP_SIZE][MAP_SIZE]) {
    
    for (int row = 0; row < MAP_SIZE; row++)
    {
        for (int col = 0; col < MAP_SIZE; col++)
        {
            printf("%d", values[row][col]);
            if (col != MAP_SIZE-1)
            {
                printf(" ");
            }
            
        }
        printf("\n");
    }

}

int main(void) {

    int val[MAP_SIZE][MAP_SIZE] = 
    {{1, 2, 3, 4, 5}, {1, 2, 3, 4, 5}, {1, 2, 3, 4, 5}, {1, 2, 3, 4, 5}, {1, 2, 3, 4, 5}};

    PrintArray(val);

    return 0;
}