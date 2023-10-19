#include <stdio.h>
#define MAP_SIZE 6

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


    int map1[MAP_SIZE][MAP_SIZE];
    // Initialise the array
    for (int i = 0; i < MAP_SIZE; i++) {
        for (int j = 0; j < MAP_SIZE; j++) {
            map1[i][j] = 0;    
        }
    }

    PrintArray(map1);

    return 0;
}