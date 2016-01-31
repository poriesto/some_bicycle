//
// Created by porie on 25.06.2015.
//
#pragma once

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
