#include <iostream>
#include<bits/stdc++.h>
#include <string>
#include <fstream>
#include "windows.h"
#include "Stack.h"

using namespace std;
const int MAXSIZE = 100;
int maze[MAXSIZE][MAXSIZE];

vector < pair<int, int> >  path;//The dynamic array path is used to store the path
vector < pair<int, int> >  stackk;//The dynamic array path is used to store the path

bool flag = true;//Used for recursive end return
int dir[4][2] = {//Direction array
        {- 1, 0},   //Left
        {1, 0},     //Right
        {0, - 1},   //Up
        {0, 1}      //Down
};

Stack s;
Stack visited;
vector <pair<int,int>> adj;

pair<int, int> initial_position;

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

void Depth_first_search(int v,int u){
    bool flag =true;
    while (true) {
        if (s.isEmpty() == true) return;

        if(flag=false) return;

        pair<int, int> current_position;
        current_position = s.pop(); //getting new value from stack

        //Mark new position as visited
        maze[current_position.first][current_position.second] = 1;
        visited.push(current_position);

        int count_dir=0;
        for (auto &direction:dir) {
            cout << "Current position " << current_position.first + direction[0] << " "
                 << current_position.second + direction[1];
            cout << " Value " << maze[current_position.first + direction[0]][current_position.second + direction[1]]
                 << endl;
            if (0 <= current_position.first + direction[0] && current_position.first + direction[0] < 21 &&
                0 <= current_position.second + direction[1] && current_position.second + direction[1] < 21) {

                if (maze[current_position.first+ direction[0]][current_position.second+ direction[1]] == 3) {
                    cout<<"3 detected\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
                    cout<<"3 detected\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
                    cout<<"3 detected\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
                    cout<<"3 detected\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
                    flag= false;

                    for (int i = 0; i < adj.size(); i++) {
                        //for(auto &adj_1:adj){
                        //if(adj_1.first==current_position.first && adj_1.second==current_position.second){
                        cout<<endl<<"Before conditino check\n";
                        cout<<"adj "<<adj[i].first<<" "<<adj[i].second<<endl;
                        cout<<"s "<<s.peek().first<<" "<<s.peek().second<<endl;
                        maze[s.peek().first][s.peek().second]=0;
                        if (adj[i].first == s.peek().first && adj[i].second == s.peek().second) {
                            adj.erase(adj.begin()+i);
                            cout<<"hmm this delete then "<<adj[i].first<<" "<<adj[i].second<<endl;
                            //adj.resize(i+1);
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

                    //print that value
                    pair<int, int> ne_print;
                    ne_print = s.peek();
                    cout << ne_print.first << " " << ne_print.second << endl;
                }
                else{
                    cout<<"Visited one\n";
                    count_dir++;
                }
            }
            else{
                cout<<"Trying to go out\n";
            }
        }

        cout<<"Count "<<count_dir<<endl;
        cout<<"Before deleting in adj "<<s.peek().first<<" "<<s.peek().second<<endl;
        if (count_dir == 4) {
            cout<<"In the counter"<<endl;
            for (int i = 0; i < adj.size(); i++) {
                //for(auto &adj_1:adj){
                //if(adj_1.first==current_position.first && adj_1.second==current_position.second){
                cout<<endl<<"Before conditino check\n";
                cout<<"adj "<<adj[i].first<<" "<<adj[i].second<<endl;
                cout<<"s "<<s.peek().first<<" "<<s.peek().second<<endl;
                if (adj[i].first == s.peek().first && adj[i].second == s.peek().second) {
                    //adj.erase(adj.begin()+i+1);
                    cout<<"hmm this delete then "<<adj[i].first<<" "<<adj[i].second<<endl;
                    adj.resize(i+1);
                }
            }
        }

        int cp=0;
        cout<<adj.back().first<<" "<< adj.back().second<<" "<<s.peek().first<<" "<<s.peek().second<<" "<<endl;
        for(auto &d:adj){

            if(d.first==s.peek().second && d.second==s.peek().first){
                cp++;
            }
        }
        if(cp != 1){
            cout<<"Duplicate found:";
            for(auto &d:adj){
                cout<<d.first<<" "<<d.second<<"\t";
            }
            cout<<endl;
        }
        cout << "\nStack " << s.size() << " \tvisited " << visited.size() << endl;

        //Create copy of array
        int maze_copy[21][21];
        for (int j = 0; j < 21; j++) {
            for (int i = 0; i < 21; i++) {
                maze_copy[i][j] = maze[i][j];
            }
        }

        for (auto &i : adj){
            maze_copy[i.first][i.second]=7;
        }

        for (int j = 0; j < 21; j++) {
            for (int i = 0; i < 21; i++) {
                //cout<<path[i].first<<" "<<path[i].second<< " in "<<i<<" "<<j<<endl;
                if(maze_copy[i][j]==7){
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED);
                    cout<<0<<" ";
                }
                else{
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN);
                    cout<< maze_copy[i][j]<<" ";
                }
            }
            cout<<endl;
        }
    }
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
    for (int j = 0; j < arr_size; j++) {
        for (int i = 0; i < arr_size; i++) {
            maze[i][j] = array[count];
            if(array[count]==2){ //Set intial position
                cout<<endl<<i<<" "<<j<<" This is Initial Position"<<endl;
                x = i;
                y= j;
                initial_position = make_pair(i, j);
            }
            count++;
        }
    }

    //Testing codes
    /*
    cout<<initial_position.first<<" "<<initial_position.second<<endl;

    cout<<endl;

    for (int j = 0; j < arr_size; j++) {
        for (int i = 0; i < arr_size; i++) {
            cout<<i<<","<<j<<" ";
        }
        cout<<endl;
    }

    cout<<endl<<endl;
    for (int j = 0; j < arr_size; j++) {
        for (int i = 0; i < arr_size; i++) {
            cout<<maze[i][j];
        }
        cout<<endl;
    }
    cout<<endl<<endl;

    for (int j = 0; j < arr_size; j++) {
        for (int i = 0; i < arr_size; i++) {
            cout<<i<<","<<j<<" = "<< maze[i][j]<<endl;
        }
        //cout<<endl;
    }

    return 0;*/
    //cout<<current_position.first<<" "<<current_position.second<<endl;
    //cout<<maze[current_position.first][current_position.second];

    //Create copy of array
    int maze_copy[arr_size][arr_size];
    for (int j = 0; j < arr_size; j++) {
        for (int i = 0; i < arr_size; i++) {
            maze_copy[i][j] = maze[i][j];
        }
    }

    //cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n";
    //Intialize empty stack of size 1000
    //all 0
    //push first node
    //visit vertex s
    //mark s as visited
    //visit to next unvisited s

    //We have maze now
    //Copy of maze for print

    for (int j = 0; j < arr_size; j++) {
        for (int i = 0; i < arr_size; i++) {
            cout<<maze[i][j]<<" ";
        }cout<<endl;
    }
    cout<<endl;






    //Inside function
    //First value
    s.push(initial_position);
    adj.push_back(initial_position);
    visited.push(initial_position);

    //Mark as visited
    maze[initial_position.first][initial_position.second]=1;

    cout << "Is empty " << s.size() << endl;
    cout << endl << "Hi" << endl;

    cout<<"Initial Position "<<initial_position.first<<" "<<initial_position.second<<endl<<endl;

    Depth_first_search(initial_position.first,initial_position.second);


    cout<<endl<<"Hi"<<endl;

    pair<int, int> new_position;
    new_position=s.pop();
    cout<<new_position.first<<"  "<<new_position.second;

    cout<<endl;
    pair<int, int> ne_position;
    ne_position=visited.pop();
    ne_position=visited.pop();
    cout<<ne_position.first<<"  "<<ne_position.second;

    //Print the result
    //printf("Steps: %d\n", visited.size());
    //printf("Path:\n");
    //for (int i = 0; i < path.size(); i++) {
      //  printf("%d %d\n", path[i].first, path[i].second);
    //}

    cout<<endl<<"Lets print the maze"<<endl;

    int cp=0;

    while (visited.isEmpty()){
        pair<int, int> position;
        position=visited.pop();
        cout<<position.first<<" "<<position.second<<endl;
        maze[position.first][position.second]=7;
    }

    cout<<endl<<endl;

    for (auto &i : adj){
        maze_copy[i.first][i.second]=7;
    }

    cout<<"duplicates"<<endl;
    // Create a map to store the frequency of each element in vector


    std::map<pair<int,int>, int> countMap;
// Iterate over the vector and store the frequency of each element in map
    for (auto & elem : adj)
    {
        auto result = countMap.insert(pair<pair<int,int>, int>(elem, 1));
        if (result.second == false)
            result.first->second++;
    }

    // Iterate over the map
    for (auto & elem : countMap)
    {
        // If frequency count is greater than 1 then its a duplicate element
        if (elem.second > 1)
        {
            std::cout << elem.first.first<<" "<<elem.first.second<<" " << " :: " << elem.second << std::endl;
        }
    }

    for (int j = 0; j < arr_size; j++) {
        for (int i = 0; i < arr_size; i++) {
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
    cout<<endl<<endl;
    for (int j = 0; j < arr_size; j++) {
        for (int i = 0; i < arr_size; i++) {
            //cout<<path[i].first<<" "<<path[i].second<< " in "<<i<<" "<<j<<endl;
            if(maze[i][j]==0){
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED);
                cout<<0<<" ";
            }
            else{
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN);
                cout<< maze[i][j]<<" ";
            }
            cp++;
        }
        cout<<endl;
    }

    /*
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
    for (int j = 0; j < arr_size; j++) {
        for (int i = 0; i < arr_size; i++) {
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
    for (int j = 0; j < arr_size; j++) {
        for (int i = 0; i < arr_size; i++) {
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
    cout<<endl<<endl;
    for(int i =0; i<arr_size;i++){
        for(int j =0; j<arr_size;j++){
            //cout<<path[i].first<<" "<<path[i].second<< " in "<<i<<" "<<j<<endl;
            if(maze[i][j]==0){
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED);
                cout<<0<<" ";
            }
            else{
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN);
                cout<< maze[i][j]<<" ";
            }
            cp++;
        }
        cout<<endl;
    }

    Stack d1;
    d1.push(1);
    d1.push(2);

    cout<<d1.pop()<<endl;
    cout<<d1.peek();
     */

    cout<<"\n\n\n"<<adj.size();

    cout<<endl;

    for(auto &fg:adj){
        cout<<fg.first<<" "<<fg.second<<endl;
    }
    return 0;
}

//Use 2 2
//Take 4 directions select one & take others to array
//right cell dekak issarhin nathi cell ekak thynid balala
