#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED
#include <iostream>
#include "linklist.h"
#include "List.h"
    using namespace std;

    struct StackList{
        List l;

        bool isEmpty() {
            if( l.size == 0){
                return true;
            }
            else{
                return false;
            }

        }

        void push(int item) {
            l.ChenVaoCuoi(item);

        }

        int pop(){
            if (isEmpty()){
                cout <<"Stack rong" << endl;
                return -1;

            }
            int value = l.arr[l.size - 1];
            l.XoaCuoi();
            return value;
        }

        int size() {
            return l.size;


        }
        int top() {

         if (isEmpty()) {

            cout <<"Stack rong" << endl;
            return -1;
         }
         return l.arr[l.size - 1];

        }
    };
    struct StackLinkList {
        LinkedList LL;
        int count = 0;

        bool isEmpty(){

            return LL.Head == nullptr;

        }

        void push(int item){
            LL.ChenVaoDau(item);
            count++;
        }

        int pop(){
            if(isEmpty()) {
                cout<<"Stack rong"<<endl;
                return -1;
            }
            int value = LL.Head->data;
            LL.XoaDau();
            count--;
            return value;

        }

        int size() {
            return count;
        }

        int top() {
            if (isEmpty()) {
                cout << "Stack rong"<<endl;
                return -1;
            }

        return LL.Head -> data;
        }
    };

#endif
