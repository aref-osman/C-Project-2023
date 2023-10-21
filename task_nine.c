#include <stdio.h>
#define MAP_SIZE 7

int CheckGameOver(int shots[MAP_SIZE][MAP_SIZE], int map[MAP_SIZE][MAP_SIZE]) {

    for (int row = 0; row < MAP_SIZE; row++) {
        for (int col = 0; col < MAP_SIZE; col++) {
            
            // if there is a ship block
            if (map[row][col] != 0) {
                // check to see matching 'shots' array element is not 0
                // assuming all shots are correct, if there's shots on every ship block, then it should be game over

                // if any ship blocks are undestroyed
                if (shots[row][col] == 0) {
                    // game not over, return 0 (false)
                    return 0;
                }
            }
            

        }
    }
    
    return 1;

}

int main(void) {
    
    int map[MAP_SIZE][MAP_SIZE] = {
    {0, 4, 4, 4, 4, 0, 6},
    {5, 0, 0, 0, 0, 0, 6},
    {5, 0, 0, 0, 0, 0, 6},
    {5, 0, 0, 0, 0, 0, 6},
    {5, 0, 3, 3, 3, 0, 6},
    {5, 0, 0, 0, 0, 0, 6},
    {0, 0, 2, 2, 0, 0, 0}
    };
    int shots[MAP_SIZE][MAP_SIZE] = {
    {36, 4033, 4029, 4009, 4043, 19, 1013},
    {5023, 8, 11, 5, 25, 12, 1002},
    {5017, 10, 26, 41, 47, 40, 1035},
    {5031, 44, 1, 6, 30, 27, 1021},
    {5020, 3, 3028, 3022, 3038, 45, 0},
    {5015, 46, 24, 18, 32, 34, 1014},
    {4, 0, 2037, 2007, 39, 42, 16}
    };
    printf("Game over? %d\n", CheckGameOver(shots, map));


    return 0;
}