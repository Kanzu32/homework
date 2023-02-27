#include <iostream>
#include <stdexcept>
#include <set>
#include <fstream>
//#include <string>
#include <iterator>

using namespace std;

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
    int n;
    int initial = 0;
    Stack<int> stack = Stack<int>();
    set<int> connected;
    ifstream infile("in.txt");
    infile >> n;
    int** matrix = new int*[n];

    for (int i = 0; i < n; i++) {
        matrix[i] = new int[n];
        for (int j = 0; j < n; j++) {
            infile >> matrix[i][j];
        }
    }
    infile.close();
    stack.push(initial);
    connected.insert(initial);

    while(stack.getCount() != 0) {
        int item = stack.pop();
        //cout << item << " out\n";
        for (int i = 0; i < n; i++) {
            if (matrix[item][i] == 1 && !connected.count(i)) {
                stack.push(i);
                connected.insert(i);
                //cout << i << " in\n";
            }
        }
    }

    copy(connected.begin(), connected.end(), ostream_iterator<int>(cout, " "));
}