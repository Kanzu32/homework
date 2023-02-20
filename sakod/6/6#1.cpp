#include <iostream>
#include <stdexcept>
#include <fstream>
#include <string>

using namespace std;

//( 6 баллов) Дан текстовый файл T. Напечатать его содержимое,
//выписывая литеры каждой его строки в обратном порядке.

template <typename Type> class Node;
template <typename Type> class Stack;

template <typename Type>
class Node {
protected:
    friend class Stack<Type>;
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

int main() {
    Stack<char> stack = Stack<char>();
    ifstream infile("in.txt");
    ofstream outfile("out.txt");
    std::string line;
    while (std::getline(infile, line)) {
        for (int i = 0; i < line.length(); i++) {
            stack.push(line[i]);
        }

        while (stack.getCount() != 0) {
            outfile << stack.pop();
        }

        outfile << '\n';
        
    };
    
    infile.close();
    outfile.close();

}