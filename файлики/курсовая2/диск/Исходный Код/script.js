function comparator(a, b) { // Функция для сравнения данных из узлов дерева
    return (b<a) - (a<b);
}

class BinaryTree {
    root
    comparator
    IDArray
    constructor(comparator) {
        this.IDArray = [];
        this.comparator = comparator;
    }

    insert(value) { // Вставка значения в дерево
        if (this.root == null) {
            this.root = new BinaryTreeNode(value, this.comparator, this.IDArray.length);
            this.IDArray.push(this.root);
            if (animation) newNodesTrace.push([this.root, "marked-green"]);
            setTypeChange(false);
            setAutoBalanceChange(false);
            setDuplicateChange(false);
            return this.root;
        } else {
            
            let node = this.root.insert(value, this.IDArray.length);
            if (node) this.IDArray.push(node);
            return node;
        }
    }

    find(value) { // Поиск узла по значению
        return this.root.find(value);
    }

    recalculateCounts() { // Пересчёт значения количества вершин в поддереве от корня к листьям
        this.root.recalculateCountDown();
    }

    removeByID(id) { // Удаление узла по ID
        if (this.root == null) return;
        const nodeToRemove = this.IDArray[id];
        animationTrace.push([nodeToRemove.DOMLink, "marked-red"]);

        if (nodeToRemove == null) {
            console.log("Tree with id " + id + " is not found.");
            return false;
        }

        const parent = nodeToRemove.parent;
        if (!nodeToRemove.left && !nodeToRemove.right) {
            if (parent) {
                this.IDArray[nodeToRemove.ID] = null;
                parent.removeChild(nodeToRemove);
                if (autoBalance) nodeToRemove.recalculateAndRebalanceUp();
                else nodeToRemove.recalculateUp();
            } else {
                this.IDArray[this.root.ID] = null;
                this.root = null;
                setTypeChange(true);
                setAutoBalanceChange(true);
                setDuplicateChange(true)
            }
        } else if (nodeToRemove.left && nodeToRemove.right) {
            const newNode = nodeToRemove.right.findMin();
            if (newNode === nodeToRemove.right) {
                this.IDArray[nodeToRemove.ID] = null;
                nodeToRemove.value = nodeToRemove.right.value;
                nodeToRemove.ID = nodeToRemove.right.ID;
                nodeToRemove.right = nodeToRemove.right.right;
                this.IDArray[nodeToRemove.ID] = nodeToRemove;
                if (autoBalance) nodeToRemove.recalculateAndRebalanceUp();
                else nodeToRemove.recalculateUp();
                
            } else {
                this.removeByID(newNode.ID);
                this.IDArray[nodeToRemove.ID] = null;
                if (autoBalance) nodeToRemove.recalculateAndRebalanceUp();
                else nodeToRemove.recalculateUp();
                nodeToRemove.value = newNode.value;
                nodeToRemove.ID = newNode.ID;
                this.IDArray[nodeToRemove.ID] = nodeToRemove;
            }
        } else {
            const childNode = nodeToRemove.left || nodeToRemove.right;
            if (animation) animationTrace.push([childNode.DOMLink, "marked-green"]);
            if (parent) {
                this.IDArray[nodeToRemove.ID] = null;
                parent.replaceChild(nodeToRemove, childNode);  //++++
                if (autoBalance) nodeToRemove.recalculateAndRebalanceUp();
                else nodeToRemove.recalculateUp();
            } else {
                this.IDArray[this.root.ID] = null;
                this.root = childNode;
                this.root.parent = null;
            }
        }
        return true;
    }

    remove(value) { // Удаление узла по значению
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
                if (autoBalance) nodeToRemove.recalculateAndRebalanceUp();
                else nodeToRemove.recalculateUp();
            } else {
                this.IDArray[this.root.ID] = null;
                this.root = null;
                setTypeChange(true);
                setAutoBalanceChange(true);
                setDuplicateChange(true)
            }
        } else if (nodeToRemove.left && nodeToRemove.right) {
            const newNode = nodeToRemove.right.findMin();
            if (newNode === nodeToRemove.right) {
                this.IDArray[nodeToRemove.ID] = null;
                nodeToRemove.value = nodeToRemove.right.value;
                nodeToRemove.ID = nodeToRemove.right.ID;
                nodeToRemove.right = nodeToRemove.right.right;
                this.IDArray[nodeToRemove.ID] = nodeToRemove;
                if (autoBalance) nodeToRemove.recalculateAndRebalanceUp();
                else nodeToRemove.recalculateUp();
                
            } else {
                this.removeByID(newNode.ID);
                this.IDArray[nodeToRemove.ID] = null;
                if (autoBalance) nodeToRemove.recalculateAndRebalanceUp();
                else nodeToRemove.recalculateUp();
                nodeToRemove.value = newNode.value;
                nodeToRemove.ID = newNode.ID;
                this.IDArray[nodeToRemove.ID] = nodeToRemove;
            }
        } else {
            const childNode = nodeToRemove.left || nodeToRemove.right;
            if (animation) animationTrace.push([childNode.DOMLink, "marked-green"]);
            if (parent) {
                this.IDArray[nodeToRemove.ID] = null;
                parent.replaceChild(nodeToRemove, childNode);
                if (autoBalance) nodeToRemove.recalculateAndRebalanceUp();
                else nodeToRemove.recalculateUp();
            } else {
                this.IDArray[this.root.ID] = null;
                this.root = childNode;
                this.root.parent = null;
            }
        }
        return true;

    }

    createSaveString() { // Создание строки из дерева для последующего сохранения в файл
        let res = (+autoBalance).toString() + "|" + (+intMode).toString() + "|" + (+duplicate).toString();
        if (this.root) res += "|" + this.root.createSaveString();
        return res;
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
    DOMLink;
    constructor(value, comparator, ID) {
        this.value = value;
        this.comparator = comparator;
        this.ID = ID;
    }

    insert(value, ID) { // Рекурсивная вставка в поддерево и присвоение ID
        this.count++;
        if (animation) animationTrace.push([this.DOMLink, "marked-yellow"]);
        if ((duplicate && this.comparator(value, this.value) == 0) || (this.comparator(value, this.value) < 0)) {
            if (this.left) {
                let node = this.left.insert(value, ID);
                if (autoBalance) this.balance();
                return node;
            }
            this.left = new BinaryTreeNode(value, this.comparator, ID);
            if (animation) newNodesTrace.push([this.left, "marked-green"]);
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
            if (animation) newNodesTrace.push([this.right, "marked-green"]);
            this.right.parent = this;
            if (autoBalance) this.balance();
            return this.right;
        }
        this.count--;
        return null;
    }

    find(value) { // Поиск значения в поддереве
        if (this.comparator(this.value, value) === 0) {
            if (animation) animationTrace.push([this.DOMLink, "marked-red"]);
            return this;
        }
 
        if (this.comparator(this.value, value) > 0 && this.left) {
            if (animation) animationTrace.push([this.DOMLink, "marked-yellow"]);
            return this.left.find(value);
        }

        if (this.comparator(this.DOMLink.value, value) <= 0 && this.right) {
            if (animation) animationTrace.push([this.DOMLink, "marked-yellow"]);
            return this.right.find(value);
        }

        return null;
    }

    findMin() { // Поиск минимального элемента в поддереве
        if (!this.left) {
            if (animation) animationTrace.push([this.DOMLink, "marked-green"]);
            return this;
        }
        if (animation) animationTrace.push([this.DOMLink, "marked-yellow"]);
        return this.left.findMin();
    }

    removeChild(nodeToRemove) { // Удадение дочернего узла
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

    replaceChild(nodeToReplace, replacementNode) { // Замена дочернего узла
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

    recalculateAndRebalanceUp() { // Пересчёт кол-ва узлов в поддереве и балансировка от листа к корню
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

    recalculateUp() { // Пересчёт кол-ва узлов в поддеревеа от листа к корню
        this.count = 1;
        if (this.left) {
            this.count += this.left.count;
        }

        if (this.right) {
            this.count += this.right.count;
        }
    }

    recalculateCountDown() { // Пересчёт кол-ва узлов в поддеревеа от корня к листьям
        this.count = 1;
        if (this.left) {
            this.count += this.left.recalculateCountDown();
        }

        if (this.right) {
            this.count += this.right.recalculateCountDown();
        }
        return this.count;
    }

    rotateLeft() { // Малый левый поворот поддерева
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
        if (animation) newNodesTrace.push([b, "marked-yellow"]);
        this.recalculateCountDown();
    }

    rotateRight() { // Малый правый поворот
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
        if (animation) newNodesTrace.push([b, "marked-yellow"]);
        this.recalculateCountDown();
    }

    bigRotateLeft() { // Большой левый поворот
        this.right.rotateRight()
        this.rotateLeft()
    }

    bigRotateRight() { // Большой правый поворот
        this.left.rotateLeft()
        this.rotateRight()
    }

    getHeight() { // Получение глубины поддерева
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



    balance() { // Балансировка поддерева
        let rightHeight = 0
        let leftHeight = 0
        if (this.right) rightHeight = this.right.getHeight();
        if (this.left) leftHeight = this.left.getHeight();
        let bal = rightHeight - leftHeight;

        if (bal >= 2) { //left
            if (animation) newNodesTrace.push([this, "marked-red"]);
            let subRightHeight = 0;
            let subLeftHeight = 0;
            if (this.right.right) subRightHeight = this.right.right.getHeight();
            if (this.right.left) subLeftHeight = this.right.left.getHeight();

            if (subLeftHeight <= subRightHeight) this.rotateLeft();
            else this.bigRotateLeft();

        } else if (bal <= -2) { //right
            if (animation) newNodesTrace.push([this, "marked-red"]);
            let subRightHeight = 0;
            let subLeftHeight = 0;
            if (this.left.right) subRightHeight = this.left.right.getHeight();
            if (this.left.left) subLeftHeight = this.left.left.getHeight();

            if (subRightHeight <= subLeftHeight) this.rotateRight();
            else this.bigRotateRight();
        }
    }

    createSaveString() { // Создание строки из узла для последующего сохранения в файл
        if (this.left) saveQueue.push(this.left);
        if (this.right) saveQueue.push(this.right);
        if (saveQueue.length == 0) {
            if (intMode) return this.value.toString();
            else return this.value.join(" ");
        } else {
            if (intMode) return this.value.toString() + "|" + saveQueue.shift().createSaveString();
            else return this.value.join(" ") + "|" + saveQueue.shift().createSaveString();
        }
        
    }
}

// Управление и навигация по дереву
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
    const dx = e.clientX - pos.x;
    const dy = e.clientY - pos.y;

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

// Функции отрисовки дерева
function drawNode(node, x, y) {
    let block = document.createElement('div');
    block.classList.add('block');
    block.style.left = x+"px";
    block.style.top = y+"px";
    block.style.height = blockHeight+"px";
    block.style.width = blockWidth+"px";
    let blockVal = document.createElement("div");
    blockVal.classList.add('block-value');
    let blockInfo = document.createElement("div");
    blockInfo.classList.add('block-info');
    let stringValue;
    if (intMode) stringValue = node.value.toString();
    else stringValue = node.value.join(" ");
    if (stringValue.length > 45) blockVal.style.fontSize = "16px";
    if (stringValue.length > 70) stringValue = stringValue.slice(0, 69) + "...";
    blockVal.textContent = "value: " + stringValue;
    blockInfo.textContent = "count: " + node.count + "; ID: " + node.ID;
    block.appendChild(blockVal);
    block.appendChild(blockInfo);
    content.appendChild(block);
    node.DOMLink = block;
}

function drawTree(tree) {
    content.innerHTML = '';
    jg = new jsGraphics(content);
    jg.setColor("#1ac2c2");
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

// Функции для обработки взаимодействия с интерфейсом
function addNode() {
    stopAnimation();
    let input = document.getElementById("new-node-input");
    let value = input.value;
    let res;
    if (intMode && isNaN(value) || value == '') {
        input.classList.add("wrong-input-animation");
        input.onanimationend = () => {input.classList.remove("wrong-input-animation");};
    } else if (intMode) {
        res = tree.insert(parseInt(value, 10));
        if (res) {
            if (animation) animate();
            else drawTree(tree);
        } else {
            input.classList.add("wrong-input-animation");
            input.onanimationend = () => {input.classList.remove("wrong-input-animation");};
        } 
    } else {
        res = tree.insert(value.split(" "));
        if (res) {
            if (animation) animate();
            else drawTree(tree);
        } else {
            input.classList.add("wrong-input-animation");
            input.onanimationend = () => {input.classList.remove("wrong-input-animation");};
        } 
    }
}

function removeNode() {
    stopAnimation();
    let input = document.getElementById("remove-node-input");
    let value = input.value;
    if (value == "" || (intMode && isNaN(value)) || tree.root == null) {
        input.classList.add("wrong-input-animation");
        input.onanimationend = () => {input.classList.remove("wrong-input-animation");};
    } else if (intMode) {
        tree.remove(parseInt(value, 10));
        if (animation) animate();
        else drawTree(tree);
    } else {
        tree.remove(value.split(" "));
        if (animation) animate();
        else drawTree(tree)
    }
}

function removeNodeByID(id = -1) {
    stopAnimation();
    if (id < 0) {
        let input = document.getElementById("remove-id-node-input");
        id = parseInt(input.value, 10);
        if (id.isNaN || id < 0 || tree.IDArray[id] == null) {
            input.classList.add("wrong-input-animation");
            input.onanimationend = () => {input.classList.remove("wrong-input-animation");};
        } else {
            tree.removeByID(id);
            if (animation) animate();
            else drawTree(tree)
        }
    } else if (tree.IDArray[id] != null) {
        tree.removeByID(id);
        if (animation) animate();
        else drawTree(tree)
    }

}

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

duplicateSwitch = document.getElementById("duplicate-input");
duplicateSwitch.addEventListener("change", ()=>{
    if (!tree.root) {
        duplicate = duplicateSwitch.checked;
    }
});

function setDuplicateChange(val) {
    duplicateSwitch.disabled = !val;
    duplicateSwitch.parentElement.style.opacity = 0.5 + val*0.5;
}

scaleSlider = document.getElementById("scale-input");
scaleSlider.value = 1;
scaleSlider.addEventListener("change", () => {
    content.style.scale = scaleSlider.value;
});

animationSwitch = document.getElementById("animation-input");
animationSwitch.addEventListener("change", ()=>{
    stopAnimation();
    animation = animationSwitch.checked;
});

function download() {
    stopAnimation()
    let text = tree.createSaveString();
    let element = document.createElement('a');
    element.setAttribute('href', 'data:text/plain;charset=utf-8,' + encodeURIComponent(text));
    element.setAttribute('download', "tree.txt");
      
    element.style.display = 'none';
    document.body.appendChild(element);
      
    element.click();
      
    document.body.removeChild(element);
};

let fileInput = document.getElementById("file-input");

fileInput.addEventListener("change", () => {
    let text = fileInput.files[0].name;
    if (text.length > 15) text = text.slice(0, 14) + "...";
    document.querySelector("#input-file-wrapper > p").textContent = text;
});

function load() {
    stopAnimation()
    let fr = new FileReader();
    let file = fileInput.files[0];
    fr.readAsText(file);
    fr.onload = function () {
        let str = fr.result;
        let input = str.split("|");
        if (!isNaN(parseInt(input[0], 10)) && !isNaN(parseInt(input[1], 10)) && !isNaN(parseInt(input[2], 10))) {
            autoBalance = !!parseInt(input[0], 10);
            intMode = !!parseInt(input[1], 10);
            duplicate = !!parseInt(input[2], 10);
            balanceSwitch.checked = autoBalance;
            dataTypeSwitch.checked = intMode;
            duplicateSwitch.checked = duplicate;
        } else {
            fileInput.classList.add("wrong-input-animation");
            fileInput.onanimationend = () => {fileInput.classList.remove("wrong-input-animation");};
            return;
        }
        deleteAll();
        for (let i = 3; i < input.length; i++) {
            if (intMode && isNaN(parseInt(input[i], 10))) {
                fileInput.classList.add("wrong-input-animation");
                fileInput.onanimationend = () => {fileInput.classList.remove("wrong-input-animation");};
                deleteAll();
                return;
            }
            let res;
            if (intMode) {
                res = tree.insert(parseInt(input[i], 10));
            } else {
                res = tree.insert(input[i].split(" "));
            }
            if (res) {
                drawTree(tree);
            } else {
                fileInput.classList.add("wrong-input-animation");
                fileInput.onanimationend = () => {fileInput.classList.remove("wrong-input-animation");};
                deleteAll();
            }
        }
    }; 
}

function deleteAll() {
    tree = new BinaryTree(comparator);
    autoBalance = balanceSwitch.checked;
    intMode = dataTypeSwitch.checked;
    duplicate = duplicateSwitch.checked;
    setTypeChange(true);
    setAutoBalanceChange(true);
    setDuplicateChange(true);
    drawTree(tree);
}

var treeDrawed = false;
function animate() {
    if (animationTrace.length > 0) {
        let item = animationTrace[0];
        item[0].classList.add(item[1]);
    } else if (newNodesTrace.length > 0) {
        drawTree(tree);
        treeDrawed = true;
        let item = newNodesTrace[0];
        item[0].DOMLink.classList.add(item[1]);
    }
    treeDrawed = false;
    animationTimer = setInterval(()=>{
        if (animationTrace.length > 0) {
            let item = animationTrace.shift();
            item[0].classList.remove(item[1]);
        }
        if (animationTrace.length > 0) {
            let item = animationTrace[0];
            item[0].classList.add(item[1]);
        } else if (!treeDrawed){
            drawTree(tree);
            treeDrawed = true;
            if (newNodesTrace.length > 0) {
                let item = newNodesTrace[0];
                item[0].DOMLink.classList.add(item[1]);
            }
        } else if (newNodesTrace.length > 0) {
            let item = newNodesTrace.shift();
            item[0].DOMLink.classList.remove(item[1]);
            if (newNodesTrace.length > 0) {
                let item = newNodesTrace[0];
                item[0].DOMLink.classList.add(item[1]);
            }
        } else {
            stopAnimation();
        }
    }, animationTime);
}

function stopAnimation() {
    clearInterval(animationTimer);
    if (animationTrace.length > 0) {
        animationTrace[0][0].classList.remove(animationTrace[0][1]);
    } else if (newNodesTrace.length > 0) {
        newNodesTrace[0][0].DOMLink.classList.remove(newNodesTrace[0][1]);
    }
    animationTrace = [];
    newNodesTrace = [];
    drawTree(tree);
}

// Инициализация дерева и его параметров
var jg;
var autoBalance = balanceSwitch.checked;
var intMode = dataTypeSwitch.checked;
var duplicate = duplicateSwitch.checked;
var animation = animationSwitch.checked;
var animationTrace = [];
var newNodesTrace = [];
var animationTime = 500;
var animationTimer;
var xTreeOffset = 50;
var yTreeOffset = 50;
var xOffset = 300;
var yOffset = 250;
var blockWidth = 250;
var blockHeight = 150;
var maxX = 0;
var maxY = 0;
let tree = new BinaryTree(comparator);
var saveQueue = [];

// Начальная отрисовка дерева
drawTree(tree);
