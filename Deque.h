//
//  Deque.h
//  Created by: Raymond Chen
//  Student Number: 20790117
//

#ifndef Header_h
#define Header_h

class Node{
private:
    friend class Deque;
    int value;
    Node* p_next;
    Node* p_prev;
public:
    Node(const int &value);
    ~Node();
};

class Deque{
    
public:
    Deque();
    ~Deque();
    void enqueue_front(const int &value);
    void enqueue_back(const int &value);
    void dequeue_front();
    void dequeue_back();
    bool empty() const;
    void clear();
    void front(const int &value) const;
    void back(const int &value) const;
    int size() const;
    void print() const;
private:
    Node* p_head;
    Node* p_tail;
    int list_length;
};

//"exception" class
class deque_empty{};
#endif /* Deque_h */
