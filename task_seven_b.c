#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#define MAP_SIZE 9


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

// AddRandomShip
void DummyFunctionOne(int size, int map[MAP_SIZE][MAP_SIZE]) {
    
    double direction = 0;
    int initial_row = 0;
    int initial_col = 0;
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
}

// IsShipValid
int DummyFunctionTwo(int size, int map[MAP_SIZE][MAP_SIZE]) {

    int validity = 0;
    int orientation = 0;
    int lower_row_bound = 0;
    int upper_row_bound = 0;
    int lower_col_bound = 0;
    int upper_col_bound = 0;    

    for (int row = 0; row < MAP_SIZE; row++) {
        for (int col = 0; col < MAP_SIZE; col++) {

            if (map[row][col] == size) {

                // find starting position of each ship (top left)
                int initial_row = row;
                int initial_col = col;

                // find orientation of ship (1: horizontal & 2: vertical)
                orientation = ((map[row + (1*(col+1 % MAP_SIZE == 0))][col+1 % MAP_SIZE] == size)*1 
                + (map[row + 1 % MAP_SIZE][col + (row + 1 % MAP_SIZE == 0)*1] == size)*2);

                if (orientation == 0)
                {
                    // if only one block found of ship
                    validity = 0;
                    return validity;
                }

                // find ending position of each ship (bottom right)
                int final_row = (orientation==1)*initial_row + (orientation==2)*(initial_row + size -1);
                int final_col = (orientation==1)*(initial_col + size -1) + (orientation==2)*initial_col;
            
                // set lower bounds for area to search
                lower_row_bound = initial_row - (initial_row != 0)*1;
                lower_col_bound = initial_col - (initial_col != 0)*1;
                upper_row_bound = final_row + (final_row != (MAP_SIZE - 1))*1;
                upper_col_bound = final_col + (final_col != (MAP_SIZE - 1))*1;

                int ship_length_count = 0;

                // check one block all around the ship (using search areas bounds above)
                for (int sub_row = lower_row_bound; sub_row <= upper_row_bound; sub_row++) {
                    for (int sub_col = lower_col_bound; sub_col <= upper_col_bound; sub_col++) {

                        int within_ship_bounds = (((initial_row <= sub_row) && (sub_row <= final_row)) && ((initial_col <= sub_col) && (sub_col <= final_col)));
                        int not_within_ship_bounds = !(within_ship_bounds);

                        // check that block is not in the corner:
                        int not_a_corner_block = (((initial_row <= sub_row) && (sub_row <= final_row)) || ((initial_col <= sub_col) && (sub_col <= final_col)));

                        // check that the block being checked is not part of the ship
                        if (not_within_ship_bounds && not_a_corner_block) {
                            
                            // check if there's non-empty blocks
                            if (map[sub_row][sub_col] != 0) {
                                // if any found, then ship is invalid
                                validity = 0;
                                return validity;
                            }                     
                        }

                        else if (within_ship_bounds) {
                            if (map[sub_row][sub_col] != size) {
                                // if any part of ship is a different number than the size, then ship is invalid
                                validity = 0;
                                return validity;
                            }
                            else {
                                ship_length_count += 1;
                            }
                        }
                        
                        
                    }    
                }
                
                // if ship is shorter than it should, then ship is invalid
                if (ship_length_count != size)
                {
                    validity = 0;
                    return validity;
                }

                // if no non-empty blocks found around ship, then ship is valid
                validity = 1;
                return validity;
            
            }
        }
    }
    return validity;
}

void InitialiseRandomMap(int map[MAP_SIZE][MAP_SIZE]) {        

    // set randomness seed
    //srand((unsigned int)time(NULL));

    int validShips[4] = {0, 0, 0, 0};
    int allValidShips = 0;

    // keep generating a map until it is valid
    while (!(allValidShips == 4)) {

        // clear blank array
        for (int row = 0; row < MAP_SIZE; row++) {
            for (int col = 0; col < MAP_SIZE; col++) {
                map[row][col] = 0;
            } 
        }

        // add all 4 ships randomly
        for (int size = 2; size <= 5; size++) {
            DummyFunctionOne(size, map);
        } // end of for-loop

        // check all 4 ships' validity
        for (int size = 2; size <= 5; size++) {
            validShips[size - 2] = DummyFunctionTwo(size, map);           
        }

        allValidShips = 0;
        for (int eachShip = 0; eachShip < 4; eachShip++) {
            allValidShips += validShips[eachShip];
        }

    } // end of while-loop
} // end of function

int main(void) {
    
    int map[MAP_SIZE][MAP_SIZE] = {0};
    InitialiseRandomMap(map);
    PrintArray(map);

    return 0;
}