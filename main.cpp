/********************************************************************************
 * Name             : Nirmal L.Y.T.
 * Index No         : 19/ENG/072
 * Registration No  : EN93921
*********************************************************************************/

////// Note that this is made with Depth first search with Recursive and Backtrack

#include <iostream>
#include<bits/stdc++.h>
#include <string>
#include <fstream>
#include "windows.h"
#include "Stack.h"

#include "Another_Method.h"
#include "Generator.h"

using namespace std;
const int MAXSIZE = 100;
int maze[MAXSIZE][MAXSIZE];
int arr_size;

//Used for recursive end return
int dir[4][2] = {//Direction array
        {-1, 0},   //Left
        {1,  0},     //Right
        {0,  -1},   //Up
        {0,  1}      //Down
};

Stack s;    //Save stack
vector<pair<int, int>> adj;     //Adj

pair<int, int> initial_position;


void DFS(pair<int, int> position) {
    if (s.isEmpty()) return;
    if (s.size() == -1) return;

    //Mark new position as visited
    maze[position.first][position.second] = 1;
    int random[4] = {4,3,2,1};

    int count_dir = 0;

    random_shuffle(&random[0], &random[4]);
    for (int i=0; i<4; i++) {
        if (0 <= position.first + dir[i][0] && position.first + dir[i][0] < arr_size &&
            0 <= position.second + dir[i][1] && position.second + dir[i][1] < arr_size) {
            if (maze[position.first + dir[i][0]][position.second + dir[i][1]] == 3) {
                for (int j = s.size(); j > 0; j--) {
                    //while(true){
                    if (s.size() == -1) break;
                    for (int i = 0; i < adj.size(); i++) {
                        if (adj[i].first == s.peek().first && adj[i].second == s.peek().second) {
                            adj.erase(adj.begin() + i);
                            s.pop();
                        }
                    }
                }
                return;
            }
            if (maze[position.first + dir[i][0]][position.second + dir[i][1]] == 0) {
                //adjecent
                pair<int, int> temp_pair = make_pair(position.first + dir[i][0],
                                                     position.second + dir[i][1]);
                adj.push_back(temp_pair);
                s.push(temp_pair);      //Adjecent value to stack
            } else {
                count_dir++;
            }
        }
    }

    if (count_dir == 4) {
        for (int i = 0; i < adj.size(); i++) {
            if (adj[i].first == s.peek().first && adj[i].second == s.peek().second) {
                adj.resize(i + 1);
            }
        }
    }

    DFS(s.pop());
}

int main() {
    Generator obj_gen;

    cout<<endl;

    string array[5000];
    int count = 0;

    ifstream file("C:\\Users\\timni\\CLionProjects\\untitled7\\cmake-build-debug\\Generate.txt");

    if (!file)
        cout << "File not Found";
    while (!file.eof()) {
        file >> array[count];
        //Add the number to the end of the array
        count++;
    }

    arr_size = sqrt(count);
    count = 0;
    for (int j = 0; j < arr_size; j++) {
        for (int i = 0; i < arr_size; i++) {
            if (array[count] == "A") { //Set intial position
                initial_position = make_pair(i, j);
                maze[i][j] = 2;
            } else if (array[count] == "B") {
                maze[i][j] = 3;
            } else {
                maze[i][j] = stoi(array[count]);
            }
            count++;
        }
    }

    //Create copy of array
    int maze_copy[arr_size][arr_size];
    for (int j = 0; j < arr_size; j++) {
        for (int i = 0; i < arr_size; i++) {
            maze_copy[i][j] = maze[i][j];
        }
    }

    //Inside function
    //First value
    s.push(initial_position);

    //Mark as visited
    maze[initial_position.first][initial_position.second] = 1;

    DFS(initial_position);

    //Mark path in Maze_copy using 7
    for (auto &i : adj) {
        maze_copy[i.first][i.second] = 7;
    }

    //Print Maze
    for (int j = 0; j < arr_size; j++) {
        for (int i = 0; i < arr_size; i++) {
            if (maze_copy[i][j] == 7) {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED);
                cout << "# ";
            } else if (maze_copy[i][j] == 2) {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_BLUE);
                cout << "A ";
            } else if (maze_copy[i][j] == 3) {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_BLUE);
                cout << "B ";
            } else {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN);
                cout << maze_copy[i][j] << " ";
            }
        }
        cout << endl;
    }

    cout<<endl<<"By using Another_method.\n";
    cout<<"Note that this is not purly Depth First Search as Above.\n";
    cout<<"Code in Main.cpp or purly Depth First Search Algorithm with recursive and Backtracking\n\n";

    Another_Method obj;

    return 0;
}