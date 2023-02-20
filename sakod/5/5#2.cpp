#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

// (3 балла) Напишите процедуру добавления в конец очереди Q
//элемента X из ее начала, причем при формировании очереди учтите, что она
//может содержать не более K звеньев (переполнение очереди) и не может
//быть пустой (опустошение очереди).

using namespace std;

template <typename Type> class Node;
template <typename Type> class Queue;
template <typename Type> class FixedQueue;

template <typename Type>
class Node {
private:
    friend class Queue<Type>;
    friend class FixedQueue<Type>;
    Node<Type>* next;
public:
    Type data;

    Node() {
        next = nullptr;
    };

    Node(Type data): Node() {
        this->data = data;
    }

    
};

template <typename Type>
class Queue {
protected:
    int count;
public:
    int getCount() {
        return count;
    }
    Node<Type>* first;
    Node<Type>* last;
    

    Queue() {
        count = 0;
    };

    Queue(Type data) {
        Node<Type>* node = new Node<Type>(data);
        first = node;
        last = node;
        count = 1;
    }

    void push(Type data) {
        Node<Type>* node = new Node<Type>(data);
        if (count == 0) {
            first = node;
            last = node;
            count = 1;
        } else {
            last->next = node;
            last = node;
            count++;
        }
        
    }

    void pop() {
        if (count > 0) {
            Node<Type>* node = first;
            Type data = node->data;
            first = first->next;
            delete node;
            count--;
        } else {
            cout << "Queue is empty!!!\n";
        }
        
    }

    void print() {
        Node<Type>* node = first;
        while (node->next != nullptr) {
            cout << node->data << " ";
            node = node->next;
        }
        cout << node->data << "\n";
    }
};

template <typename Type>
class FixedQueue: public Queue<Type> {
    int limit;
public:
    FixedQueue(unsigned limit): Queue<Type>::Queue() {
        this->limit = limit;
    }

    void push(Type data) {
        Node<Type>* node = new Node<Type>(data);
        if (this->count == 0) {
            this->first = node;
            this->last = node;
            this->count = 1;
        } else if (this->count < limit) {
            this->last->next = node;//
            this->last = node;
            this->count++;
        } else {
            cout << "Queue is full!!!\n";
        }
        
    }

    void pop() {
        if (this->count > 1) {
            Node<Type>* node = this->first;
            Type data = node->data;
            this->first = this->first->next;
            delete node;
            this->count--;
        } else {
            cout << "Queue can't be empty!!!\n";
        }
    }

    void move() {
        if (this->count > 1) {
            Node<Type>* node = this->first;
            this->first = this->first->next;
            node->next = nullptr;
            this->last->next = node;
            this->last = node;
        } else if (this->count == 0) {
            cout << "Queue is empty!!!\n";
        }
    }
};

int main() {
    FixedQueue<int> fq = FixedQueue<int>(5);
    fq.move(); //is empty
    fq.push(1);
    fq.print();
    fq.move();
    fq.print();
    fq.pop(); //can't be empty
    fq.push(2);
    fq.push(3);
    fq.push(4);
    fq.push(5);
    fq.print();
    fq.push(6); //full
    fq.print();
    fq.move();
    fq.print();

    
}