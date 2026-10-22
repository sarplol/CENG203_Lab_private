#include "CircularList.h"
#include <iostream>
using namespace std;

CircularList::CircularList()
{
    head = nullptr;
}

CircularList::~CircularList()
{
    if (head == nullptr)
        return;
    Node* cur = head->next;             // break the ring: delete everything after head
    while (cur != head) {
        Node* temp = cur;
        cur = cur->next;
        delete temp;
    }
    delete head;
    head = nullptr;
}

void CircularList::append(int value)
{
    Node* newNode = new Node;
    newNode->data = value;

    if (head == nullptr) {              // empty ring: the only node points to itself
        newNode->next = newNode;
        head = newNode;
        return;
    }
    Node* cur = head;
    while (cur->next != head)           // stop AT the last node
        cur = cur->next;
    cur->next = newNode;
    newNode->next = head;
}

void CircularList::display() const
{
    if (head == nullptr) {
        cout << "(empty)" << endl;
        return;
    }
    Node* cur = head;
    do {
        cout << cur->data << " -> ";
        cur = cur->next;
    } while (cur != head);
    cout << "(back to " << head->data << ")" << endl;
}

int CircularList::length() const
{
    if (head == nullptr)
        return 0;
    int count = 0;
    Node* cur = head;
    do {
        count++;
        cur = cur->next;
    } while (cur != head);
    return count;
}