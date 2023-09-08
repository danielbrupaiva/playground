#include <iostream>
#include "linkedlist.h"

#define print(x) std::cout << x << std::endl;

using namespace std;

struct Dummy{
    char* TAG;
    int value;
};

int main()
{
    print("Linked List Example");

    LinkedList<int> linkedList;

    linkedList.insertBack(10);
    linkedList.printList();
    linkedList.insertBack(20);
    linkedList.printList();
    linkedList.insertBack(30);
    linkedList.printList();
    linkedList.insertBack(40);
    linkedList.printList();
    linkedList.insertFront(56);
    linkedList.remove(20);
    linkedList.printList();
    linkedList.insertFront(78);
    linkedList.printList();

    return 0;
}
