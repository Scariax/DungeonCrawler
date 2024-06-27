/*#include "list.h"
#include <iostream>

template <typename T>
List<T>::List() : Start(nullptr), End(nullptr) {}

template <typename T>
List<T>::~List() {
    while (!is_empty()) {
        pop_front();
    }
}

template <typename T>
void List<T>::push_front(const T& data) {
    Node* new_node = new Node(data);
    if (is_empty()) {
        Start = End = new_node;
    } else {
        new_node->next = Start;
        Start->prev = new_node;
        Start = new_node;
    }
}

template <typename T>
void List<T>::push_back(const T& data) {
    Node* new_node = new Node(data);
    if (is_empty()) {
        Start = End = new_node;
    } else {
        new_node->prev = End;
        End->next = new_node;
        End = new_node;
    }
}

template <typename T>
void List<T>::pop_front() {
    if (is_empty()) {
        std::cerr << "List is empty, cannot pop front" << std::endl;
        return;
    }

    Node* temp = Start;
    if (Start == End) {
        Start = End = nullptr;
    } else {
        Start = Start->next;
        Start->prev = nullptr;
    }
    delete temp;
}

template <typename T>
void List<T>::pop_back() {
    if (is_empty()) {
        std::cerr << "List is empty, cannot pop back" << std::endl;
        return;
    }

    Node* temp = End;
    if (Start == End) {
        Start = End = nullptr;
    } else {
        End = End->prev;
        End->next = nullptr;
    }
    delete temp;
}

template <typename T>
bool List<T>::is_empty() const {
    return Start == nullptr;
}

template <typename T>
void List<T>::print_list() const {
    Node* current = Start;
    while (current != nullptr) {
        std::cout << current->data << " ";
        current = current->next;
    }
    std::cout << std::endl;
}

template <typename T>
typename List<T>::Iterator List<T>::begin() const {
    return Iterator(Start);
}

template <typename T>
typename List<T>::Iterator List<T>::end() const {
    return Iterator(nullptr);
}
*/
