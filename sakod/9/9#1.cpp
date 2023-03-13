#include <iostream>
#include <stdexcept>
#include <map>
#include <set>

//Перенумеруйте вершины неориентированного графа в порядке
//обхода в ширину.

using namespace std;

template <typename Type> class Node;
template <typename Type> class HeaderList;
template <typename Type> class Queue;

template <typename Type>
class Queue {
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

    Type pop() {
        if (count > 0) {
            Node<Type>* node = first;
            Type data = node->data;
            first = first->next;
            delete node;
            count--;
            return data;
        } else {
            throw std::length_error("Queue is empty!!!");
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
class Node {
protected:
    friend class HeaderList<Type>;
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
    Queue<int> queue = Queue<int>();
    set<int> used;
    Graph graph;
    int n;
    cout << "Graph nodes (-1 to exit): \n";
    while (cin >> n) {
        if (n < 0) {break;};
        graph.add(n);
    };

    cout << "Select node: ";
    cin >> n;
    queue.push(n);
    used.insert(n);
    int number = 1;
    while (queue.getCount() != 0) {
        int node = queue.pop();
        
        cout << node << " -> " << number << '\n';
        number++;
        while (graph.getNode(node).header->getCount() != 0) {
            int i = graph.getNode(node).popFront();
            if (!used.count(i)) {
                queue.push(i);
                used.insert(i);
            }
        }
    }
    
}