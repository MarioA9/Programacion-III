//
// Created by silve on 12/10/2023.
//

#ifndef DLIST_DLLIST_H
#define DLIST_DLLIST_H

#include <iostream>
#include <utility>

template <typename Object> //Declaramos que se va a ultilizar un template y los object seran remplazados por un clase o tipo de dato.

class DLList {
private:
    //Cada Cuadrito
    struct Node  {
        Object data;
        Node *next;//Anya
        Node *previous;
        //aqui hacemos el contructor tipo default

        Node(const Object &d = Object{}, Node *n = nullptr)//aqui hacemos el constructor de tipo copia
                : data{d}, next{n}, previous{n} {}
        Node(Object &&d, Node *n = nullptr)
                : data{std::move(d)}, next{n}, previous{n} {}
    };

public:
    class iterator {
    public:
        iterator() : current{nullptr} {}

        Object &operator*() {
            if(current == nullptr)
                throw std::logic_error("Trying to dereference a null pointer.");
            return current->data;
        }

        iterator &operator++() { //Declaramos que vaya a la siguiente posicion del iterador
            if(current) //Si el puntero esta en la posicion actual, vaya a la siguiente
                current = current->next;
            else
                throw std::logic_error("Trying to increment past the end.");
            return *this;
        }

        iterator operator++(int) { //aqui determinamos donde se usa el ++ por su posicion
            iterator old = *this;
            ++(*this);
            return old;
        }

        iterator &operator--() { //Declaramos que vaya a la siguiente posicion del iterador
            if(current) //Si el puntero esta en la posicion actual, vaya al anterior
                current = current->previous;
            else
                throw std::logic_error("Trying to increment past the end.");
            return *this;
        }

        iterator operator--(int) { //aqui determinamos donde se usa el -- por su posicion
            iterator old = *this;
            --(*this);
            return old;
        }

        bool operator==(const iterator &rhs) const {
            return current == rhs.current;
        }

        bool operator!=(const iterator &rhs) const {
            return !(*this == rhs);
        }

    private:
        Node *current;
        iterator(Node *p) : current{p} {}
        friend class DLList<Object>;
    };

public:
    DLList() : head(new Node()), tail(new Node()), theSize(0) {
        head->next = tail;
    }

    ~DLList() {
        clear();
        delete head;
        delete tail;
    }

    iterator begin() { return {head->next}; }
    iterator end() { return {tail}; }

    int size() const { return theSize; }
    bool empty() const { return size() == 0; }

    void clear() { while (!empty()) pop_front(); }

    Object &front() {
        if(empty())
            throw std::logic_error("List is empty.");
        return *begin();
    }

    void push_front(const Object &x) { insert(begin(), x); } //Se ultiliza para poner un objeto nuevo a la lista por copia
    void push_front(Object &&x) { insert(begin(), std::move(x)); } //aqui es por referencia

    void push_back(const Object &x) { insert(end(), x); }  //Se ultiliza para poner un objeto anterior a la lista por copia
    void push_back(Object &&x) { insert(end(), std::move(x)); } //aqui es por referencia


    void pop_front() {
        if(empty())
            throw std::logic_error("List is empty.");
        erase(begin());
    }

    iterator insert(iterator itr, const Object &x) {
        Node *p = itr.current;
        head->next = new Node{x, head->next};
        theSize++;
        return iterator(head->next);
    }

    iterator insert(iterator itr, Object &&x) {
        Node *p = itr.current;
        head->next = new Node{std::move(x), head->next};
        theSize++;
        return iterator(head->next);
    }

    void insert(int entero, const Object &x)
    {
        insert(Get_interator(entero), x);
    }

    iterator Get_interator(int a)
    {
        iterator it = begin();
        for(int x = 0; x != a; x++){
            it++;
        }
        return it;
    }

    iterator erase(iterator itr) {
        if (itr == end())
            throw std::logic_error("Cannot erase at end iterator");
        Node *p = head;
        while (p->next != itr.current) p = p->next;
        p->next = itr.current->next;
        delete itr.current;
        theSize--;
        return iterator(p->next);
    }

    void erase(int borrar){
        erase(Get_interator(borrar));
    }

    void print() {
        iterator itr = begin();
        while (itr != end()) {
            std::cout << *itr << " ";
            ++itr;
        }
        std::cout << std::endl;
    }

private:
    Node *head;
    Node *tail;
    int theSize;
    void init() {
        theSize = 0;
        head->next = tail;
    }
};

#endif //DLIST_DLLIST_H
