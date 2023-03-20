function comparator(a, b) {
    return (b<a) - (a<b);
}

class BinaryTree {
    root
    comparator
    constructor(value, comparator) {
        this.root = new BinaryTreeNode(value, comparator);
        this.comparator = comparator;
    }

    insert(value) {
        if (this.root == null) {
            this.root = new BinaryTreeNode(value, this.comparator);
            return this.root;
        } else {
            return this.root.insert(value);
        }
    }
}

class BinaryTreeNode {
    count = 1;
    left = null;
    right = null;
    parent = null;
    comparator;
    value;
    constructor(value, comparator) {
        this.value = value;
        this.comparator = comparator;
    }

    insert(value) {
        this.count++;
        if (this.comparator(value, this.value) <= 0) {
            if (this.left) return this.left.insert(value);
            this.left = new BinaryTreeNode(value, this.comparator);
            return this.left;
        }
        if (this.comparator(value, this.value) > 0) {
            if (this.right) return this.right.insert(value);
            this.right = new BinaryTreeNode(value, this.comparator);
            return this.right;
        }
    }
}

// Tree view controls
const view = document.getElementById("view");
let pos = { top: 0, left: 0, x: 0, y: 0 };

const mouseDownHandler = function (e) {
    view.style.cursor = 'grabbing';
    view.style.userSelect = 'none';
    pos = {
        // The current scroll
        left: view.scrollLeft,
        top: view.scrollTop,
        // Get the current mouse position
        x: e.clientX,
        y: e.clientY,
    };

    document.addEventListener('mousemove', mouseMoveHandler);
    document.addEventListener('mouseup', mouseUpHandler);
};

const mouseMoveHandler = function (e) {
    // How far the mouse has been moved
    const dx = e.clientX - pos.x;
    const dy = e.clientY - pos.y;

    // Scroll the element
    view.scrollTop = pos.top - dy;
    view.scrollLeft = pos.left - dx;
};

const mouseUpHandler = function () {
    document.removeEventListener('mousemove', mouseMoveHandler);
    document.removeEventListener('mouseup', mouseUpHandler);

    view.style.cursor = 'grab';
    view.style.removeProperty('user-select');
};

view.addEventListener('mousedown', mouseDownHandler);

function drawNode(node, x, y) {
    let block = document.createElement('div');
    block.classList.add('block');
    block.style.left = x+"px";
    block.style.top = y+"px";
    block.textContent = node.value;
    view.appendChild(block);
}

function drawTree(tree) {
    let count = 1;
    if (tree.root.left != null) count = tree.root.left.count;
    let x = xOffset+(xOffset*count);
    let y = yOffset/2;
    if (tree.root == null) return;
    drawNode(tree.root, x, y);
    if (tree.root.left != null) drawLeft(tree.root.left, x, y);
    if (tree.root.right != null) drawRight(tree.root.right, x, y);
    jg.paint();
}

function drawLeft(node, parentX, parentY) {
    let count = 0;
    if (node.right != null) count = node.right.count;
    let x = parentX - xOffset - (count * xOffset);
    let y = parentY + yOffset;
    jg.drawLine(parentX+blockWidth/2, parentY+blockHeight, x+blockWidth/2, y);
    drawNode(node, x, y);
    if (node.left != null) drawLeft(node.left, x, y);
    if (node.right != null) drawRight(node.right, x, y);
}

function drawRight(node, parentX, parentY) {
    let count = 0;
    if (node.left != null) count = node.left.count;
    let x = parentX + xOffset + (count * xOffset);
    let y = parentY + yOffset;
    jg.drawLine(parentX+blockWidth/2, parentY+blockHeight, x+blockWidth/2, y);
    drawNode(node, x, y);
    if (node.left != null) drawLeft(node.left, x, y);
    if (node.right != null) drawRight(node.right, x, y);
}

var cnv = document.getElementById("view");
var jg = new jsGraphics(cnv);
jg.setColor("#00aaaa");
jg.setStroke(3);

xOffset = 300;
yOffset = 250;
blockWidth = 250;
blockHeight = 150;
tree = new BinaryTree(5, comparator);
tree.insert(6);
tree.insert(3);
tree.insert(0);
tree.insert(8);
tree.insert(7);
tree.insert(9);
tree.insert(11);
tree.insert(12);
tree.insert(10);
tree.insert(4);

drawTree(tree);
