#include <stdio.h>
#define MAP_SIZE 7

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
    int index = 0;
    int ship_num = 0;
    int ship_lengths[4] = {2, 3, 4, 5};

    for (int row = 0; row < MAP_SIZE; row++)
    {
        x += (MAP_SIZE-1)/3;
        index = (int)x;
        printf("row: %d\nx: %f\nindex: %d\nship_num: %d\n\n", row, x, index, ship_num);
        if (index == row)
        {
            for (int ship_block = 0; ship_block < ship_lengths[index]; ship_block++)
            {
                map[row][ship_block] = ship_lengths[ship_num];
            }
            ship_num += 1;
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