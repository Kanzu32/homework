#include <iostream>
#include <stdexcept>
#include <map>
#include <fstream>

//Используя представление графа с помощью списков смежности,
//определите количество ребер, инцидентных некоторой вершине (степень вершины).

using namespace std;

template <typename Type> class Node;
template <typename Type> class HeaderList;

template <typename Type>
class Node {
protected:
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
class HeaderList {
public:
    HeaderNode<Type>* header;
    Node<Type>* tail;
    

    HeaderList() {
        header = new HeaderNode<Type>();
        tail = header;
    };

    void pushBack(Type data) {
        Node<Type>* node = new Node<Type>(data);
        tail->next = node;
        tail = node;
        header->count++;
    }

    void pushFront(Type data) {
        Node<Type>* node = new Node<Type>(data);
        if (header->count > 0) {
            node->next = header->next;
        }
        if (header->count == 0) {
            tail = node;
        }
        header->next = node;
        header->count++;
        
    }

    Type popFront() {
        if (header->count == 0) {
            throw std::length_error("List is empty!!!");
        }
        if (header->count == 1) {
            tail = header;
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

class GraphNode {
    int count;

    public:
    GraphNode(int n) {
        count = n;
    }
};

class Graph {
    int count;
    map<int, HeaderList<int>> nodes;
    public:
    Graph() {
        count = 0;
    }

    void add(int num) {
        nodes[num] = HeaderList<int>();
        int next;
        while (cin.peek() != '\n') {
            cin >> next;
            nodes[num].pushBack(next);
        }
    }

    HeaderList<int> getNode(int n) {
        return nodes[n];
    }

};

int main() {
    Graph graph;
    int n;
    cout << "Graph nodes  (-1 to exit): \n";
    while (cin >> n) {
        if (n < 0) {break;};
        graph.add(n);
    };

    cout << "Select node: ";
    cin >> n;
    cout << graph.getNode(n).header->getCount();
    
}