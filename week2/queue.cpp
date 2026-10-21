#ifndef QUEUE_H_INCLUDED
#define QUEUE_H_INCLUDED
#include <iostream>
#include "list.h"
#include "linklist.h"
using namespace std;

struct QueueList {
    List l;

    bool isEmpty() {
        return l.size == 0;
    }

    void enqueue(int item) {
        l.ChenVaoCuoi(item);
    }

    int dequeue() {
        if (isEmpty()) {
            cout << "Queue rong"<<endl;
            return -1;
        }
        int value = l.arr[0];
        l.XoaDau();
        return value;
    }

    int front() {
        if (isEmpty()) {
            cout << "Queue rong"<<endl;
            return -1;
        }
        return l.arr[0];
    }

    int size() {
        return l.size;
    }
};

struct QueueLinkedList {
    LinkedList l;
    int count = 0;

    bool isEmpty() {
        return l.Head == nullptr;
    }

    void enqueue(int item) {
        l.ChenVaoCuoi(item);
        count++;
    }

    int dequeue() {
        if (isEmpty()) {
            cout << "Queue rong"<<endl;
            return -1;
        }
        int value = l.Head->data;
        l.XoaDau();
        count--;
        return value;
    }

    int front() {
        if (isEmpty()) {
            cout << "Queue rong"<<endl;
            return -1 ;
        }
        return l.Head->data;
    }

    int size() {
        return count;
    }
};

#endif
