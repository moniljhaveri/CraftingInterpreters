#pragma once

#include <iostream> 
#include <memory>

template <typename T>
class node
{

public:
    std::shared_ptr<node<T>> next;
    std::shared_ptr<node<T>> prev;
    T data;
    node(T data) : data(data), next(nullptr), prev(nullptr) {}


}; 


class LinkedList
{
public: 
    LinkedList();
    ~LinkedList() = default;
    void push_back(int data);
    void push_front(int data);
    bool erase(int index);
    bool find(int data);
    size_t get_size();
private:
    std::shared_ptr<node<int>> head;
    std::shared_ptr<node<int>> tail;
    int size;

}; 