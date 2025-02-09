#include "LinkedList.h"

LinkedList::LinkedList() : head(nullptr), tail(nullptr), size(0) 
{
    head = std::make_shared<node<int>>(0);
    tail = std::make_shared<node<int>>(0);
    head->next = tail;
    tail->prev = head;
}

void LinkedList::push_back(int data)
{
    std::shared_ptr<node<int>> new_node = std::make_shared<node<int>>(data);
    new_node->next = tail;
    new_node->prev = tail->prev;
    tail->prev->next = new_node;
    tail->prev = new_node;
    size++;
}

void LinkedList::push_front(int data)
{
    std::shared_ptr<node<int>> new_node = std::make_shared<node<int>>(data);
    new_node->next = head->next;
    head->next->prev = new_node;
    head->next = new_node;
    new_node->prev = head;
    size++;
}

size_t LinkedList::get_size()
{
    return size;
}

bool LinkedList::erase(int index)
{
    if (index < 0 || index >= size)
    {
        return false;
    }
    std::shared_ptr<node<int>> current = head->next;
    for (int i = 0; i < index; i++)
    {
        current = current->next;
    }
    current->prev->next = current->next;
    current->next->prev = current->prev;
    size--;
    return true;
}
