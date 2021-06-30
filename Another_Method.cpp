#include <iostream>
#include<bits/stdc++.h>
#include <cstdio>
#include <string>
#include "windows.h"
#include "Another_Method.h"

using namespace std;

vector < pair<int, int> >  path;//The dynamic array path is used to store the path
vector < pair<int, int> >  stackk;//The dynamic array path is used to store the path

const int maxsize = 100;
int maze_another[maxsize][maxsize];

bool flag = true;//Used for recursive end return
int dir_another[4][2] = {//Direction array
        {- 1, 0},   //Up
        {1, 0},     //Down
        {0, - 1},   //Left
        {0, 1}      //Right
};

void D_F_S(int x,int y){
    if(!flag) return;
    if(maze_another[y][x] == 3){
        path.push_back(make_pair(y,x));
        flag = false;
        return;
    }
    if(maze_another[y][x] == 1) return;
    //The above judgment statement detects whether it reaches the end of the recursion

    maze_another[y][x] = 1;//Mark has been visited
    path.push_back(make_pair(y,x));//Add this vertex to the path
    for(int i = 0; i < 4 && flag; i++){//Continue recursive search in four directions
        D_F_S(x + dir_another[i][0], y + dir_another[i][1]);
    }
    if(flag) path.pop_back();//Exit the path if this vertex is not found
}

Another_Method::Another_Method()
{
    int x, y;
    int m, n;

    string array[5000];
    int count = 0;

    ifstream file("C:\\Users\\timni\\CLionProjects\\untitled7\\cmake-build-debug\\Generate.txt");

    if(!file )
        cout<<"File not Found";
    while (!file.eof()) {
        file >> array[count];
        //Add the number to the end of the array
        count++;
    }

    int arr_size = sqrt(count);
    count = 0;
    for (int i = 0; i < arr_size; i++) {
        for (int j = 0; j < arr_size; j++) {
            if (array[count] == "A") { //Set intial position
                x = i;
                y = j;
                maze_another[i][j] = 2;
            } else if (array[count] == "B") {
                maze_another[i][j] = 3;
                m = i;
                n = j;
            } else {
                maze_another[i][j] = stoi(array[count]);
            }
            count++;
        }
    }

    //Create copy of array
    int maze_copy[arr_size][arr_size];
    for (int i = 0; i < arr_size; i++) {
        for (int j = 0; j < arr_size; j++) {
            maze_copy[i][j] = maze_another[i][j];
        }
    }


    path.push_back( make_pair(x,y) );
    stackk.push_back( make_pair(x,y));

//Function
    int nLoopCount=0;

    while (true)
    {
        //termination condition
        if(nLoopCount==3){
            cout<<"\nFound";
            cout<<" at "<<x<<" "<<y<<endl<<endl;
            break;
        }

        for (int d=0; d<4; d++){
            D_F_S(y + dir_another[d][0], x + dir_another[d][1]); //Send each value to Depth first search with direction
        }
        nLoopCount++;

    }


    //Print the result
    printf("Steps: %d\n", path.size());
    printf("Path:\n");
    for (int i = 0; i < path.size(); i++) {
        printf("%d %d\n", path[i].first, path[i].second);
    }

    cout<<endl<<"Lets print the maze"<<endl;

    int cp=0;
    for (auto &i : path){
        maze_copy[i.first][i.second]=7;
    }

    maze_copy[x][y]=2;
    maze_copy[m][n]=3;

    cout<<endl<<endl;
    for(int i =0; i<arr_size;i++){
        for(int j =0; j<arr_size;j++){
            //cout<<path[i].first<<" "<<path[i].second<< " in "<<i<<" "<<j<<endl;
            if(maze_copy[i][j]==7){
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED);
                cout<<"# ";
            }else if (maze_copy[i][j] == 2) {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_BLUE);
                cout << "A ";
            } else if (maze_copy[i][j] == 3) {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_BLUE);
                cout << "B ";
            }
            else{
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN);
                cout<< maze_copy[i][j]<<" ";
            }
            cp++;
        }
        cout<<endl;
    }
}
