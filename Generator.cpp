#include "Generator.h"
/*
 0 - Path
 1 - Wall
 A - Starting Point
 B - Finish Point
*/

#include<iostream>
#include <algorithm>
#include "windows.h"
#include <fstream>
#include <time.h>

using namespace std;

const int maze_size_main = 21;
const int width = maze_size_main;
const int height = maze_size_main;

int random[4] = {1, 2, 3, 4};
int maze_gen[width][height];

int mark_x = 0, mark_y = 0;

ofstream Generate("Generate.txt", ios::trunc);

void Print_Maze() {
    for (int i = 0; i < width; i++) {
        for (int j = 0; j < height; j++) {
            if (maze_gen[i][j] == 0) {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED);
                cout << maze_gen[i][j] << " ";
            } else if (maze_gen[i][j] == 2) {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_BLUE);
                cout << "A ";
            } else if (maze_gen[i][j] == 3) {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_BLUE);
                cout << "B ";
            } else {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN);
                cout << maze_gen[i][j] << " ";
            }
        }
        cout << endl;
    }
}

void Print_Maze_file() {
    for (int i = 0; i < width; i++) {
        for (int j = 0; j < height; j++) {
            if (maze_gen[i][j] == 2) {
                Generate << "A ";
            } else if (maze_gen[i][j] == 3) {
                Generate << "B ";
            } else {
                Generate << maze_gen[i][j] << " ";
            }
        }
        Generate << endl;
    }
}

void recursion(int x, int y) {

    // 4 random directions
    random_shuffle(&random[0], &random[4]);
    // Examine each direction
    for (int i = 0; i < 4; i++) {
        switch (random[i]) {
            case 1: // Up
                //　Whether 2 cells up is out or not
                if (x - 2 <= 0)
                    continue;
                if (maze_gen[x - 2][y] != 0) {
                    maze_gen[x - 2][y] = 0;
                    maze_gen[x - 1][y] = 0;
                    mark_x = x - 2;
                    mark_y = y;
                    recursion(x - 2, y);
                }
                break;
            case 2: // Right
                // Whether 2 cells to the right is out or not
                if (y + 2 >= width - 1)
                    continue;
                if (maze_gen[x][y + 2] != 0) {
                    maze_gen[x][y + 2] = 0;
                    maze_gen[x][y + 1] = 0;
                    mark_x = x;
                    mark_y = y + 2;
                    recursion(x, y + 2);
                }
                break;
            case 3: // Down
                // Whether 2 cells down is out or not
                if (x + 2 >= height - 1)
                    continue;
                if (maze_gen[x + 2][y] != 0) {
                    maze_gen[x + 2][y] = 0;
                    maze_gen[x + 1][y] = 0;
                    mark_x = x + 2;
                    mark_y = y;
                    recursion(x + 2, y);
                }
                break;
            case 4: // Left
                // Whether 2 cells to the left is out or not
                if (y - 2 <= 0)
                    continue;
                if (maze_gen[x][y - 2] != 0) {
                    maze_gen[x][y - 2] = 0;
                    maze_gen[x][y - 1] = 0;
                    mark_x = x;
                    mark_y = y - 2;
                    recursion(x, y - 2);
                }
                break;
        }
    }
}

Generator::Generator() {
    for (int i = 0; i < width; i++) {
        for (int j = 0; j < height; j++) {
            maze_gen[i][j] = 1;
        }
    }
    srand(time(0));

    int rand_x = rand() % width-1;
    int rand_y = rand() % height-1;
    maze_gen[rand_x][rand_y] = 2;

    recursion(rand_x, rand_y);
    maze_gen[rand_x][rand_y] = 2;
    maze_gen[mark_x][mark_y] = 3;
    Print_Maze();
    Print_Maze_file();


    void close();
}

