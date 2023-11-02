//
// Created by silve on 30/10/2023.
//
#include <iostream>
#include <cstdlib>
#include <stack>
#ifndef PROYECTO_SEGUNDO_PARCIAL_STACK_H
#define PROYECTO_SEGUNDO_PARCIAL_STACK_H

template <typename Iterator>
        class Stack : private DLList<Iterator> { // se crea una clase para stack y hereda de DLList
        public:
            Stack() { // se crea el constructor simple
            }

            ~Stack(){ // se crea el destructor
                clear();
                delete DLList<Iterator>::head;
                delete DLList<Iterator>::tail;
            }

            void push(Iterator &data){ // inserta el dato al inicio del stack
                DLList<Iterator>::push_front(data);
            }
            void push(Iterator &&data){  // inserta por referencia el dato al inicio del Stack
                DLList<Iterator>::push_front(data);
            }

            void pop(){  // borra el dato al inicio de la lista
                DLList<Iterator>::pop_front();
            }

            void clear(){ // borra toda la lista
                DLList<Iterator>::clear();
            }

            void print(){ // se imprime todo
                DLList<Iterator>::print();
            }

            Iterator top(){ // imprime solamente el primero
                return DLList<Iterator>::head->next->data;
            }
        };

#endif //PROYECTO_SEGUNDO_PARCIAL_STACK_H
