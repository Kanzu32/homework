#include <iostream>
#include <stdexcept>

using namespace std;

//(6 баллов) Предположим, что уже построен стек, элементами
//которого являются целые числа. Написать программу, которая удаляет из
//стека все элементы, кратные 4 (использовать для промежуточного хранения
//элементов стека однонаправленный список с заглавным звеном).

template <typename Type> class Node;
template <typename Type> class Stack;
template <typename Type> class HeaderList;

template <typename Type>
class Node {
protected:
    friend class Stack<Type>;
    friend class HeaderList<Type>;
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
class HeaderNode: public Node<Type> {
    friend class HeaderList<Type>;
    int count;
public:
    HeaderNode(): Node<Type>::Node() {
        count = 0;
    }

    int getCount() {
        return count;
    }
};

template <typename Type>
class Stack {
    int count;
public:
    int getCount() {
        return count;
    }
    Node<Type>* top;

    Stack() {
        count = 0;
    };

    Stack(Type data) {
        Node<Type>* node = new Node<Type>(data);
        top = node;
        count = 1;
    }

    void push(Type data) {
        Node<Type>* node = new Node<Type>(data);
        if (count == 0) {
            top = node;
            count = 1;
        } else {
            node->next = top;
            top = node;
            count++;
        }
        
    }

    Type pop() {
        if (count == 0) {
            throw std::length_error("Stack is empty!!!");
        }
        Node<Type>* node = top;
        Type data = node->data;
        top = top->next;
        delete node;
        count--;
        return data;
        
    }

    void print() {
        Node<Type>* node = top;
        while (node->next != nullptr) {
            cout << node->data << " ";
            node = node->next;
        }
        cout << node->data << "\n";
    }
};

template <typename Type>
class HeaderList {
public:
    HeaderNode<Type>* header;
    

    HeaderList() {
        header = new HeaderNode<Type>();
    };

    void pushFront(Type data) {
        Node<Type>* node = new Node<Type>(data);
        if (header->count > 0) {
            node->next = header->next;
        }
        header->next = node;
        header->count++;
    }

    Type popFront() {
        if (header->count == 0) {
            throw std::length_error("List is empty!!!");
        }
        Node<Type>* node = header->next;
        header->next = node->next;
        Type data = node->data;
        delete node;
        header->count--;
        return data;
        
    }

    void print() {
        if (header->count != 0) {
            Node<Type>* node = header->next;
            while (node->next != nullptr) {
                cout << node->data << " ";
                node = node->next;
            }
        cout << node->data << "\n";
        }
    }
};

int main() {
    HeaderList<int> hlist = HeaderList<int>();
    Stack<int> stack = Stack<int>();
    stack.push(1);
    stack.push(2);
    stack.push(4);
    stack.push(8);
    stack.push(9);
    stack.push(16);
    stack.push(22);
    stack.push(44);

    stack.print();

    while (stack.getCount() != 0) {
        int item = stack.pop();
        if (item % 4 != 0) {
            hlist.pushFront(item);
        }
    }

    while (hlist.header->getCount() != 0) {
        stack.push(hlist.popFront());
    }

    stack.print();
}