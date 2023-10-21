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

void FireShot(int shots[MAP_SIZE][MAP_SIZE], int map[MAP_SIZE][MAP_SIZE], int row, int col) {

    int shotsShip[4] = {0, 0, 0, 0}; // FIRST TWO VALUES UNUSED
    int shipLengths[4] = {2, 3, 4, 5};
    int map_content = map[row][col];
    int numShots = 0;

    // count unique shots made
    for (int row = 0; row < MAP_SIZE; row++) {
        for (int col = 0; col < MAP_SIZE; col++) {
            

            if (shots[row][col] != 0) {
                numShots += 1;

                if (shots[row][col] != numShots) {
                    shotsShip[map_content - 2] = shotsShip[map_content - 2] + 1;
                }
                

                /*
                if (shots[row][col] > 1000) {
                    
                } 
                */
            } // end of cell scanning

            
            
        } // end of col scanning
    } // end of row scanning
    printf("\n---------------------------\n");
    printf("AAstart of turn\n");
    printf("shotsShip[0]: %d\n", shotsShip[0]);
    printf("shotsShip[1]: %d\n", shotsShip[1]);
    printf("shotsShip[2]: %d\n", shotsShip[2]);
    printf("shotsShip[3]: %d\n\n", shotsShip[3]);
    

    // check that reference block hasn't been shot already
    if (shots[row][col] == 0) {

        // if no ship on this block
        if (map_content == 0) {
            // plot the shot number
            shots[row][col] = numShots + 1;
        }
        else {
            
            shotsShip[map_content - 2] = shotsShip[map_content - 2] + 1;


            // plot the shot number + 1000
            shots[row][col] = (numShots + 1) + 1000;
        }
        
        
        
        
        
    
    } // end of if-statement
    printf("\nZZend of turn\n");
    printf("shotsShip[0]: %d\n", shotsShip[0]);
    printf("shotsShip[1]: %d\n", shotsShip[1]);
    printf("shotsShip[2]: %d\n", shotsShip[2]);
    printf("shotsShip[3]: %d\n\n", shotsShip[3]);
} // end of function


int main(void) {
    
    int map[MAP_SIZE][MAP_SIZE] = {0};
    int shots[MAP_SIZE][MAP_SIZE] = {0};

    InitialiseMap(map);

    printf("Map:\n");
    PrintArray(map);
    printf("Shots 0:\n");
    PrintArray(shots);

    FireShot(shots, map, 0, 0);
    printf("Shots 1:\n");
    PrintArray(shots);

    FireShot(shots, map, 1, 0);
    printf("Shots 2:\n");
    PrintArray(shots);

    FireShot(shots, map, 2, 0);
    printf("Shots 3:\n");
    PrintArray(shots);

    FireShot(shots, map, 3, 0);
    printf("Shots 4:\n");
    PrintArray(shots);

    FireShot(shots, map, 4, 0);
    FireShot(shots, map, 5, 0);
    FireShot(shots, map, 0, 1);
    FireShot(shots, map, 1, 1);
    FireShot(shots, map, 2, 1);
    FireShot(shots, map, 3, 1);
    printf("Shots whole bunch:\n");
    PrintArray(shots);

    return 0;
}