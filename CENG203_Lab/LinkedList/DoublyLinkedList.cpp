#include "DoublyLinkedList.h"
#include <iostream>
using namespace std;

DoublyLinkedList::DoublyLinkedList()
{
    head = nullptr;
    tail = nullptr;
}

DoublyLinkedList::~DoublyLinkedList()
{
    while (head != nullptr) {
        DNode* temp = head;
        head = head->next;
        delete temp;
    }
    tail = nullptr;
}

void DoublyLinkedList::insertAtFront(int value)
{
    DNode* newNode = new DNode;
    newNode->data = value;
    newNode->prev = nullptr;
    newNode->next = head;
    if (head != nullptr)
        head->prev = newNode;
    else
        tail = newNode;                 // empty list: new node is also the tail
    head = newNode;
}

void DoublyLinkedList::insertAtEnd(int value)
{
    DNode* newNode = new DNode;
    newNode->data = value;
    newNode->next = nullptr;
    newNode->prev = tail;
    if (tail != nullptr)
        tail->next = newNode;
    else
        head = newNode;                 // empty list: new node is also the head
    tail = newNode;
}

void DoublyLinkedList::displayForward() const
{
    cout << "Forward:  ";
    for (DNode* cur = head; cur != nullptr; cur = cur->next)
        cout << cur->data << " <-> ";
    cout << "NULL" << endl;
}

void DoublyLinkedList::displayBackward() const
{
    cout << "Backward: ";
    for (DNode* cur = tail; cur != nullptr; cur = cur->prev)
        cout << cur->data << " <-> ";
    cout << "NULL" << endl;
}

bool DoublyLinkedList::deleteValue(int value)
{
    DNode* cur = head;
    while (cur != nullptr && cur->data != value)
        cur = cur->next;
    if (cur == nullptr)                 // not found
        return false;

    if (cur->prev != nullptr)           // unlink from the left neighbour
        cur->prev->next = cur->next;
    else
        head = cur->next;               // it was the head
    if (cur->next != nullptr)           // unlink from the right neighbour
        cur->next->prev = cur->prev;
    else
        tail = cur->prev;               // it was the tail
    delete cur;
    return true;
}