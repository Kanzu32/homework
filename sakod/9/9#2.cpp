#include <iostream>
#include <stdexcept>
#include <fstream>
#include <map>
#include <set>
#include <vector>
#include <algorithm>

//Найдите: (а) для двух выделенных вершин графа соединяющий их
//простой путь; (б) самый длинный простой путь в заданном графе.

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

    Type get(int n) {
        if (n > header->count) {
            throw std::length_error("Index error!!!");
        }
        Node<Type>* node = header->next;
        for (int i = 0; i < n; i++) {
            node = node->next;
        }
        return node->data;
    }

    bool include(int n) {
        Node<Type>* node = header;
        while (node->next != nullptr) {
            node = node->next;
            if (node->data == n) {
                return true;
            }
        }
        // for (int i = 0; i < header->getCount(); i++) {
        //     if (node->data == n) {
        //         return true;
        //     }
        //     node = node->next;
        // }
        return false;
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

    void toSet(set<int> &set) {
        Node<Type>* node = header->next;
        while (node->next != nullptr) {
            set.insert(node->data);
            node = node->next;
        }
    }
};

class Graph {
    int count;
    map<int, HeaderList<int>> nodes;
    map<int, int> minLengths;
    public:
    map<int, int> prev;
    Graph() {
        count = 0;
    }

    void add(int num) {
        count++;
        nodes[num] = HeaderList<int>();
        int next;
        while (cin.peek() != '\n') {
            cin >> next;
            nodes[num].pushBack(next);
        }
    }

    int minLength(int n) {
        return minLengths.at(n);
    }

    void setMinLength(int number, int n) {
        minLengths[number] = n;
    }

    HeaderList<int> getNode(int n) {
        return nodes[n];
    }

    int getCount() {
        return count;
    }

    void travel(int n, vector<int> used, vector<vector<int>> &ways) {
        bool isEnd = true;
        used.push_back(n);
        for (int i = 0; i < nodes[n].header->getCount(); i++) {
            if (std::find(used.begin(), used.end(), nodes[n].get(i)) == used.end()) {
                isEnd = false;
                this->travel(nodes[n].get(i), used, ways);
            }
        }
        if (isEnd) {
            ways.push_back(used);
        }
    }

};

int main() {
    Queue<int> queue = Queue<int>();
    Graph graph;
    set<int> fixed;
    int n, m;
    cout << "Graph nodes (-1 to exit): \n";
    while (cin >> n) {
        if (n < 0) {break;};
        graph.add(n);
    };

    cout << "Select first and last nodes: ";
    cin >> n >> m;
    graph.setMinLength(n, 0);
    queue.push(n);
    fixed.insert(n);

    while (!fixed.count(m)) {
        int node = queue.pop();
        int x = 0;
        while (x < graph.getNode(node).header->getCount()) {
            int i = graph.getNode(node).get(x);
            x++;
            if (!fixed.count(i)) {
                queue.push(i);
                graph.setMinLength(i, graph.minLength(node)+1);
                graph.prev[i] = node;
                fixed.insert(i);
            }
        }
    }

    int i = m;
    do {
        cout << i << " <- ";
        i = graph.prev[i];
    } while (i != n);
    cout << n << '\n';

    vector<int> res;
    fixed.clear();
    for (int i = 1; i < graph.getCount(); i++) {
        if (fixed.count(i)) { continue; };
        vector<vector<int>> ways = vector<vector<int>>();;
        graph.travel(i, vector<int>(), ways);
        for (int j = 0; j < ways.size(); j++) {
            if (ways.at(j).size() > res.size()) {
                res = ways.at(j);
            }
        }
        fixed = std::set<int>(res.begin(), res.end());
    }

    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << " ";
    }
    
}