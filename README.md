# Depth First Maze Solver (with Recursive and Backtrack)

In here main goal is to make a *Maze Solver* with Depth first search.

Main.cpp - Include the Solver  
Stack.cpp and Stack.h - Include a custom stack coded for this


Other than that,   
Generated.cpp - contain a maze solver for this (Not compleated one just for test)
Another_method.cpp - Another method solve the Maze using recursive but not exactly the DFS


0 - Path  
1 - Wall  
A - Starting Point  
B - Finish Point  
.# - Output Path

File is Read as a String because there are A and B in the txt.

Code with ❤️ by Thimira Nirmal




Example Output:

1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1  
1 0 B # 1 # # # 1 # # # 1 # # # # # # # 1  
1 0 1 # 1 # 1 # 1 # 1 # 1 # 1 0 1 1 1 # 1  
1 0 1 # 1 # 1 # 1 # 1 # # # 1 0 1 # # # 1  
1 0 1 # 1 # 1 # 1 # 1 1 1 1 1 1 1 # 1 1 1  
1 0 1 # # # 1 # # # 1 0 0 0 0 0 1 # # # 1  
1 0 1 1 1 1 1 1 1 1 1 1 1 1 1 0 1 1 1 # 1  
1 0 0 0 1 0 0 0 0 0 0 0 1 0 0 # # # # # 1  
1 1 1 0 1 0 1 1 1 1 1 1 1 0 1 # 1 1 1 1 1  
1 0 1 0 1 0 0 0 0 0 0 0 1 0 1 # 1 # # # 1  
1 0 1 1 1 0 1 1 1 1 1 0 1 1 1 # 1 # 1 # 1  
1 0 0 0 0 0 1 0 0 0 0 0 0 0 1 # # # 1 # 1  
1 1 1 1 1 0 1 0 1 1 1 1 1 0 1 1 1 1 1 # 1  
1 0 0 0 0 0 1 0 0 0 0 0 1 0 0 0 1 # # # 1  
1 0 1 1 1 1 1 1 1 0 1 0 1 1 1 0 1 # 1 1 1  
1 0 0 0 0 0 0 0 1 0 1 0 1 0 0 0 1 # # # 1  
1 1 1 1 1 1 1 0 1 0 1 0 1 1 1 1 1 0 1 # 1  
1 0 0 0 0 0 0 0 1 0 1 0 1 0 0 0 0 0 1 # 1  
1 0 1 1 1 1 1 1 1 0 1 0 1 1 1 1 1 1 1 # 1  
1 0 1 0 0 0 0 0 0 0 1 # # # # # # # # # 1  
1 1 1 1 1 1 1 1 1 1 1 A 1 1 1 1 1 1 1 1 1   

