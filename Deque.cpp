//
//  Deque.cpp
//  Created by: Raymond Chen
//  Student Number: 20790117
//

#include <iostream>
#include "Deque.h"
using std::cout;
using std::endl;

//Deque constructor
Deque::Deque(){
    //assign pointer to avoid wild pointers
    p_head = nullptr;
    p_tail = nullptr;
    list_length = 0;
}
//Deque destructor
Deque::~Deque(){
    clear();
}

//Node constructor
Node::Node(const int &value){
    this->value = value;
    p_next = nullptr;
    p_prev = nullptr;
}

//Node destructor
Node::~Node(){
    p_next = nullptr;
    p_prev = nullptr;
}

//add to front
void Deque::enqueue_front(const int &value) {
    //create node
    Node* node = new Node(value);

    //IF empty THEN point head and tail to first node
    if(empty()){
        p_head = node;
        p_tail = node;
    }
    //ELSE assign head's previous node and change head to be new node
    else{
        p_head->p_prev = node;
        node->p_next = p_head;
        p_head = node;
    }
    //increase  size of linked list
    list_length++;
}

//add to back
void Deque::enqueue_back(const int &value) {
    //create node
    Node* node = new Node(value);
    
    //IF empty THEN point head and tail to first node
    if(empty()){
        p_head = node;
        p_tail = node;
    }
    //ELSE assign tail's next node and change tail to be new node
    else{
        node->p_prev = p_tail;
        p_tail->p_next = node;
        p_tail = node;
    }
    list_length++;
}

//remove front
void Deque::dequeue_front(){
    //error if empty
    if(empty())
        throw deque_empty();
        
    //if size is 1, THEN reset everythign to default
    if(size() == 1){
        delete p_head;
        p_tail = nullptr;
        p_head = nullptr;
    }
    //ELSE assign p_head to to its next node
    else{
        Node *tmp = p_head; //need temporary node to track the current head
        p_head = p_head->p_next;
        p_head->p_prev = nullptr;
        delete tmp;
        tmp = nullptr; //avoid dangling pointers
    }
    //decrease size of the linked list
    list_length--;
}

//remove back
void Deque::dequeue_back(){
    //error if empty
    if(empty())
        throw deque_empty();
    
    //if size is 1, THEN reset everythign to default
    if(size() == 1){
        delete p_head;
        p_tail = nullptr;
        p_head = nullptr;
    }
    //ELSE assign p_tail to to its previous node
    else{
        Node *tmp = p_tail; //need temporary node to track the current tail
        p_tail = p_tail->p_prev;
        p_tail->p_next=nullptr;
        delete tmp;
        tmp = nullptr; //avoid dangling pointers
    }
    list_length--;
}

//clear

void Deque::clear(){
    //only clear if the list is not already empty
    if(!empty()){
        while(!empty()){
            dequeue_front();
        }
    }
}

//front
void Deque::front(const int &value) const{
    //need to check if empty fisrt or else p_head->value will throw an error
    if(empty())
        throw deque_empty();
    
    bool equal = p_head->value == value? true:false;
    if(!equal){
        throw deque_empty();
    }
}
//back
void Deque::back(const int &value) const{
    //need to check if empty fisrt or else p_tail->value will throw an error
    if(empty())
        throw deque_empty();
    
    bool equal = p_tail->value == value? true:false;
    if(!equal){
        throw deque_empty();
    }
}

//check if empty
bool Deque::empty() const{
    return (list_length==0);
}

//size of linked list
int Deque::size() const{
    return list_length;
}

void Deque::print() const{
    //loop through the linked list by using a temporary pointer that point to the next node on every ilteration
    if(!empty()){
        Node *tmp = p_head;
        while (tmp!=nullptr){
            if(tmp->p_next == nullptr){
                cout << tmp->value;
            }
            else{
                cout << tmp->value << " ";
            }
            tmp = tmp->p_next;
        }
        std::cout << std::endl;
        
        tmp = p_tail;
        while (tmp!=nullptr){
            if(tmp->p_prev == nullptr){
                cout << tmp->value;
            }
            else{
                cout << tmp->value << " ";
            }
            tmp = tmp->p_prev;
        }
        std::cout << std::endl;
    }
}
