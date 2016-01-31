//
// Created by porie on 22.06.2015.
//
#pragma once

#include <utility>
#include <initializer_list>
#include "IContainer.h"

template <typename ElemType, typename IndexType>
class CContainer
        : IContainer<ElemType, IndexType>, public std::map<IndexType, ElemType> {
public:
    CContainer(){}
    CContainer(std::initializer_list<std::pair<ElemType, IndexType>>list){
        for(auto value : list){
            PutElem(value.second, value.first);
        }
    }
    virtual ~CContainer() { }


    inline void PutElem(const IndexType &index, const ElemType &elem) throw(){
        this->insert(std::make_pair(index,elem));
    }
    inline const ElemType &GetElem(const IndexType &index) const throw(ElemNotFound){
        auto result = this->find(index);
        if(result == this->end()){
            throw ElemNotFound();
        }
        return result->second;
    }
};
