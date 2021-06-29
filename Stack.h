//
// Created by timni on 6/29/2021.
//

#ifndef UNTITLED3_STACK_H
#define UNTITLED3_STACK_H

#define MAX 1000
#include <vector>
using namespace std;

class Stack {
private:
    int top;
public:
    pair<int, int> a[MAX]; // Maximum size of Stack

    Stack() { top = -1; }
    bool push(pair<int, int> stack_pair);
    pair<int, int> pop();
    pair<int, int> peek();
    bool isEmpty();

    int size();
};


#endif //UNTITLED3_STACK_H
