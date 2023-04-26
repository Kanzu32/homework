#include <iostream>
#include <map>
#include <vector>
#include <set>
#include <chrono>

//Задача о раскраске графа.

using namespace std;

class Graph {
    int count;
    map<int, vector<int>> nodes;
    public:
    map<int, int> color;
    set<int> keys;
    Graph() {
        count = 0;
    }

    void add(int num) {
        count++;
        nodes[num] = vector<int>();
        color[num] = 1;
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

    // void travel(int n, set<int> &visited) {
    //     visited.insert(n);
    //     for (int i = 0; i < nodes[n].size(); i++) {
    //         if (!visited.count(nodes[n][i]))
    //             this->travel(nodes[n][i], visited);
    //     }
    // }
    bool isPainted() {
        int n = 1;
        set<int> visited;
        visited.insert(n);
        for (int child : nodes[n]) {
            if (color[n] == color[child] || (!visited.count(child) && !innerIsPainted(child, visited))) return false;
        }
        return true;
    }

    bool innerIsPainted(int n, set<int> &visited) {
        visited.insert(n);
        for (int child : nodes[n]) {
            if (color[n] == color[child] || (!visited.count(child) && !innerIsPainted(child, visited))) return false;
        }
        return true;
    }


    void paint() {
        for (int h = 1; h < nodes.size(); h++) {
            for (int key : keys) {
                color[key] = 1;
            }
            while (!isPainted()) {

                int i = 1;
                while (i <= nodes.size() && color[i] == h) i++;
                if (i > nodes.size()) break;
                if (color[i] >= h)
                    i++;
                color[i]++;
                if (i == nodes.size()) break;
                for (int k = i-1; k >= 1; k--) {
                    color[k] = 1;
                }

                // for (int key : keys) {
                //     cout << color[key] << " ";
                // }
                // cout << "\n";
            }
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

    auto start_time = std::chrono::steady_clock::now();

    graph.paint();

    auto end_time = std::chrono::steady_clock::now();
    auto elapsed_ns = std::chrono::duration_cast<std::chrono::nanoseconds>(end_time - start_time);
    std::cout << "time: "<< elapsed_ns.count() << " ns\n";

    for (int key : graph.keys) {
        cout << key << ": "<< graph.color[key] << "\n";
    }
}