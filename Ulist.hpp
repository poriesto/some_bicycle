//
// Created by porie on 25.06.2015.
//
#pragma once

#include <memory>
#include <iostream>

template <typename ElemType>
struct element{
    ElemType value;
    std::shared_ptr<element> next = nullptr;
};

template <typename ElemType>
class Ulist{
private:
    std::shared_ptr<element<ElemType>> _head;
    std::shared_ptr<element<ElemType>> _tail;
    size_t _size;
public:
    void push_back(const ElemType& elem){
        if(_head == nullptr && _size == 0){
            _head = std::shared_ptr<element<ElemType>>(new element<ElemType>);
            _head->value = elem;
            _head->next = nullptr;
            _tail = _head;
        }
        else{
            std::cout << _tail << " " << _head <<std::endl;
            _tail->next = nullptr;
            _tail->next.reset(new element<ElemType>);
            _tail = _tail->next;
            _tail->value = elem;
            _tail->next = nullptr;
        }
        _size++;
    }
    void push_front(const ElemType& elem){
        if(_head == nullptr && _size == 0){
            _head = std::shared_ptr<element<ElemType>>(new element<ElemType>);
            _head->value = elem;
            _head->next = nullptr;
            _tail = _head;
        }
        else{
            std::shared_ptr<element<ElemType>> front(new element<ElemType>);
            front->next.swap(_head);
            front->value = elem;
            _head.swap(front);
        }
        _size++;
    }
    void insert(const ElemType& elem, const unsigned int pos){
        std::shared_ptr<element<ElemType>> paste(new element<ElemType>);
        unsigned int _pos = 0;

        paste->next = nullptr;
        paste->value = elem;

        std::shared_ptr<element<ElemType>> current(_head.get());
        while(current != nullptr){
            if(_pos == pos){
                paste->next.swap(current->next);
                current->next = std::shared_ptr<element<ElemType>>(paste);
                _size++;
                return;
            }
            current.reset(current->next.get());
            _pos++;
        }
    }

    size_t get_size() const {
        return _size;
    }
    ElemType find(const ElemType& value) const{
        std::shared_ptr<element<ElemType>> current = _head;
        while(current != nullptr){
            if(current->value == value){
                return current->value;
            }
            else{
                current = current->next;
            }
        }
        return nullptr;
    }
    void erase(const ElemType& elem){}
    void erase(const unsigned int pos){}
    void show() const {
        std::shared_ptr<element<ElemType>> current = _head;
        while(current != nullptr){
            std::cout << current.get() << " = " << current->value << std::endl;
            current = current->next;
        }
    }
};
