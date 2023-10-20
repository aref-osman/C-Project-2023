#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#define MAP_SIZE 6


void PrintArray(int values[MAP_SIZE][MAP_SIZE]) {
    
    for (int row = 0; row < MAP_SIZE; row++) {
        for (int col = 0; col < MAP_SIZE; col++) {

            printf("%d", values[row][col]);
            if (col != MAP_SIZE-1) {
                printf(" ");
            }
        }
        printf("\n");
    }
}

void InitialiseRandomMap(int map[MAP_SIZE][MAP_SIZE]) {    
    
    // ship creation variables
    double direction = 0;
    int initial_row = 0;
    int initial_col = 0;
    int max_index = 0;

    // validity check variables
    int validShip = 0;
    int orientation = 0;
    int lower_row_bound = 0;
    int upper_row_bound = 0;
    int lower_col_bound = 0;
    int upper_col_bound = 0;    

    // set randomness seed
    srand((unsigned int)time(NULL));

    // keep generating a map until it is valid
    while (!validShip) {

        // clear blank array
        for (int row = 0; row < MAP_SIZE; row++) {
            for (int col = 0; col < MAP_SIZE; col++) {
                map[row][col] = 0;
            } 
        }

        // add all 4 ships randomly
        for (int size = 2; size <= 5; size++) {
            int max_index = MAP_SIZE - size;

            direction = (rand() % 2);            

            // 50% chance the direction is horizontal
            if (direction <= 0.5) {
                initial_row = rand() % MAP_SIZE;
                initial_col = rand() % (max_index + 1);

                for (int col = 0; col < size; col++) {
                    map[initial_row][initial_col + col] = size;
                }
            }

            // 50% chance the direction is vertical
            else {
                initial_row = rand() % (max_index + 1);
                initial_col = rand() % MAP_SIZE;
                
                for (int row = 0; row < size; row++) {
                    map[initial_row + row][initial_col] = size;
                }
            }

        } // end of for-loop


        // check ship validity here



    } // end of while-loop
} // end of function

int main(void) {

    int map[MAP_SIZE][MAP_SIZE] = {0};
    InitialiseRandomMap(map);
    PrintArray(map);

    return 0;
}