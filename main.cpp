#include <iostream>
#include "CContainer.h"
#include "Ilist.h"
#include "Hlist.h"
#include "Ulist.hpp"
using namespace std;

struct Human{
    string name;
    int age;
    Human *next;
};
struct List{
    int value;
    List *next;
};
struct ListTwo{
    int data;
    ListTwo* prev = NULL;
    ListTwo* next = NULL;
};

void println(List* beg){
    List* cur = beg;
    while(cur){
        cout << cur->value << endl;
        cur = cur->next;
    }
}
void print(Human* beg){
    Human* current = beg;
    while(current){
        cout << current->name << " " << current->age << endl;
        current = current->next;
    }
}
void init(Human** beg, int size){
    *beg = new Human;
    Human* end = *beg;
    for(int i = 0; i < size; i++){
        end->next = new Human;
        end = end->next;
        end->name = "P";
        end->age = i;
        end->next = NULL;
    }
}
void init(List** beg, size_t size){
    *beg = new List;
    List* end = *beg;
    for(auto i = 0; i < size; i++){
        end->next = new List;
        end = end->next;
        end->value = i;
        end->next = NULL;
    }
}
struct Hitman{
    string name;
    int age;
};
ostream& operator<<(ostream& os, const Hitman& value){
    os << "Name: " << value.name << " Age: " << value.age;
    return os;
}

int main() {

   CContainer<string, int> c(
            {
                    {std::make_pair("Hello", 1)},
                    {std::make_pair(" C++!", 2)},
                    {std::make_pair("Some magic and frendship", 3)}
            });

    cout << c.GetElem(1);
    cout << c.GetElem(2);
    cout << c.GetElem(3);
    try {
        c.GetElem(4);
    }
    catch (ElemNotFound& e){
        e.what();
    }
    //some exp
    Human* begin = new Human;
    List* lbegin = new List;
    init(&begin, 10);
    init(&lbegin, 20);
    print(begin);
    std::cout << "Test struct" << std::endl;
    println(lbegin);
    ListTwo* head = new ListTwo;
    ListTwo* tail = head;
    ListTwo* current;

   for(int i = 0; i < 5; i++){
        tail->data = i*2;
        tail->next = new ListTwo;
        tail->next->prev = tail;
        tail = tail->next;
    }
    current = head;
    while(current->next){
        std::cout << current->data << std::endl;
        current = current->next;
    }
    std::cout << "From tail to head" << std::endl;
    current = tail->prev;
    while(current){
        std::cout << current->data << std::endl;
        current = current->prev;
    }
    std::cout << "Test my list" << std::endl;
    Ilist<int> lst = Ilist<int>();
    for(int i = 0; i < 10; i++){
        lst.push_back(i);
    }
    cout << "list size: " << lst.get_size();
    lst.insert(270, 5);
    cout << "\nlist size: " << lst.get_size();
    lst.insert(12, 1);
    cout << "\nlist size: " << lst.get_size();
    lst.erase(4);
    cout << "\nlist size: " << lst.get_size();
    lst.push_front(345);
    lst.show();

    std::cout << "Test two way list" << std::endl;
    Hlit<int> hlst = Hlit<int>();
    hlst.push_front(3);
    hlst.push_front(4);
    hlst.push_back(10);
    hlst.push_back(15);
    hlst.show();
    cout << endl;
    hlst.reverse_show();

    std::cout << "Test ULIST" << std::endl;
    Ulist<int> ulist = Ulist<int>();
    ulist.push_front(1);
    ulist.push_front(2);
    ulist.push_front(3);
    ulist.push_front(4);
    ulist.push_back(7);
    ulist.show();
    return 0;
}