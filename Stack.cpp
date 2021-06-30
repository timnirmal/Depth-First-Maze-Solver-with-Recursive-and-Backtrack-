#include <bits/stdc++.h>
#include "Stack.h"
#include <vector>

using namespace std;

bool Stack::push(pair<int, int> stack_pair) {
    if (top >= (MAX - 1)) {
        cout << "Stack Overflow";
        return false;
    } else {
        a[++top] = stack_pair;
        return true;
    }
}

pair<int, int> Stack::pop() {
    pair<int, int> stack_pair;
    stack_pair = a[top--];
    return stack_pair;
}

pair<int, int> Stack::peek() {
    pair<int, int> stack_pair;
    stack_pair = a[top];
    return stack_pair;
}

bool Stack::isEmpty() {
    return (top < 0);
}

int Stack::size() {
    return top;
}
