#include <iostream>
#include<bits/stdc++.h>
#include <cstdio>
#include <string>
#include <fstream>
#include "windows.h"

using namespace std;
const int MAXSIZE = 100;
int maze[MAXSIZE][MAXSIZE];

vector < pair<int, int> >  path;//The dynamic array path is used to store the path
vector < pair<int, int> >  stackk;//The dynamic array path is used to store the path

bool flag = true;//Used for recursive end return
int dir[4][2] = {//Direction array
        {- 1, 0},   //Up
        {1, 0},     //Down
        {0, - 1},   //Left
        {0, 1}      //Right
};

void print_maze(){
    cout<<endl<<endl;
    for(int i=0; i<10;i++){
        for(int j =0; j<10;j++){
            cout<<maze[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl<<endl;
}
void print_maze(int n){
    cout<<endl<<endl;
    for(int i=0; i<n;i++){
        for(int j =0; j<n;j++){
            cout<<maze[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl<<endl;
}

void DFS(int x, int y){
    cout<<"Yes";
    if(!flag) return;   //Function will be terminated if flag false (End found) (Not sure)

    if(maze[y][x] == 3){    //Found 3
        path.push_back(make_pair(y,x));
        flag = false;
        return;
    }
    if(maze[y][x] == 1) return;
    //The above judgment statement detects whether it reaches the end of the recursion

    maze[y][x] = 1;//Mark has been visited
    path.push_back(make_pair(y,x));//Add this vertex to the path
    for(int i = 0; i < 4 && flag; i++){//Continue recursive search in four directions
        DFS(y + dir[i][0], x + dir[i][1]);
    }
    if(flag) path.pop_back();//Exit the path if this vertex is not found
}

void DF_search(int x, int y){
    //cout<<"OK 200<<endl";
    if(!flag) return;
    if(maze[x][y]==3){
        cout<<"\nFound";
        cout<<" at "<<x<<" "<<y<<endl<<endl;
        return;
    }
    if(maze[y][x] == 1) return; //If visited or wall found

    maze[y][x] = 1;//Mark has been visited

    maze[y][x] = 1;//Mark has been visited

    //cout<<"hey";
    path.push_back(make_pair(x,y));//Add this vertex to the path
    stackk.push_back(make_pair(x,y));

    for(int i = 0; i < 4 && flag; i++){//Continue recursive search in four directions
        //cout<<"\nSending "<<x<<" in direction "<<dir[i][0]<<" and "<<y<<" in direction "<<dir[i][1];
        cout<<" (x,y) "<<x+dir[i][0]<<" "<<y+dir[i][1];
        DF_search(x + dir[i][0], y + dir[i][1]);
    }
    if(flag) stackk.pop_back();//Exit the path if this vertex is not found
}

void D_F_S(int x,int y){
    if(!flag) return;
    if(maze[y][x] == 3){
        path.push_back(make_pair(y,x));
        flag = false;
        return;
    }
    if(maze[y][x] == 1) return;
    //The above judgment statement detects whether it reaches the end of the recursion

    maze[y][x] = 1;//Mark has been visited
    path.push_back(make_pair(y,x));//Add this vertex to the path
    for(int i = 0; i < 4 && flag; i++){//Continue recursive search in four directions
        D_F_S(x + dir[i][0], y + dir[i][1]);
    }
    if(flag) path.pop_back();//Exit the path if this vertex is not found
}

int main(int argc, char const *argv[])
{
    int n, m;
    int x, y;

    int array[1000];
    int count = 0;

    ifstream file("C:\\Users\\timni\\CLionProjects\\untitled3\\Generated.txt");

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
            maze[i][j] = array[count];
            if(array[count]==2){ //Set intial position
                cout<<endl<<i<<" "<<j<<" This is i j"<<endl;
                x = i;
                y= j;
            }
            count++;
        }
    }

    //Create copy of array
    int maze_copy[arr_size][arr_size];
    for (int i = 0; i < arr_size; i++) {
        for (int j = 0; j < arr_size; j++) {
            maze_copy[i][j] = maze[i][j];
        }
    }

    //Send intial position to stack
    //stackk.push_back(make_pair(x,y));
    //path.push_back(make_pair(x,y)); //mark as visited

    //DF_S{

    path.push_back( make_pair(x,y) );
    stackk.push_back( make_pair(x,y));

    //cout << path[0].first << " " << path[0].second << endl;
    //cout << path[0].first << " " << path[0].second << endl;
    //cout<<endl<<path.back().first<<" "<<path.back().second;

//Function
    int nLoopCount=0;

    while (true)
    {
        //if (maze[path.back().first][path.back().second] == 3) {   //termination condition
        if(nLoopCount==3){
            cout<<"\nFound";
            cout<<" at "<<x<<" "<<y<<endl<<endl;
            break;
        }
        //Functions here
        //Add adjecent items to stack
        //Need to calculate with directions
        //In here I assumed that there is wall around maze and enterece is made from there.
        cout<<"About to enter the directions.\n";
        for (int d=0; d<4; d++){
            //if(x+dir[d][0] == 0) {
            //cout<<"\nSending "<<x<<" in direction "<<dir[d][0]<<" and "<<y<<" in direction "<<dir[d][1];
            cout<<"Number from main : ";
            cout<<" (x,y) "<<x+dir[d][0]<<" "<<y+dir[d][1]<<endl;
            D_F_S(y + dir[d][0], x + dir[d][1]); //Send each value to Depth first search with direction
            //cout<<" (x,y) "<<x+dir[d][0]<<" "<<y+dir[d][1];
            //cout << "\nSend retunred";
            //}
        }
        //cout<<endl<<path.back().first<<" "<<path.back().second;
        nLoopCount++;

    }

    //cout<<"Not Found.\n";
    cout<< "Stoped at "<<x<<" "<<y<<endl<<endl;


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

    cout<<endl<<endl;
    for(int i =0; i<arr_size;i++){
        for(int j =0; j<arr_size;j++){
            //cout<<path[i].first<<" "<<path[i].second<< " in "<<i<<" "<<j<<endl;
            if(maze_copy[i][j]==7){
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED);
                cout<<"# ";
            }
            else{
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN);
                cout<< maze_copy[i][j]<<" ";
            }
            cp++;
        }
        cout<<endl;
    }
    return 0;
}

//Use 2 2
//Take 4 directions select one & take others to array
//right cell dekak issarhin nathi cell ekak thynid balala
