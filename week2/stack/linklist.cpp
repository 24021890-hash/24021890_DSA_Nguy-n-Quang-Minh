#ifndef DEFLINKLIST_H_INCLUDED
#define DEFLINKLIST_H_INCLUDED
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Node{
    int data;
    Node* next;

    };
struct LinkedList{
        Node* Head;
        LinkedList(){
            Head = nullptr;

        }
        void TruyCap(int vitri){
            Node *A = Head;
            for( int i = 1; i < vitri; i++){
                A = A -> next;
            }
            cout<<A ->data<<endl;
        }
        void ChenVaoDau(int giatri){
            Node *B = new Node{giatri,Head};
            Head = B;
        }
        void ChenVaoCuoi(int giatri){
            Node *A = Head;
            Node *C = new Node{giatri, nullptr};
                while(A -> next != nullptr){
                    A = A -> next;
                }
                A -> next = C;
        }
        void ChenVaoViTri(int vitri,int giatri){
            Node *A = Head;
            for( int i = 1; i < vitri - 1; i++){
                A = A -> next;
            }
            Node *D = new Node{giatri,A->next};
            A -> next = D;

        }
        void XoaDau(){
            Node *A = Head;
            Head = Head -> next;
            delete A;
        }
        void XoaCuoi(){
            Node *A = Head;

            while( A -> next -> next != nullptr){
                A = A -> next;
            }
            delete A -> next;
            A -> next = nullptr;
        }
        void XoaViTri(int giatri){
            Node *A = Head;
            for(int i = 1; i < giatri-1;i++ ){
                A = A->next;
            }
            Node *E = A->next;
            A -> next = A->next->next;
            delete E;
        }
        void DuyetXuoi(){
            Node *A = Head;
            while( A != nullptr){
                cout<<A -> data<<" ";
                A = A -> next;
            }
            cout<<endl;
        }
        void DuyetNguoc(){
            vector<int> a;
            Node *A = Head;
            while(A != nullptr){
                a.push_back(A -> data);
                A = A -> next;
            }
            for(int i = a.size()-1; i >= 0; i--){
                cout<<a[i]<<" ";
            }
        }
};





#endif
