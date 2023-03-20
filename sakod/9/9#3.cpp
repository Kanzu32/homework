#include <iostream>
#include <map>
#include <vector>
#include <set>
#include <algorithm>

//Реализуйте алгоритм проверки связности графа, основанный на
//следующем результате [Пападимитриу, Стайнглиц, 1985, с.199], а именно:
//"граф G связен в том и только в том случае, если после применения к нему
//алгоритмов обхода графа в глубину или в ширину все вершины будут помечены".

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
    graph.travel(1, visited);

    for (int i : visited) {
        cout << i << " ";
    }

    if (visited == graph.keys) {
        cout << "\nYES";
    } else {
        cout << "\nNO";
    }
}