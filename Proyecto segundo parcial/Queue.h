#ifndef PROYECTO_SEGUNDO_PARCIAL_QUEUE_H
#define PROYECTO_SEGUNDO_PARCIAL_QUEUE_H
// enqueue copia referencia r y l
// dequeue
//front
// print

template<typename ZL>
class Queue : private DLList<ZL>{ // se crea una clase para queu y hereda de DLList
public:
    Queue(){ // se crea el constructor simple
    }

    ~Queue(){ // se crea el destructor
        clear();
        delete DLList<ZL>::head; // se borra el head heredado del DLList
        delete DLList<ZL>::tail; // se borra el tail heredado del DLList
    }

    void enqueue(ZL &data){ // inserta el dato al final del queu
        DLList<ZL>::push_back(data);
    }

    void enqueue(ZL &&data){ // inserta por referencia el dato al final del queu
        DLList<ZL>::push_back(data);
    }

    void dequeue(){  // borra el dato al inicio de la lista
        DLList<ZL>::pop_front();
    }

    void print(){ // se imprime todo
        DLList<ZL>::print();
    }

    void clear(){ // borra toda la lista
        DLList<ZL>::clear();
    }

    ZL front(){ // imprime solamente el primero
        return DLList<ZL>::head->next->data;
    }
};

#endif //PROYECTO_SEGUNDO_PARCIAL_QUEUE_H