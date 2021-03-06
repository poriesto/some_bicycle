//
// Created by porie on 22.06.2015.
//
#pragma once

#include <map>

class ElemNotFound {
public:
    ElemNotFound(){ }
    virtual ~ElemNotFound() { }
    void what(){
        std::cout << "Element not found in container" << std::endl;
    }
};

template < typename ElemType, typename IndexType > class IContainer
{
public:
    virtual const ElemType& GetElem( const IndexType& index ) const
            throw ( ElemNotFound ) = 0;

    virtual void PutElem( const IndexType& index, const ElemType& elem )
            throw () = 0;
};
