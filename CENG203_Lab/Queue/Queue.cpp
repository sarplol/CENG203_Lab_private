#include "Queue.h"
#include <iostream>
using namespace std;

Queue::Queue()
{
    front = nullptr;
    rear = nullptr;
    count = 0;
}

Queue::~Queue()
{
    int value;
    while (dequeue(value))          // dequeue until the queue is empty
        ;
}

void Queue::enqueue(int value)
{
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = nullptr;        // the new node is the last one
    if (rear == nullptr) {          // empty queue: front and rear are the same node
        front = newNode;
        rear = newNode;
    } else {
        rear->next = newNode;       // link behind the old rear
        rear = newNode;
    }
    count++;
}

bool Queue::dequeue(int& value)
{
    if (front == nullptr)           // underflow
        return false;
    value = front->data;
    Node* temp = front;
    front = front->next;
    if (front == nullptr)           // queue became empty: rear must be reset too
        rear = nullptr;
    delete temp;
    count--;
    return true;
}

bool Queue::peek(int& value) const
{
    if (front == nullptr)
        return false;
    value = front->data;
    return true;
}

bool Queue::isEmpty() const
{
    return front == nullptr;
}

int Queue::size() const
{
    return count;
}

void Queue::display() const
{
    cout << "front ->";
    if (front == nullptr)
        cout << " (empty)";
    for (Node* cur = front; cur != nullptr; cur = cur->next)
        cout << " " << cur->data;
    cout << " <- rear" << endl;
}