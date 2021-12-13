
/**************
 * author: Isaac Shepherd
 * file: linkedlist.cpp
 **************/

#include "fifo.h"

Fifo::Fifo(){
    head = NULL;
}

Fifo::~Fifo(){
    clearList();
}

Node* Fifo::createNode(int id, string* information){
    Node *newNode = new Node;
    newNode->data.id = id;
    newNode->data.data = *information;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

bool Fifo::push(int id, string* information){
    bool added = false;
    if(id > 0 and *information != ""){
        Node *current = head; //head initially is NULL
        if(head == NULL){//starts list head
            head = createNode(id, information);
            added = true;
            nodes++;
        }
        else{//adds new head node
            Node *insertNode = createNode(id, information);
            current->prev = insertNode;
            insertNode->next = current;
            head = insertNode;
            added = true;
            nodes++;
        }
    }
    return added;
}

bool Fifo::pop(){
    bool deleted = false;
    Node *current = head;
    while(current and current->next != NULL){
        current = current->next;
    }
    if(current){
        if (current->prev != NULL and current->next == NULL) { //deletes tail node
            current->prev->next = NULL;
        }
        else if(current == head){
            head = NULL;
        }
        delete current;
        deleted = true;
        nodes--;
    }
    return deleted;
}

bool Fifo::peek(Data& emptyStruct){
    bool gotten = false;
    Node *current = head;

    while(current and current->next != NULL){
        current = current->next;
    }
    if(current) {
        emptyStruct.id = current->data.id;
        emptyStruct.data = current->data.data;
        gotten = true;
    }
    return gotten;
}

void Fifo::printList(bool backwards){
    Node *current = head;
    int nodeNumber = 0;

    if(!backwards){
        while (current) {
            nodeNumber++;
            cout << nodeNumber << ": " << current->data.id << ": " << current->data.data << endl;
            current = current->next;
        }
    } else{
        while(current and current->next != NULL){
            current = current->next;
        }
        while(current){
            nodeNumber++;
            cout << nodeNumber << ": " << current->data.id << ": " << current->data.data << endl;
            current = current->prev;
        }
    }
    if(nodeNumber == 0){
        cout << "\tlist is empty" << endl;
    }
}


void Fifo::clearList(){
    Node *current = head;

    while(head and head->next){
        current = current->next;
        head = current;
        delete current->prev;
    }
    delete head;
    head = NULL;
}

bool Fifo::isEmpty(){
    return nodes > 0;
}