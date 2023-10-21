#include <stdio.h>
#define MAP_SIZE 6

void PrintArray(int values[MAP_SIZE][MAP_SIZE]) {
    
    for (int row = 0; row < MAP_SIZE; row++) {
        for (int col = 0; col < MAP_SIZE; col++) {
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

void AdjustSunkShip(int shots[MAP_SIZE][MAP_SIZE], int map[MAP_SIZE][MAP_SIZE], int shipLength) {

    int map_content = 0;
    int offset = 1000*(shipLength - 1);

    for (int var_row = 0; var_row < MAP_SIZE; var_row++) {
        for (int var_col = 0; var_col < MAP_SIZE; var_col++) {
            
            map_content = map[var_row][var_col];

            // if the block contains the sunk ship
            if (map_content == shipLength) {
                // add the correct multiple of thousand to block
                shots[var_row][var_col] = shots[var_row][var_col] + offset;
            }

        } // end of row scanning
    } // end of column scanning
} // end of function

void FireShot(int shots[MAP_SIZE][MAP_SIZE], int map[MAP_SIZE][MAP_SIZE], int row, int col) {

    int numShots = 0;
    int shotsPerShip[4] = {0, 0, 0, 0};
    int map_content = 0;
    int shots_content = 0;

    // count unique shots made on each ship
    for (int var_row = 0; var_row < MAP_SIZE; var_row++) {
        for (int var_col = 0; var_col < MAP_SIZE; var_col++) {
            
            map_content = map[var_row][var_col];
            shots_content = shots[var_row][var_col];

            if (shots_content != 0) {
                numShots += 1;

                // see if ship 5 has been sunken
                if (shots_content < 6000 && shots_content > 5000) {
                    shotsPerShip[3] = 5;
                }
                // see if ship 4 has been sunken
                else if (shots_content < 5000 && shots_content > 4000) {
                    shotsPerShip[2] = 4;
                }
                // see if ship 3 has been sunken
                else if (shots_content < 4000 && shots_content > 3000) {
                    shotsPerShip[1] = 3;
                }
                // see if ship 2 has been sunken
                else if (shots_content < 3000 && shots_content > 2000) {
                    shotsPerShip[0] = 2;
                }
                // see for non-sinking shot
                else if (shots_content < 2000 && shots_content > 1000) {
                    shotsPerShip[map_content - 2] = shotsPerShip[map_content - 2] + 1;
                }

            } // end of cell scanning

        } // end of col scanning
    } // end of row scanning

    // get values from both shots and maps arrays
    int mapContent = map[row][col];
    int shotContent = shots[row][col];

    // check that reference block hasn't been shot already
    if (shotContent == 0) {

        // if no ship on this block
        if (mapContent == 0) {
            // plot the shot number
            shots[row][col] = numShots + 1;
        }

        // there's a ship block here
        else {
            // plot the shot number + 1000
            shots[row][col] = 1000 + numShots + 1;

            // ship is almost sunken (about to sink)
            if (mapContent == (shotsPerShip[mapContent - 2] + 1)) {
                // add the correct multiple of 1000 to existing shots
                AdjustSunkShip(shots, map, mapContent);
            }
        } // end of else-statement
        
    } // end of if-statement

} // end of function


int main(void) {
    
    int map[MAP_SIZE][MAP_SIZE] = {
    {3, 0, 0, 0, 0, 5},
    {3, 0, 2, 2, 0, 5},
    {3, 0, 0, 0, 0, 5},
    {0, 0, 0, 0, 0, 5},
    {0, 0, 0, 0, 0, 5},
    {4, 4, 4, 4, 0, 0}
    };

    int shots[MAP_SIZE][MAP_SIZE] = {0};

    for (int i = 0; i < MAP_SIZE-1; i++) {
        for (int j = 0; j < MAP_SIZE; j++) {
            FireShot(shots, map, i, j);
        }
    }

    PrintArray(shots);

    return 0;
}