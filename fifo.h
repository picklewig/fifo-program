
/**************
 * author: Isaac Shepherd
 * file: fifo.h
 **************/


#ifndef FIFO_H
#define FIFO_H

#include "string"
#include <iostream>

using std::cout;
using std::endl;
using std::string;
struct Data {
    int id;
    string data;
};

struct Node {
    Data data;
    Node *next;
    Node *prev;
};

class LinkedList{
    public:
        LinkedList();
        ~LinkedList();

        bool addNode(int, string*);//rename to push, only add to head
        bool pop();
        bool getNode(int, Data*);//rename to peek. does the same thing
        void printList(bool = false);
        bool isEmpty();//new method needs definition
        void clearList();
    private:
        Node *head;
        int nodes;
};

#endif