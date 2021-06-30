#include <iostream>
#include<bits/stdc++.h>
#include <string>
#include <fstream>
#include "windows.h"
#include "Stack.h"

using namespace std;
const int MAXSIZE = 100;
int maze[MAXSIZE][MAXSIZE];

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

void Depth_first_search() {
    while (true) {
        if (s.isEmpty()) return;

        pair<int, int> current_position;
        current_position = s.pop(); //getting new value from stack

        //Mark new position as visited
        maze[current_position.first][current_position.second] = 1;

        int count_dir = 0;
        for (auto &direction:dir) {
            if (0 <= current_position.first + direction[0] && current_position.first + direction[0] < 21 &&
                0 <= current_position.second + direction[1] && current_position.second + direction[1] < 21) {
                if (maze[current_position.first + direction[0]][current_position.second + direction[1]] == 3) {

                    while(true){
                        cout<<s.size()<<endl;
                        if(s.size()==-1) break;
                        for (int i = 0; i < adj.size(); i++) {
                            if (adj[i].first == s.peek().first && adj[i].second == s.peek().second) {
                                adj.erase(adj.begin() + i);
                                s.pop();
                            }
                        }

                    }
                    return;
                }
                if (maze[current_position.first + direction[0]][current_position.second + direction[1]] == 0) {
                    //adjecent
                    pair<int, int> temp_pair = make_pair(current_position.first + direction[0],
                                                         current_position.second + direction[1]);
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

        int cp = 0;
        for (auto &d:adj) {
            if (d.first == s.peek().second && d.second == s.peek().first) {
                cp++;
            }
        }

        //Create copy of array
        int maze_copy[21][21];
        for (int j = 0; j < 21; j++) {
            for (int i = 0; i < 21; i++) {
                maze_copy[i][j] = maze[i][j];
            }
        }
    }
}


void Depth_first_search(pair <int,int> position) {
cout<<"New position "<<" "<<position.first<<" "<<position.second<<" Stack Size "<<s.size()<<endl;
        //if (s.isEmpty()) return;
        //if (s.size()==-1) return;

    if (s.isEmpty()) {
        cout<<"\nEmpyt\n";
        return;
    };
    if (s.size()==-1) {
        cout<<"\nSize -1\n";
    };

    pair<int, int> current_position;
        current_position = position; //getting new value from stack

        //Mark new position as visited
        maze[current_position.first][current_position.second] = 1;

        int count_dir = 0;
        for (auto &direction:dir) {
            if (0 <= current_position.first + direction[0] && current_position.first + direction[0] < 21 &&
                0 <= current_position.second + direction[1] && current_position.second + direction[1] < 21) {
                if (maze[current_position.first + direction[0]][current_position.second + direction[1]] == 3) {

                    cout<<"\n\nFound\n\n";

                    for(int j=s.size(); j > 0; j--){
                    //while(true){
                    cout<<s.size()<<endl;
                        if(s.size()==-1) break;
                        for (int i = 0; i < adj.size(); i++) {
                            if (adj[i].first == s.peek().first && adj[i].second == s.peek().second) {
                                adj.erase(adj.begin() + i);
                                s.pop();
                            }
                        }
                    }
                    cout<<endl;
                    return;
                }
                if (maze[current_position.first + direction[0]][current_position.second + direction[1]] == 0) {
                    //adjecent
                    pair<int, int> temp_pair = make_pair(current_position.first + direction[0],
                                                         current_position.second + direction[1]);
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

    int array[1000];
    int count = 0;

    ifstream file("C:\\Users\\timni\\CLionProjects\\untitled3\\Generated.txt");

    if (!file)
        cout << "File not Found";
    while (!file.eof()) {
        file >> array[count];
        //Add the number to the end of the array
        count++;
    }

    int arr_size = sqrt(count);
    count = 0;
    for (int j = 0; j < arr_size; j++) {
        for (int i = 0; i < arr_size; i++) {
            maze[i][j] = array[count];
            if (array[count] == 2) { //Set intial position
                initial_position = make_pair(i, j);
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

    //Intialize empty stack of size 1000
    //all 0
    //push first node
    //visit vertex s
    //mark s as visited
    //visit to next unvisited s


    //Inside function
    //First value
    s.push(initial_position);

    //Mark as visited
    maze[initial_position.first][initial_position.second] = 1;

    //Depth_first_search();
    DFS(initial_position);

    cout<<"1\n\n\nIm here\n";
    for (auto &i : adj) {
        maze_copy[i.first][i.second] = 7;
    }

    for (int j = 0; j < arr_size; j++) {
        for (int i = 0; i < arr_size; i++) {
            if (maze_copy[i][j] == 7) {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED);
                cout << "# ";
            }else if (maze_copy[i][j] == 2) {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_BLUE);
                cout << "A ";
            }
            else if (maze_copy[i][j] == 3) {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_BLUE);
                cout << "B ";
            }
            else {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN);
                cout << maze_copy[i][j] << " ";
            }
        }
        cout << endl;
    }

    return 0;
}

//Use 2 2
//Take 4 directions select one & take others to array
//right cell dekak issarhin nathi cell ekak thynid balala
