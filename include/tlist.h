//
// Created by Lenovo on 2023/4/29.
//

#ifndef C__CLASSDESIGN_TLIST_H
#define C__CLASSDESIGN_TLIST_H
#include "../include/listnode.h"
#include <iostream>

template <typename T>
class TList{
protected:
    int size;
    ListNode<T>* head;
    ListNode<T>* tail;
public:
    TList();
    //插在某个结点之后
    void AddNode(ListNode<T>*, int);

    void AddNode(std::istream& in);

    void AddNode(ListNode<T>* );

    void DeleteNode(int);

    int GetSize();

    ListNode<T>* GetHead();

    ListNode<T>& operator[](int);

    void display();
};

template<typename T>
void TList<T>::AddNode(std::istream &in) {
    auto newnode = new ListNode<T>;
    T newdata;
    in >> newdata;
    newnode->SetAddress(newdata);
    if(size==0){
        newnode->SetPrev(head);
        head->SetNext(newnode);
        tail = newnode;
    }else{
        newnode->SetPrev(tail);
        tail->SetNext(newnode);
        tail = newnode;
    }
    size++;
}

template<typename T>
void TList<T>::display() {
    ListNode<T> *ptr = head->GetNext();
    while(ptr) {
        std::cout << *ptr;
        ptr = ptr->GetNext();
    }
}

template<typename T>
void TList<T>::AddNode(ListNode<T>* x, int index) {
    if(index > size+1) std::cout << "超过链表最大长度" << std::endl;
    if(index < 0) std::cout << "参数错误" << std::endl;
    if(size==0||index==size){
        AddNode(x);
    }else{
        ListNode<T>* pre = nullptr;
        ListNode<T>* next = nullptr;
        pre = &(*this)[index];
        next = &(*this)[index+1];
        pre->SetNext(x);
        x->SetPrev(pre);
        next->SetPrev(x);
        x->SetNext(next);
        size++;
    }
}

template<typename T>
void TList<T>::AddNode(ListNode<T>* x) {
    if(size==0){
        head->SetNext(x);
        tail = x;
    }else{
        tail->SetNext(x);
        tail = x;
    }
    size++;
}

template<typename T>
void TList<T>::DeleteNode(int index) {
    if(index<0) std::cout << "参数错误" << std::endl;
    if(index<=size){
        if(size>=0){
            //删除头节点
            if(index==0){
                std::cout << "参数错误" << std::endl;
            }else{
                //删除尾结点时需要特殊处理
                if(index==size) tail = tail->GetPrev();
                ListNode<T>* pre = &(*this)[index-1];
                ListNode<T>* next = nullptr;
                ListNode<T>* now = &(*this)[index];
                if(index!=size) next = &(*this)[index+1];
                pre->SetNext(now->GetNext());
                if(index!=size) next->SetPrev(now->GetPrev());
                size --;
                if(size==0) tail = nullptr;
            }
        }
        if(size==0){
            std::cout << "链表为空 无法删除" << std::endl;
        }
    }else{
        std::cout << "超过链表最大长度" << std::endl;
    }
}

template<typename T>
int TList<T>::GetSize() {
    return size;
}

template<typename T>
ListNode<T>* TList<T>::GetHead() {
    return head;
}

template<typename T>
ListNode<T>& TList<T>::operator[](int index) {
    if(index>size+1){
//        std::cout << "index: " << index << " size: " << size << std::endl;
        std::cout << "参数错误 超过链表最大长度" << std::endl;
        return *tail;
    }
    ListNode<T>* temp = head;
    for (int i = 0; i < index; ++i) {
        temp = temp->GetNext();
    }
    return *temp;
}

template<typename T>
TList<T>::TList() {
    size = 0;
    head = new ListNode<T>;
    tail = nullptr;
}

#endif //C__CLASSDESIGN_TLIST_H
