#include<bits/stdc++.h>
using namespace std;
const int MAXSIZE = 100;
int maze[MAXSIZE][MAXSIZE];
vector< pair<int, int> >  path;//The dynamic array path is used to store the path
bool flag = true;//Used for recursive end return
int dir[4][2] = {//Direction array
        {- 1, 0},
        {1, 0},
        {0, - 1},
        {0, 1}
};


void DFS(int y, int x){
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
        DFS(y + dir[i][0], x + dir[i][1]);
    }
    if(flag) path.pop_back();//Exit the path if this vertex is not found
}

int main(int argc, char const *argv[])
{
    int n, m;
    int x, y;
    if(argc == 1)
    {
        argv[1] = "C:\\Users\\timni\\CLionProjects\\untitled3\\Generated.txt";
    }
    freopen(argv[1],"r", stdin);
    while(~scanf("%d%d", &n, &m)){
        for(int i = 0; i <= n + 1; i++)
            maze[0][i] = maze[m + 1][i] = 1;
        for(int i = 0; i <= m + 1; i++)
            maze[i][0] = maze[i][n + 1] = 1;

        for(int i = 1; i <= m; i++)
            for(int j = 1; j <= n; j++){
                scanf("%d", &maze[i][j]);
                if(maze[i][j] == 2){
                    x = j;
                    y = i;
                }
            }//Enter data and set the end point
        path.push_back(make_pair(y,x));
        for(int i = 0; i < 4; i++){
            DFS(y + dir[i][0], x + dir[i][1]);//Search in four directions recursively
        }
        //Print the result
        printf("Steps: %d\n",path.size());
        printf("Path:\n");
        for(int i = 0; i < path.size(); i++)
            printf("%d %d\n", path[i].first, path[i].second);
    }
    return 0;
}
