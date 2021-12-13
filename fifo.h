
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

class Fifo{
    public:
        Fifo();
        ~Fifo();

        bool push(int, string*);
        bool pop();
        bool peek(Data*);//peeks tail node data
        bool isEmpty();

        void clearList();
        void printList(bool = false);
    private:
        Node* createNode(int, string*);
        Node *head;
        int nodes;
};

#endif