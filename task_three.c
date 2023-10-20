#include <stdio.h>
#include <stdlib.h>
#include <time.h>
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

void AddRandomShip(int size, int map[MAP_SIZE][MAP_SIZE]) {
    
    double direction = 0;
    int initial_row = 0;
    int initial_col = 0;
    int max_index = MAP_SIZE - size;

    direction = (rand() % 2);
    printf("direction: %f\n", direction);
    printf("max value: %d\n\n", RAND_MAX);
    

    // 50% chance the direction is horizontal
    if (direction <= 0.5)
    {
        initial_row = rand() % MAP_SIZE;
        initial_col = rand() % (max_index + 1);

        for (int col = 0; col < size; col++)
        {
            map[initial_row][initial_col + col] = size;
        }
        
    }
    // 50% chance the direction is vertical
    else
    {
        initial_row = rand() % (max_index + 1);
        initial_col = rand() % MAP_SIZE;
        
        for (int row = 0; row < size; row++)
        {
            map[initial_row + row][initial_col] = size;
        }
    }
}

int main(void) {

    /*
    int map1[MAP_SIZE][MAP_SIZE] = {0}; 
    
    AddRandomShip(5, map1);

    printf("Map 1: \n");
    PrintArray(map1);


    int map2[MAP_SIZE][MAP_SIZE] = {0};

    AddRandomShip(5, map2);
    AddRandomShip(2, map2);
    AddRandomShip(3, map2);
    AddRandomShip(4, map2);    

    printf("Map 2: \n");
    PrintArray(map2);
    */
    
    srand((unsigned int)time(NULL));

    int map[MAP_SIZE][MAP_SIZE];
    // Initialise the array
    for (int i = 0; i < MAP_SIZE; i++) {
        for (int j = 0; j < MAP_SIZE; j++) {
            map[i][j] = 0;
        }
    }
    for (int abc = 0; abc < 100; abc++)
    {
        AddRandomShip(2, map);
    }
    
    
    PrintArray(map);

    return 0;
}