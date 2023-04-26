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
    vector<int> order;
    Graph() {
        count = 0;
    }

    void add(int num) {
        count++;
        nodes[num] = vector<int>();
        color[num] = 0;
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

    int getMax(set<int> &used) {
        int max = 0;
        int maxSize = 0;
        for (int i : keys) {
            if (!used.count(i) && nodes[i].size() > maxSize) {
                maxSize = nodes[i].size();
                max = i;
            }
        }
        used.insert(max);
        return max;
    }

    void genOrder() {
        set<int> used;
        for (int i : keys) {
            order.push_back(getMax(used));
        }
    }

    void paint() {
        for (int n : order) {
            int minPaint = 1;
            for (int i : nodes[n]) {
                if (color[i] == minPaint) minPaint++;
            }
            color[n] = minPaint;
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
    graph.genOrder();

    auto start_time = std::chrono::steady_clock::now();

    graph.paint();

    auto end_time = std::chrono::steady_clock::now();
    auto elapsed_ns = std::chrono::duration_cast<std::chrono::nanoseconds>(end_time - start_time);
    std::cout << "time: "<< elapsed_ns.count() << " ns\n";

    for (int key : graph.keys) {
        cout << key << ": "<< graph.color[key] << "\n";
    }
}