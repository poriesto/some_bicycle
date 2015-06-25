//
// Created by porie on 25.06.2015.
//

#ifndef UNTITLED_BIN_TREE_H
#define UNTITLED_BIN_TREE_H

#include <memory>
#include <iostream>

template <typename T>
struct branch{
    T value;
    std::shared_ptr<branch> left;
    std::shared_ptr<branch> right;
};

template <typename T>class bit_tree{
private:
};
#endif //UNTITLED_BIN_TREE_H
