/* C++ program to implement basic stack
   operations */
#include <bits/stdc++.h>
#include "Stack.h"
#include <vector>

using namespace std;


bool Stack::push(pair<int, int> stack_pair)
{
    if (top >= (MAX - 1)) {
        cout << "Stack Overflow";
        return false;
    }
    else {
        //pair<int, int> stack_pair;
        //stack_pair=make_pair(x,y);
        a[++top] = stack_pair;
        //cout << x << " pushed into stack\n";
        return true;
    }
}

pair<int, int> Stack::pop()
{
    if (top < 0) {
        cout << "Stack Underflow";
        //return;
    }
    else {
        pair<int, int> stack_pair;
        stack_pair=a[top--];
        return stack_pair;
    }
}

pair<int, int> Stack::peek()
{
    if (top < 0) {
        //cout << "Stack is Empty";
        //return 0;
    }
    else {
        pair<int, int> stack_pair;
        stack_pair= a[top];
        return stack_pair;
    }
}

bool Stack::isEmpty()
{
    return (top < 0);
}

int Stack::size(){
    return top;
}
