#include <iostream>
using namespace std;
template <typename Type> class Node;
template <typename Type> class Queue;

template <typename Type>
class Node {
    friend class Queue<Type>;
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
    int count;
public:
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
            cout << "Queue is empty!!!";
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
    
    Type operator ! () {
        if (count == 0) {
            cout << "Queue is empty!!!";
            return Type();
        }
        Node<Type>* node = first;
        Type min = first->data;
        while (node->next != nullptr) {
            if (node->data < min) {
                min = node->data;
            };
            node = node->next;
        };
        if (node->data < min) {
                min = node->data;
        };
        return min;
    }
};

int main() {
    Queue<string> queue = Queue<string>("one");
    queue.push("two");
    queue.push("three");
    queue.push("four");
    queue.pop();
    queue.print();
    cout << !queue << "\n";
}