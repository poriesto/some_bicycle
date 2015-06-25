//
// Created by porie on 23.06.2015.
//

#ifndef UNTITLED_ILIST_H
#define UNTITLED_ILIST_H

#include <memory>
#include <iostream>

template <typename ElemType>
struct Node{
    ElemType data;
    std::unique_ptr<Node> next = nullptr;
};
template <class ElemType>class Ilist {
public:
    void show(){
        Node<ElemType>* current = _head;
        while(current != nullptr){
            std::cout << "value = " << current->data << std::endl;
            current = current->next.get();
        }
    }
    void push_back(const ElemType& value){
        if(_head == nullptr && _size == 0){
            _head = new Node<ElemType>();
            _head->data = value;
            _head->next = std::unique_ptr<Node<ElemType>>(new Node<ElemType>());
            _tail = _head;
            _size++;
        }
        else {
            _tail->next = std::unique_ptr<Node<ElemType>>(new Node<ElemType>());
            _tail = _tail->next.get();
            _tail->data = value;
            _tail->next = nullptr;
            _size++;
        }
    }
    void push_front(const ElemType& elem){
        Node<ElemType>* front = new Node<ElemType>;
        front->data = elem;
        front->next = std::unique_ptr<Node<ElemType>>(_head);
        _head = front;
    }
    void insert(const ElemType& elem, unsigned int pos){
            Node<ElemType>* paste = new Node<ElemType>;
            _pos = 0;
            paste->data = elem;
            paste->next = nullptr;

            Node<ElemType>* current = _head;
            while(current != nullptr) {
                if (_pos == (pos - 1)) {
                    paste->next.swap(current->next);
                    current->next = std::unique_ptr<Node<ElemType>>(paste);
                    _size++;
                    return;
                }
                current = current->next.get();
                _pos++;
            }
    }
    void erase(const ElemType& elem){
        if(_head == nullptr){
            return;
        }
        Node<ElemType>* tmp = _head;
        if (tmp->data == elem){
            _head = tmp->next.get();
            _size--;
            return;
        }
        Node<ElemType>* er = tmp->next.get();
        while(er){
            if(er->data == elem){
                tmp->next.swap(er->next);
                _size--;
                er->next.reset();
                return;
            }
            tmp = er;
            er = er->next.get();
        }
    }
    size_t get_size() const {
        return _size;
    }

protected:
    size_t _size = 0;
    unsigned int _pos = 0;
    Node<ElemType> * _head = nullptr;
    Node<ElemType> * _tail;
};


#endif //UNTITLED_ILIST_H
