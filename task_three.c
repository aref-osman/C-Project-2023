#include <stdio.h>
#include <stdlib.h>
#define MAP_SIZE 8

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

void AddRandomShip(int size, int map[MAP_SIZE][MAP_SIZE]) {
    
    double direction = 0;
    int initial_row = 0;
    int initial_col = 0;
    int max_index = MAP_SIZE - size;

    direction = (double)rand()/RAND_MAX;
    
    //printf("number: %f\n", direction);
    

    // 50% chance the direction is horizontal
    if (direction <= 0.5)
    {
        double x = MAP_SIZE*rand()/RAND_MAX;
        initial_row = (int)x;
        //printf("row: %d\n", initial_row);
        double y = (double)max_index*rand()/RAND_MAX;
        initial_col = (int)y;
        printf("col: %f\n\n", y);

        for (int col = 0; col < size; col++)
        {
            map[initial_row][initial_col + col] = size;
        }
        
    }
    // 50% chance the direction is vertical
    else
    {
        initial_row = (int)max_index*rand()/RAND_MAX;
        initial_col = (int)MAP_SIZE*rand()/RAND_MAX;
        
        /*
        for (int row = 0; row < size; row++)
        {
            map[initial_row + row][initial_col] = size;
        }
        */

    }

    //printf("initial row: %d\ninitial col: %d\n\n", initial_row, initial_col);
    

}

int main(void) {

    //int map1[MAP_SIZE][MAP_SIZE] = {0};
    int map2[MAP_SIZE][MAP_SIZE] = {0};
    
    
    //AddRandomShip(5, map1);

    //printf("Map: \n");
    //PrintArray(map1);

    for (int b = 0; b < 4; b++)
    {
        AddRandomShip(5, map2);
    }

    if (0 == 1)
    {
        AddRandomShip(2, map2);
        AddRandomShip(3, map2);
        AddRandomShip(4, map2);    
    }

    printf("Map: \n");
    PrintArray(map2);

    return 0;
}