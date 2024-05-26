#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#define WIDTH 150
#define HEIGHT 50

char grid[HEIGHT][WIDTH] = {0};
char temp_grid[HEIGHT][WIDTH] = {0};


void clear_screen(){
    for (int i = 0; i < 100; i++) {
        printf("\n");
    }
}

void init_grid(){
    for(int i = 0 ; i < HEIGHT  ; i++) {
        for(int j = 0; j < WIDTH ; j++){
            char random_bit = '0' + (rand() % 2);
            grid[i][j] = random_bit;
        }
    }
}

void print_grid(){
    for(int i = 0; i < HEIGHT ; i++){
        for (int j = 0; j < WIDTH; j++){
            if (grid[i][j] == '0') {
                printf("%c", '-');
            }
            else{
                printf("%c", '#');
            }
        }
        printf("\n");
    }
}

char alive_count(int row, int col) {
    int alive_n = 0;    

    for (int i = -1; i < 2; i++) {
        for (int j = -1; j < 2; j++) {
            if (!(i == 0 && j == 0) && 
                (0 <= i + row && i + row < HEIGHT) && 
                (0 <= j + col && j + col < WIDTH)) {
                alive_n += (grid[i + row][j + col] - '0');
            }
        }
    }

    if (grid[row][col] == '1') {
        if (alive_n == 2 || alive_n == 3) {
            return '1';
        } else {
            return '0';
        }
    } else if (grid[row][col] == '0') {
        if (alive_n == 3) {
            return '1';
        } else {
            return '0';
        }
    }

    return '0';
}

void update(){
    for(int i = 0; i < HEIGHT; i++) {
        for(int j = 0; j < WIDTH; j++) {
            temp_grid[i][j] = alive_count(i, j);
        }
    }

    for(int i = 0; i < HEIGHT; i++) {
        for(int j = 0; j < WIDTH; j++) {
            grid[i][j] = temp_grid[i][j];
        }
    }

    printf("\n");
    print_grid();
    }

int main(){
    srand(time(NULL));
    init_grid();
    print_grid();  

    while (1) {
        usleep(20000);  
        clear_screen();
        update();
    }
    
    return 0;
}