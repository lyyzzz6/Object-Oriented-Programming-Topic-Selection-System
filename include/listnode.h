//
// Created by Lenovo on 2023/4/29.
//

#ifndef C__CLASSDESIGN_LISTNODE_H
#define C__CLASSDESIGN_LISTNODE_H
#include <iostream>

template <typename T>
class ListNode{
protected:
    T address;
    ListNode *next;
    ListNode *prev;
public:
    ListNode();

    ListNode* GetNext();

    void SetNext(ListNode *);

    ListNode* GetPrev();

    void SetPrev(ListNode *);

    T& GetAddress();

    void SetAddress(T);

    template<typename t>
    friend std::ostream& operator<<(std::ostream&, ListNode<t>&);
};

template<typename t>
std::ostream &operator<<(std::ostream &out, ListNode<t>& right ) {
    out << right.address << std::endl;
    return out;
}

template<typename T>
void ListNode<T>::SetAddress(T a) {
    address = a;
}

template<typename T>
T& ListNode<T>::GetAddress() {
    return address;
}

template<typename T>
void ListNode<T>::SetPrev(ListNode *p) {
    prev = p;
}

template<typename T>
ListNode<T> *ListNode<T>::GetPrev() {
    return prev;
}

template<typename T>
void ListNode<T>::SetNext(ListNode *n) {
    next = n;
}

template<typename T>
ListNode<T> *ListNode<T>::GetNext() {
    return next;
}

template<typename T>
ListNode<T>::ListNode() {
    next = nullptr;
    prev = nullptr;
}



#endif //C__CLASSDESIGN_LISTNODE_H
