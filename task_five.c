#include <stdio.h>
#define MAP_SIZE 7

int TopLeftPosition(int size, int *row, int *col, int map[MAP_SIZE][MAP_SIZE]) {

    int direction = 0;

    for (int arr_row = 0; arr_row < MAP_SIZE; arr_row++) {
        for (int arr_col = 0; arr_col < MAP_SIZE; arr_col++) {

            if (map[arr_row][arr_col] == size)
            {
                *row = arr_row;
                *col = arr_col;
                return((map[arr_row + (1*(col+1 % MAP_SIZE == 0))][arr_col+1 % MAP_SIZE] == size)*1 
                + (map[arr_row + 1 % MAP_SIZE][arr_col + (row + 1 % MAP_SIZE == 0)*1] == size)*2);
            }
        }
    }
    
    return direction;
}


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


void InitialiseMap(int map[MAP_SIZE][MAP_SIZE]) {

    int ship_row = 0;
    int ship_lengths[4] = {2, 3, 4, 5};

    // initialise blank array
    for (int row = 0; row < MAP_SIZE; row++)
    {
        for (int col = 0; col < MAP_SIZE; col++)
        {
            map[row][col] = 0;
        }
        
    }
    

    for (int ship_num = 0; ship_num < 4; ship_num++)
    {
        // place the 3 block ship vertically next to the 2 block ship, 3 blocks away
        if (ship_num == 1)
        {
            ship_row = (ship_num-1)*(MAP_SIZE-1)/3;
            map[ship_row][5] = 3;
            map[ship_row + 1][5] = 3;
            map[ship_row + 2][5] = 3;
        }
        // linearly space all the other ships
        else
        {
            ship_row = ship_num*(MAP_SIZE-1)/3;
            for (int ship_block = 0; ship_block < ship_lengths[ship_num]; ship_block++) {   
                map[ship_row][ship_block] = ship_lengths[ship_num];
            }
        }
    }
}


int main(void) {


    int row, col, direction;
    int map[MAP_SIZE][MAP_SIZE] = {
    {0, 0, 0, 3, 3, 3, 0},
    {0, 5, 0, 0, 0, 0, 0},
    {0, 5, 0, 0, 4, 0, 0},
    {0, 5, 0, 0, 4, 0, 0},
    {0, 5, 0, 0, 4, 0, 0},
    {0, 5, 0, 0, 4, 0, 0},
    {0, 0, 2, 2, 0, 0, 0}
    };

    for (int shipSize = 2; shipSize <= 5; shipSize++) {
        direction = TopLeftPosition(shipSize, &row, &col, map);
        printf("Ship %d is at (%d, %d) facing %d\n", shipSize, row, col, direction);
    }

    return 0;
}