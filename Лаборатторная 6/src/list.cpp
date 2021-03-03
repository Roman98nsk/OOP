#include "list.h"
#include <cstddef>
#include <iostream>

using namespace std;

void List::pop(){}

void List::add(int* value){}

int List::check_error(int value1, int value2){
    try{
        if(value1 == value2){
            throw KEY_ERROR;
        }
    }catch(int){
        cerr << "Нельзя взять элемент из пустого списка!!!" << endl;
        return KEY_ERROR;
    }
    return OK;
}

void Queue::pop(){
    if (check_error(0,key))
        return;
    cout << "Pop item queue == " << key << endl;
    if (next)
        shift();
    else
        key = 0;
}

void Queue::shift(){
    key = next->key;
    if (next->next)
        next->shift();
    else{
        delete next;
        next = NULL;
    }
}

void Queue::add(int* value){
    if (next){
        next->add(value);
        return;
    }
    if (!key){
        key = *value;
        return;
    }
    Queue* next_queue = new Queue(value);
    next = next_queue;
}

void Stack::pop(){
    if (next){
        next->pop();
        if (!next->key){
            delete next;
            next = NULL;
        }
    return;
    }
    if (check_error(0,key))
        return;
    cout << "pop item stack == " << key << endl;
    key = 0;
}

void Stack::add(int* value){
    if(next){
        next->add(value);
        return;
    }
    if (!key){
        key = *value;
        return;
    }
    Stack* next_stack = new Stack(value);
    next = next_stack;
}