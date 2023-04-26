#include <iostream>
#include <map>
#include <vector>
#include <set>

//Найдите количество ребер в остовом дереве заданного графа, полученном обходом графа в глубину.

using namespace std;

class Graph {
    int count;
    map<int, vector<int>> nodes;
    public:
    set<int> keys;
    Graph() {
        count = 0;
    }

    void add(int num) {
        count++;
        nodes[num] = vector<int>();
        keys.insert(num);
        int next;
        while (cin.peek() != '\n') {
            cin >> next;
            nodes[num].push_back(next);
        }
    }

    vector<int> getNode(int n) {
        return nodes[n];
    }

    void travel(int n, set<int> &visited) {
        visited.insert(n);
        for (int i = 0; i < nodes[n].size(); i++) {
            if (!visited.count(nodes[n][i]))
                this->travel(nodes[n][i], visited);
        }
    }

    int STConections(int n, set<int> &visited) {
        int count = 0;
        visited.insert(n);
        for (int i = 0; i < nodes[n].size(); i++) {
            if (!visited.count(nodes[n][i])) {
                count++;
                count += this->STConections(nodes[n][i], visited);
            }
        }
        return count;
    }

};

int main() {
    Graph graph;
    cout << "Graph nodes (-1 to exit): \n";
    int n;
    while (cin >> n) {
        if (n < 0) {break;};
        graph.add(n);
    };

    set<int> visited;
    cout << graph.STConections(1, visited);
}