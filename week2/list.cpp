#ifndef DEFLIST_H_INCLUDED
#define DEFLIST_H_INCLUDED
#include <iostream>

using namespace std;

struct List{

    int arr[100];//khai bao mang tinh
    int size; // so phan tu cua list

    List(){
    size = 0;//list rong

    }
    //O(1)
    void TruyCap(int index){

    cout << arr[index];
    }

    //O(n)
    void ChenVaoDau(int value){
        for(int i = size; i > 0; --i){
            arr[i] = arr[i - 1];
        }
        arr[0] = value;
        size++;

    }

    //O(1)
    void ChenVaoCuoi(int value){
        arr[size] = value;
        size++;

    }

    //O(n)
    void ChenVaoViTri(int index, int value){

        if( index == 0){
            ChenVaoDau(value);
        }
    else if( index == size){
        ChenVaoCuoi(value);
    }
    else {
        for( int i = size; i > index; --i){
            arr[i] = arr[ i-1];
        }
        arr[index] = value;
        size++;
        }
    }

    //O(n)
    void XoaDau() {

            for(int i = 0; i < size; i++){
                arr[i] = arr[i + 1];

            }
            size--;

    }

    //O(1)
    void XoaCuoi() {

        size--;
    }

    //O(n)
    void XoaViTri(int index){
        for(int i = index; i < size; i++){
            arr[i] = arr[i + 1];
        }
        size--;
    }

    //O(n)
    void DuyetXuoi(){
        for(int i = 0; i < size; i++){
            cout<< arr[i]<<" ";
        }

    }

    //O(n)
    void DuyetNguoc(){
        for(int i = size - 1; i >= 0; i--){
            cout<<arr[i]<<" ";
        }

    }
};
#endif // DEFLIST_H_INCLUDED
