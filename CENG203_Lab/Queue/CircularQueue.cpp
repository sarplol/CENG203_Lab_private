#include "CircularQueue.h"
#include <iostream>
using namespace std;

// Stubs: the project builds and links, you fill the bodies in Q7.

CircularQueue::CircularQueue()
{
    front = 0;
    count = 0;
    for (int i = 0; i < CAPACITY; i++)
        items[i] = 0;
}

bool CircularQueue::enqueue(int value)
{
    return false;                   // TODO
}

bool CircularQueue::dequeue(int& value)
{
    return false;                   // TODO
}

bool CircularQueue::peek(int& value) const
{
    return false;                   // TODO
}

bool CircularQueue::isEmpty() const
{
    return true;                    // TODO
}

bool CircularQueue::isFull() const
{
    return false;                   // TODO
}

int CircularQueue::size() const
{
    return 0;                       // TODO
}

void CircularQueue::display() const
{
    cout << "front ->";
    for (int i = 0; i < count; i++)
        cout << " " << items[(front + i) % CAPACITY];
    if (isEmpty())
        cout << " (empty)";
    cout << " <- rear   | array:";
    for (int i = 0; i < CAPACITY; i++)
        cout << " " << items[i];
    cout << "  front=" << front << " count=" << count << endl;
}