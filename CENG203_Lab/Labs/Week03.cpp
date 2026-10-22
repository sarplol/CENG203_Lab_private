#include "Labs.h"
#include "../LinkedList/Node.h"
#include "../LinkedList/LinkedList.h"
#include "../LinkedList/CircularList.h"        // Q8
#include "../LinkedList/DoublyLinkedList.h"    // Q9
#include <iostream>
using namespace std;

void runWeek03()
{
    cout << "--- Week 3: Linked Lists ---" << endl;

    // ---------- Q1: three nodes by hand, no class ----------
    Node* n1 = nullptr;
    cout << "  n1 before new = " << n1 << endl;
    cout << "  sizeof(n1) = " << sizeof(n1)
         << "  sizeof(Node) = " << sizeof(Node) << endl;
    n1 = new Node;
    cout << "  after new: data = " << n1->data << "  next = " << n1->next << endl;
    Node* n2 = new Node;
    Node* n3 = new Node;
    n1->data = 5;  n2->data = 7;  n3->data = 11;
    n1->next = n2;  n2->next = n3;  n3->next = nullptr;
    for (Node* cur = n1; cur != nullptr; cur = cur->next)
        cout << "  node " << cur << ": data = " << cur->data
             << "  next = " << cur->next << endl;
    delete n3;  delete n2;  delete n1;

    // ---------- Q2: insertAtEnd, length, createFromArray ----------
    LinkedList list;
    int arr[] = { 7, 2, 5, 4 };
    list.createFromArray(arr, 4);
    cout << "  list: ";  list.display();
    cout << "  length = " << list.length() << endl;

    // ---------- Q3: search ----------
    cout << "  search(4) = " << list.search(4) << endl;
    cout << "  search(9) = " << list.search(9) << endl;

    // ---------- Q4: update ----------
    list.insertAtEnd(2);                        // 7 2 5 4 2
    int changed = list.update(2, 9);
    cout << "  update(2, 9) changed " << changed << " node(s): ";  list.display();

    // ---------- Q5: insertAt ----------
    cout << boolalpha;                          // print true/false
    cout << "  insertAt(0, 1) = " << list.insertAt(0, 1) << endl;
    cout << "  insertAt(3, 8) = " << list.insertAt(3, 8) << endl;
    cout << "  insertAt(length, 6) = " << list.insertAt(list.length(), 6) << endl;
    cout << "  insertAt(99, 0) = " << list.insertAt(99, 0) << endl;
    cout << "  list: ";  list.display();

    // ---------- Q6: deleteValue ----------
    cout << "  deleteValue(1) = " << list.deleteValue(1) << endl;
    cout << "  deleteValue(8) = " << list.deleteValue(8) << endl;
    cout << "  deleteValue(6) = " << list.deleteValue(6) << endl;
    cout << "  deleteValue(42) = " << list.deleteValue(42) << endl;
    cout << "  list: ";  list.display();

    // ---------- Q7: merge ----------
    LinkedList other;
    int arr2[] = { 30, 40 };
    other.createFromArray(arr2, 2);
    list.merge(other);
    cout << "  merged: ";  list.display();
    cout << "  other:  ";  other.display();

    // ---------- Q8: circular list ----------
    CircularList ring;
    ring.append(7);  ring.append(2);  ring.append(5);  ring.append(4);
    cout << "  ring: ";  ring.display();
    cout << "  ring length = " << ring.length() << endl;

    // ---------- Q9: doubly linked list ----------
    DoublyLinkedList dl;
    dl.insertAtEnd(20);  dl.insertAtEnd(30);  dl.insertAtFront(10);
    cout << "  ";  dl.displayForward();
    cout << "  ";  dl.displayBackward();
    dl.deleteValue(20);
    cout << "  after deleteValue(20):" << endl;
    cout << "  ";  dl.displayForward();
    cout << "  ";  dl.displayBackward();
    dl.deleteValue(30);
    dl.deleteValue(10);
    cout << "  after deleting 30 and 10:" << endl;
    cout << "  ";  dl.displayForward();
    cout << "  ";  dl.displayBackward();
}