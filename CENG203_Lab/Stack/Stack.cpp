#include "Stack.h"
#include <iostream>
using namespace std;

Stack::Stack()
{
    top = nullptr;
    count = 0;
}

Stack::~Stack()
{
    clear();
}

void Stack::push(int value)
{
    Node* newNode = new Node;       // 1) allocate
    newNode->data = value;          // 2) set data
    newNode->next = top;            // 3) point to the old top
    top = newNode;                  // 4) new node becomes the top
    count++;
}

bool Stack::pop(int& value)
{
    if (top == nullptr)             // underflow
        return false;
    value = top->data;              // give the value back
    Node* temp = top;
    top = top->next;                // move top down
    delete temp;                    // free the node
    count--;
    return true;
}

bool Stack::peek(int& value) const
{
    if (top == nullptr)
        return false;
    value = top->data;              // read only: nothing is removed
    return true;
}

bool Stack::isEmpty() const
{
    return top == nullptr;
}

int Stack::size() const
{
    return count;
}

void Stack::clear()
{
    int value;
    while (pop(value))
        ;
}

void Stack::display() const
{
    cout << "top ->";
    if (top == nullptr)
        cout << " (empty)";
    for (Node* cur = top; cur != nullptr; cur = cur->next)
        cout << " " << cur->data;
    cout << endl;
}