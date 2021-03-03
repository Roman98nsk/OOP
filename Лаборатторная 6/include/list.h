#ifndef LIST_H
#define LIST_H
#include <cstddef>

#define KEY_ERROR -1
#define OK 0

class List{
    protected:
    int key;
    public:
    static int values[];
    List(int value = 0) : key(value) {};
    virtual void pop();
    virtual void add(int* value);
    virtual ~List() {}
    static int check_error(int value1, int value2);
};

class Queue: public List{
    private:
    Queue* next;
    public:
    Queue(int value = 0, Queue* pointer = NULL) : List(value),next(pointer) {}
    Queue(int* value, Queue* pointer = NULL) : List(*value), next(pointer) {}
    virtual ~Queue() {}
    virtual void pop();
    virtual void add(int* value);
    void shift();

};

class Stack: public List{
    private:
    Stack* next;
    public:
    Stack(int value = 0, Stack* pointer = NULL) : List(value), next(pointer) {}
    Stack(int* value, Stack* pointer = NULL) : List(*value), next(pointer) {}
    virtual ~Stack() {}
    virtual void pop();
    virtual void add(int* value);
};

#endif