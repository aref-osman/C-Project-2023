#include <stdio.h>
#define MAP_SIZE 15

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

    double x = 0;
    int ship_row = 0;
    int ship_lengths[4] = {2, 3, 4, 5};

    for (int ship_num = 0; ship_num < 4; ship_num++)
    {
        
        ship_row = ship_num*(MAP_SIZE-1)/3;

        for (int ship_block = 0; ship_block < ship_lengths[ship_num]; ship_block++) {   
            map[ship_row][ship_block] = ship_lengths[ship_num];
        }

    }
    
    
}

int main(void){

    int map1[MAP_SIZE][MAP_SIZE] = {0};
    InitialiseMap(map1);
    printf("Map: \n");
    PrintArray(map1);

    return 0;
}