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

int IsShipValid(int size, int map[MAP_SIZE][MAP_SIZE]) {

    int validity = 0;
    int orientation = 0;
    int lower_row_bound = 0;
    int upper_row_bound = 0;
    int lower_col_bound = 0;
    int upper_col_bound = 0;    

    for (int row = 0; row < MAP_SIZE; row++) {
        for (int col = 0; col < MAP_SIZE; col++) {

            if (map[row][col] == size) {

                //printf("\nship %d, confirmation\n", size);

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
                
                //printf("orientation: %d\n", orientation);
                //printf("initial row: %d | initial col: %d | final row: %d | final col: %d\n", initial_row, initial_col, final_row, final_col);
                //printf("lower row bound: %d | upper row bound: %d\n", lower_row_bound, upper_row_bound);
                //printf("lower col bound: %d | upper col bound: %d\n\n", lower_col_bound, upper_col_bound);

                int ship_length_count = 0;

                // check one block all around the ship (using search areas bounds above)
                for (int sub_row = lower_row_bound; sub_row <= upper_row_bound; sub_row++) {
                    for (int sub_col = lower_col_bound; sub_col <= upper_col_bound; sub_col++) {

                        int within_ship_bounds = (((initial_row <= sub_row) && (sub_row <= final_row)) && ((initial_col <= sub_col) && (sub_col <= final_col)));
                        int not_within_ship_bounds = !(within_ship_bounds);
                        //printf("part a: %d | part b: %d | part c: %d\n", part_a, part_b, part_c);
                        //printf("row: %d | col: %d | not_within_ship_bounds: %d\n", sub_row, sub_col, not_within_ship_bounds);
                        // check that the block being checked is not part of the ship
                        if (not_within_ship_bounds) {
                            
                            // check if there's non-empty blocks
                            if (map[sub_row][sub_col] != 0) {
                                // if any found, then ship is invalid
                                validity = 0;
                                //printf("Validity check failed at sub_row %d and sub_col %d\n\n", sub_row, sub_col);
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
    //printf("what the heckkk");
    return validity;
}

int main(void) {
    /*
    int map[MAP_SIZE][MAP_SIZE] = {0};
    int valid, shipSize;

    InitialiseMap(map);
    PrintArray(map);

    for (shipSize = 2; shipSize <= 5; shipSize++) {
        valid = IsShipValid(shipSize, map);
        printf("Is ship %d valid? %d\n", shipSize, valid);
    }

    // Move Ship 3 to an invalid position
    map[2][3] = 0;
    map[2][0] = 3;
    
    // Move Ship 4 to an invalid position
    map[6][0] = 0;
    map[6][1] = 0;
    map[6][2] = 0;
    map[6][3] = 0;
    map[4][3] = 4;
    map[4][4] = 4;
    map[4][5] = 4;
    map[4][6] = 4;
    map[6][5] = 5;

    
    PrintArray(map);

    for (shipSize = 2; shipSize <= 5; shipSize++) {
        valid = IsShipValid(shipSize, map);
        printf("Is ship %d valid? %d\n", shipSize, valid);
    }
    */
    int map[MAP_SIZE][MAP_SIZE];
    int valid, shipSize;
    int output = 0;

    // Initialise a random (and valid) map 1000 times
    for (int i = 0; i < 1000; i++) {
    InitialiseMap(map);
    // All ships are in valid positions
    // Check that IsShipValid() returns true
    for (shipSize = 2; shipSize <= 5; shipSize++) {
        valid = IsShipValid(shipSize, map);
        if (!valid) {
            if (!output) {
                printf("Reporting an invalid ship!\n");
                PrintArray(map);
                output = 1;
            }
        }
    }
    }
    printf("All ships are valid");
    
    return 0;
}