function comparator(a, b) {
    return (b<a) - (a<b);
}

//TODO

// delete by ID
// balance by ID??
// animation
// dropdown menu / delete buttom
// file export/import

class BinaryTree {
    root
    comparator
    IDArray
    constructor(comparator) {
        this.IDArray = [];
        //this.root = new BinaryTreeNode(value, comparator, this.IDArray.length);
        //this.IDArray.push(this.root)
        this.comparator = comparator;
    }

    insert(value) {
        if (this.root == null) {
            this.root = new BinaryTreeNode(value, this.comparator, this.IDArray.length);
            this.IDArray.push(this.root)
            setTypeChange(false);
            setAutoBalanceChange(false);
            return this.root;
        } else {
            let node = this.root.insert(value, this.IDArray.length);
            this.IDArray.push(node);
            return node;
        }
    }

    find(value) { //return node object
        return this.root.find(value);
    }

    recalculateCounts() {
        this.root.recalculateCountDown();
    }

    remove(value) {
        if (this.root == null) return;
        const nodeToRemove = this.find(value);

        if (nodeToRemove == null) {
            console.log("Tree with value " + value + " is not found.");
            return false;
        }

        const parent = nodeToRemove.parent;
        if (!nodeToRemove.left && !nodeToRemove.right) {
            if (parent) {
                this.IDArray[nodeToRemove.ID] = null;
                parent.removeChild(nodeToRemove);
                parent.recalculateAndRebalanceUp();
            } else {
                this.IDArray[this.root.ID] = null;
                this.root = null;
                setTypeChange(true);
                setAutoBalanceChange(true);
            }
        } else if (nodeToRemove.left && nodeToRemove.right) {
            const newNode = nodeToRemove.right.findMin();
            if (newNode === nodeToRemove.right) {
                this.IDArray[nodeToRemove.ID] = null;
                nodeToRemove.value = nodeToRemove.right.value;
                nodeToRemove.ID = nodeToRemove.right.ID;
                nodeToRemove.right = nodeToRemove.right.right;
                nodeToRemove.recalculateAndRebalanceUp();
                
            } else {
                this.remove(newNode.value); //!!!!!!!!!!
                this.IDArray[nodeToRemove.ID] = null;
                newNode.parent.recalculateAndRebalanceUp();
                nodeToRemove.value = newNode.value;
                nodeToRemove.ID = newNode.ID;
                //console.log(nodeToRemove, newNode);
            }
        } else {
            const childNode = nodeToRemove.left || nodeToRemove.right;
        
            if (parent) {
                this.IDArray[nodeToRemove.ID] = null;
                parent.replaceChild(nodeToRemove, childNode);  //++++
                nodeToRemove.recalculateAndRebalanceUp();
            } else {
                this.IDArray[this.root.ID] = null;
                this.root = childNode;
                this.root.parent = null;
            }
        }
        return true;

    }
}

class BinaryTreeNode {
    count = 1;
    left = null;
    right = null;
    parent = null;
    comparator;
    value;
    ID;
    constructor(value, comparator, ID) {
        this.value = value;
        this.comparator = comparator;
        this.ID = ID;
    }

    insert(value, ID) {
        this.count++;

        if (this.comparator(value, this.value) <= 0) {
            if (this.left) {
                let node = this.left.insert(value, ID);
                if (autoBalance) this.balance();
                return node;
            }
            this.left = new BinaryTreeNode(value, this.comparator, ID);
            this.left.parent = this;
            if (autoBalance) this.balance();
            return this.left;
        }

        if (this.comparator(value, this.value) > 0) {
            if (this.right) {
                let node = this.right.insert(value, ID);
                if (autoBalance) this.balance();
                return node;
            } 
            this.right = new BinaryTreeNode(value, this.comparator, ID);
            this.right.parent = this;
            if (autoBalance) this.balance();
            return this.right;
        }
    }

    find(value) {
        if (this.comparator(this.value, value) === 0) return this;
 
        if (this.comparator(this.value, value) > 0 && this.left) {
            return this.left.find(value);
        }

        if (this.comparator(this.value, value) <= 0 && this.right) {
            return this.right.find(value);
        }

        return null;
    }

    findMin() {
        if (!this.left) {
            return this;
        }
      
        return this.left.findMin();
    }

    removeChild(nodeToRemove) {
        if (this.left && this.left === nodeToRemove) {
            this.left = null;
            return true;
        }
    
        if (this.right && this.right === nodeToRemove) {
            this.right = null;
            return true;
        }

        return false;
    }

    replaceChild(nodeToReplace, replacementNode) {
        if (!nodeToReplace || !replacementNode) {
            return false;
        }
      
        if (this.left && this.left === nodeToReplace) {
            this.left = replacementNode;
            replacementNode.parent = this;
            return true;
        }
      
        if (this.right && this.right === nodeToReplace) {
            this.right = replacementNode;
            replacementNode.parent = this;
            return true;
        }
      
        return false;
    }

    recalculateAndRebalanceUp() {
        this.count = 1;
        if (this.left) {
            this.count += this.left.count;
        }

        if (this.right) {
            this.count += this.right.count;
        }
        
        this.balance();

        if (this.parent) {
            this.parent.recalculateAndRebalanceUp();
        }
    }

    recalculateCountDown() {
        this.count = 1;
        if (this.left) {
            this.count += this.left.recalculateCountDown();
        }

        if (this.right) {
            this.count += this.right.recalculateCountDown();
        }
        return this.count;
    }

    rotateLeft() {
        let b = this.right;
        this.right = b.left;
        if (b.left) {
            b.left.parent = this;
        }
        b.left = this;
        b.parent = this.parent;
        if (this.parent) {
            this.parent.replaceChild(this, b);
        } else {
            tree.root = b;
        }
        this.parent = b;
        this.recalculateCountDown();
    }

    rotateRight() {
        let b = this.left;
        this.left = b.right;
        if (b.right) {
            b.right.parent = this;
        }
        b.right = this;
        b.parent = this.parent;
        if (this.parent) {
            this.parent.replaceChild(this, b);
        } else {
            tree.root = b;
        }
        this.parent = b;
        this.recalculateCountDown();
    }

    bigRotateLeft() {
        this.right.rotateRight()
        this.rotateLeft()
    }

    bigRotateRight() {
        this.left.rotateLeft()
        this.rotateRight()
    }

    getHeight() {
        if (!this.left && !this.right) {
            return 1;
        } else if (this.left && this.right) {
            return Math.max(this.left.getHeight(), this.right.getHeight()) + 1;
        } else if (!this.left) {
            return this.right.getHeight() + 1;
        } else {
            return this.left.getHeight() + 1;
        }
    }



    balance() {
        let rightHeight = 0
        let leftHeight = 0
        if (this.right) rightHeight = this.right.getHeight();
        if (this.left) leftHeight = this.left.getHeight();
        let bal = rightHeight - leftHeight;

        if (bal >= 2) { //left
            let subRightHeight = 0;
            let subLeftHeight = 0;
            if (this.right.right) subRightHeight = this.right.right.getHeight();
            if (this.right.left) subLeftHeight = this.right.left.getHeight();

            if (subLeftHeight <= subRightHeight) this.rotateLeft();
            else this.bigRotateLeft();

        } else if (bal <= -2) { //right
            let subRightHeight = 0;
            let subLeftHeight = 0;
            if (this.left.right) subRightHeight = this.left.right.getHeight();
            if (this.left.left) subLeftHeight = this.left.left.getHeight();

            if (subRightHeight <= subLeftHeight) this.rotateRight();
            else this.bigRotateRight();
        }
    }
}

// Tree view controls
const view = document.getElementById("view");
const content = document.getElementById("content");
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

// draw functions
function drawNode(node, x, y) {
    let block = document.createElement('div');
    block.classList.add('block');
    block.style.left = x+"px";
    block.style.top = y+"px";
    if (node.parent) {
        block.textContent = "value: " + node.value + " count: " + node.count + " ID: " + node.ID + " parent val: " + node.parent.value + " ID: " + node.parent.ID;
    } else {
        block.textContent = "value: " + node.value + " count: " + node.count + " ID: " + node.ID;
    }
    content.appendChild(block);
}

function drawTree(tree) {
    content.innerHTML = '';
    jg = new jsGraphics(content);
    jg.setColor("#00aaaa");
    jg.setStroke(3);
    let count = 1;
    if (tree.root == null) return;
    if (tree.root.left != null) count = tree.root.left.count;
    let x = xTreeOffset+(xOffset*count);
    let y = yTreeOffset;
    if (x > maxX) {maxX = x};
    if (y > maxY) {maxY = y};
    drawNode(tree.root, x, y);
    if (tree.root.left != null) drawLeft(tree.root.left, x, y);
    if (tree.root.right != null) drawRight(tree.root.right, x, y);
    jg.paint();
    content.style.height = maxY+blockHeight+6+yTreeOffset+"px";
    content.style.width = maxX+blockWidth+6+xTreeOffset+"px";
}

function drawLeft(node, parentX, parentY) {
    let count = 0;
    if (node.right != null) count = node.right.count;
    let x = parentX - xOffset - (count * xOffset);
    let y = parentY + yOffset;
    if (x > maxX) {maxX = x};
    if (y > maxY) {maxY = y};
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
    if (x > maxX) {maxX = x};
    if (y > maxY) {maxY = y};
    jg.drawLine(parentX+blockWidth/2, parentY+blockHeight, x+blockWidth/2, y);
    drawNode(node, x, y);
    if (node.left != null) drawLeft(node.left, x, y);
    if (node.right != null) drawRight(node.right, x, y);
}

//ui buttons
function addNode() {
    let input = document.getElementById("new-node-input");
    let value = input.value;
    if (intMode && isNaN(value)) {
        input.classList.add("wrong-input-animation");
        input.onanimationend = () => {input.classList.remove("wrong-input-animation");};
    } else if (intMode) {
        tree.insert(parseInt(value, 10));
        drawTree(tree);
    } else {
        tree.insert(value);
        drawTree(tree);
    }
}

function removeNode() {
    let input = document.getElementById("remove-node-input");
    let value = input.value;
    if ((intMode && isNaN(value)) || tree.root == null) {
        input.classList.add("wrong-input-animation");
        input.onanimationend = () => {input.classList.remove("wrong-input-animation");};
    } else if (intMode) {
        tree.remove(parseInt(value, 10));
        drawTree(tree);
    } else {
        tree.remove(value);
        drawTree(tree);
    }
}

//ui
dataTypeSwitch = document.getElementById("data-type-input");
dataTypeSwitch.addEventListener("change", ()=>{
    if (!tree.root) {
        intMode = dataTypeSwitch.checked;
    }
});

function setTypeChange(val) {
    dataTypeSwitch.disabled = !val;
    dataTypeSwitch.parentElement.style.opacity = 0.5 + val*0.5;
};

balanceSwitch = document.getElementById("balance-input");
balanceSwitch.addEventListener("change", ()=>{
    if (!tree.root) {
        autoBalance = balanceSwitch.checked;
    }
});

function setAutoBalanceChange(val) {
    balanceSwitch.disabled = !val;
    balanceSwitch.parentElement.style.opacity = 0.5 + val*0.5;
}

//initialization
var jg;
autoBalance = balanceSwitch.checked;
intMode = dataTypeSwitch.checked;
xTreeOffset = 50;
yTreeOffset = 50;
xOffset = 300;
yOffset = 250;
blockWidth = 250;
blockHeight = 150;
maxX = 0;
maxY = 0;
tree = new BinaryTree(comparator);
// tree.insert(0);
// tree.insert(10);
// tree.insert(8);
// tree.insert(15);
// tree.insert(13);
// tree.insert(20);

drawTree(tree);
