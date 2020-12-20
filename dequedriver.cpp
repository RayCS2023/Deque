//
//  dequedriver.cpp
//  Created by: Raymond Chen
//  Student Number: 20790117
//
#include <iostream>
#include "Deque.h"
using std::string;
using std::cin;
using std::endl;
using std::cout;
using std::stoi;

int main(int argc, const char * argv[]) {

    string line;
    string command;
    string info;
    Deque deque;
    
    while (!cin.eof()){
        
        
        getline(cin, line);
        std::size_t space_index = line.find(" ");
        command = line.substr(0,space_index);
        
        if(line == "")
            break;
        
        if(command == "enqueue_front"){
            info = line.substr(space_index+1);
            deque.enqueue_front(stoi(info));
            cout << "success" << endl;
        }
        else if (command == "enqueue_back"){
            info = line.substr(space_index+1);
            deque.enqueue_back(stoi(info));
            cout << "success" << endl;
        }
        else if(command == "dequeue_front"){
            try {
                deque.dequeue_front();
                cout << "success" << endl;
            } catch (deque_empty) {
                cout << "failure" << endl;;
            }
        }
        else if(command == "dequeue_back"){
            try {
                deque.dequeue_back();
                cout << "success" << endl;
            } catch (deque_empty) {
                cout << "failure" << endl;;
            }
        }
        else if(command == "front"){
            info = line.substr(space_index+1);
            try{
                deque.front(stoi(info));
                cout << "success" << endl;
            }
            catch(deque_empty){
                cout << "failure" << endl;
            }
        }
        else if(command == "back"){
            info = line.substr(space_index+1);
            try{
                deque.back(stoi(info));
                cout << "success" << endl;
            }
            catch(deque_empty){
                cout << "failure" << endl;
            }
        }
        else if(command == "size"){
            cout << "size is " << deque.size() << endl;
        }
        else if(command == "clear"){
            deque.clear();
            cout << "success" << endl;
        }
        else if(command == "print"){
            deque.print();
        }
        else if(command == "empty"){
            cout << (deque.empty()==true? "success":"failure") << endl;
        }
        else{
          cout << "invalid command" << endl;
        }
    }
    return 0;
}
