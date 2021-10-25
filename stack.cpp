#include <bits/stdc++.h>
#include <math.h>
#include <vector>

using namespace std;

class Stack
{
    int size;
    int st[30000];

public:
    Stack()
    {
        size = 0;
    }

    void push(int val)
    {
        st[size++] = val;
    }

    void pop()
    {
        size--;
    }

    int top()
    {
        return st[size - 1];
    }

    int getSize()
    {
        return size;
    }
};

class MinStack
{
    Stack stack;
    Stack min;

public:
    MinStack()
    {
    }

    void push(int val)
    {
        if (stack.getSize() == 0)
        {
            stack.push(val);
            min.push(val);

            return;
        }

        stack.push(val);

        int top = min.top();

        if (top < val)
            min.push(top);

        else
            min.push(val);
    }

    void pop()
    {
        stack.pop();
        min.pop();
    }

    int top()
    {
        return stack.top();
    }

    int getMin()
    {
        return min.top();
    }
};

int main()
{

    return 0;
}