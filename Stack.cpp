#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int top = -1;
const int size = 10;
int arr[size];

void push(int element)
{
    if (top == size - 1){
         cout << "Stack was Full !"; 
        return;
    }

    else
    {

        top++;
        arr[top] = element;
    }
}

int pop()
{

    top--;
    return arr[top + 1];
}

void display()
{

    for (int i = top; i >= 0; i--)
    {
        cout << arr[i] << " ";
    }
}

int main()
{

    push(10);
    push(20);
    push(30);
    push(40);
    push(50);
   
          
    pop();

    display();
}