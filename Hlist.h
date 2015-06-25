//
// Created by porie on 24.06.2015.
//

#ifndef UNTITLED_HLIST_H
#define UNTITLED_HLIST_H

#include <memory>
#include <iostream>

template <typename ElemType>
struct NodeTwo{
    ElemType data;
    std::shared_ptr<NodeTwo> next;
    std::shared_ptr<NodeTwo> prev;
};

template <typename ElemType>class Hlit{
public:
    void push_back(const ElemType& elem){
        std::shared_ptr<NodeTwo<ElemType>> tmp = std::make_shared<NodeTwo<ElemType>>();
        tmp->next = nullptr;
        tmp->data = elem;
        if(_head != nullptr){
            _tail->next = std::make_shared<NodeTwo<ElemType>>();
            _tail->next->prev = _tail;
            _tail = _tail->next;
            _tail->data = elem;
        }
        else{
            tmp->prev = nullptr;
            _head = _tail = tmp;
        }
        _size++;
    }
    void push_front(const ElemType& elem){
        std::shared_ptr<NodeTwo<ElemType>> tmp = std::make_shared<NodeTwo<ElemType>>();
        tmp->next = nullptr;
        tmp->data = elem;
        if(_head!= nullptr){
            tmp->prev = _head->prev;
            tmp->next = _head;
            _head = tmp;
        }
        else{
            tmp->prev = nullptr;
            _head = _tail = tmp;
        }
        _size++;
    }
    void insert(const ElemType& elem, unsigned int pos){}
    void show(){
        std::shared_ptr<NodeTwo<ElemType>> current = _head;
        while(current){
            std::cout << "Hlit vlaue = " << current->data << std::endl;
            current = current->next;
        }
    }
    void reverse_show(){
        std::shared_ptr<NodeTwo<ElemType>> current = _tail;
        while(current){
            std::cout << "Hlit vlaue = " << current->data << std::endl;
            current = current->prev;
        }
        std::cout << "Hlit vlaue = " << _head->data << std::endl;
    }
    size_t get_size() const {
        return _size;
    }
    ElemType find(unsigned int pos) const{ return nullptr; }
    unsigned int find(const ElemType& elem){ return 0; }
private:
    std::shared_ptr<NodeTwo<ElemType>> _head;
    std::shared_ptr<NodeTwo<ElemType>> _tail;
    size_t _size = 0;
    unsigned int _pos = 0;
};

#endif //UNTITLED_HLIST_H
