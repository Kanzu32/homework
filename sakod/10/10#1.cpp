#include <iostream>
#include <vector>

//Определите, является ли заданный граф бинарным деревом.

using namespace std;


class TreeNode {
    public:
    int data;
    bool marked;
    vector <TreeNode*> children;
    TreeNode(int val) {
        this->data = val;
        this->marked = false;
    }

    TreeNode addChild(int val) {
        TreeNode child = TreeNode(val);
        children.push_back(&child);
        return child;
    }

    TreeNode addChild(TreeNode& child) {
        children.push_back(&child);
        return child;
    }
};

bool isBinaryTree(TreeNode &node) {
    if (node.marked || node.children.size() != 2 && node.children.size() != 0) {
        return false;
    }
    node.marked = true;
    for (TreeNode* child : node.children) {
        if (!isBinaryTree(*child)) {
            return false;
        }
    }
    return true;
}

int main() {
    TreeNode root = TreeNode(1); // OK
    root.addChild(2);
    TreeNode child = root.addChild(3);
    child.addChild(4);
    child.addChild(5);
    if (isBinaryTree(root)) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }


    TreeNode root2 = TreeNode(1); // >2 связей
    root2.addChild(2);
    TreeNode child2 = root2.addChild(3);
    root2.addChild(4);
    child2.addChild(5);
    child2.addChild(6);
    if (isBinaryTree(root2)) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }

    TreeNode root3 = TreeNode(1); // цикл
    root3.addChild(2);
    TreeNode child3 = root3.addChild(3);
    child3.addChild(6);
    child3.addChild(root3);
    if (isBinaryTree(root3)) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
}