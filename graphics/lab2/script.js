var step = 0.0001;
var graphicsSize = 600;
var gridFreq = 10;
var graphVal = 10;
var graphicThickness = 1;
var accurancy = 0;
var textSize = 16;
var color = "red";
var dotSize = 5;
var dotColor = "DodgerBlue";
var offset = 1;

var eps = 0.3;

var gridSize = graphicsSize/(gridFreq*2);

var inputCoords;
var inputVal;

var isAnimated = false;
var animationTimer;

var data = [];
var convertedData = [];
var animatedData = [];

var transformMatrix = regularMatrix();

const MODES = {REGULAR: 1, MOVE: 2, SCALE: 3, REFLECT: 4, ROTATE: 5};

var mode = MODES.REGULAR;

function drawAxis(ctx, x, y, size) {
    ctx.stroke();
    ctx.lineWidth = 3;
    ctx.beginPath();
    ctx.moveTo(x, y + size/2);
    ctx.lineTo(x + size, y + size/2);
    ctx.moveTo(x + size, y + size/2);
    ctx.lineTo(x + size-10, y + size/2+5)
    ctx.moveTo(x + size, y + size/2);
    ctx.lineTo(x + size-10, y + size/2-5)
    ctx.moveTo(x+size/2, y);
    ctx.lineTo(x+size/2, y+size);
    ctx.moveTo(x+size/2, y);
    ctx.lineTo(x+size/2-5, y+10)
    ctx.moveTo(x+size/2, y);
    ctx.lineTo(x+size/2+5, y+10)
    ctx.stroke();
}

function drawLabels(ctx, x, y, size, maxVal, gridStep, gridSize, n) {
    for (let i = 1; i < 2*n; i++) {
        ctx.textAlign = "center";
        ctx.fillText((-maxVal+(i*gridStep)).toFixed(accurancy), x+i*gridSize-10, y+size/2+15);
        ctx.textAlign = "right";
        if (maxVal-i*gridStep != 0) ctx.fillText((maxVal-i*gridStep).toFixed(accurancy), x+size/2-5, y+i*gridSize+15);
    }
    ctx.strokeRect(x, y, size, size);
    ctx.textAlign = "center";
    ctx.fillText("x", x+size-10, y+size/2+15);
    ctx.textAlign = "right";
    ctx.fillText("y", x+size/2-5, y+15);
}

function drawDecFigure(ctx, x, y, size, n, maxVal, d) {
    ctx.strokeStyle = "black";
    ctx.beginPath();
    ctx.lineWidth = 1;
    let gridStep = maxVal/n;
    for (let i = -n+1; i < n; i++) {
        ctx.moveTo(x, y + size/2 + gridSize*i);
        ctx.lineTo(x + size, y + size/2 + gridSize*i);
        ctx.moveTo(x + size/2 + gridSize*i, y);
        ctx.lineTo(x + size/2 + gridSize*i, y + size);
    }
    ctx.stroke();

    drawAxis(ctx, x, y, size)

    drawLabels(ctx, x, y, size, maxVal, gridStep, gridSize, n)

    ctx.beginPath();
    ctx.strokeStyle = color;
    let screenCoord1;
    let screenCoord2;
    for (let i = 1; i < data.length; i++) {
        screenCoord1 = toScreen(d[i-1][0], d[i-1][1]);
        screenCoord2 = toScreen(d[i][0], d[i][1]);
        ctx.moveTo(x+screenCoord1[0], y+screenCoord1[1]);
        ctx.lineTo(x+screenCoord2[0], y+screenCoord2[1]);
    }
    if (data.length > 0) {
        screenCoord1 = toScreen(d[0][0], d[0][1]);
        screenCoord2 = toScreen(d[d.length-1][0], d[d.length-1][1]);
        ctx.moveTo(x+screenCoord1[0], y+screenCoord1[1]);
        ctx.lineTo(x+screenCoord2[0], y+screenCoord2[1]);
    }
    ctx.stroke();

    for (let i = 0; i < d.length; i++) {
        let screenCoord = toScreen(d[i][0], d[i][1]);
        drawDot(ctx, x+screenCoord[0], y+screenCoord[1], i+1);
    }
    
}

function drawDot(ctx, x, y, label) {
    ctx.beginPath();
    ctx.fillStyle = dotColor;
    ctx.strokeStyle = dotColor;
    ctx.arc(x, y, dotSize, 0, 2 * Math.PI);
    ctx.textAlign = "center";
    ctx.fillText(label, x+10, y-dotSize-2)
    ctx.fill();
    ctx.stroke();
    ctx.fillStyle = "black";
    ctx.strokeStyle = "black";
}



var canvas1 = document.getElementById("canv1");
canvas1.width = offset*2+graphicsSize;
canvas1.height = graphicsSize + offset*2;

var context1 = canvas1.getContext('2d');
context1.translate(0.5, 0.5);
context1.font = textSize + "px sans-serif";
context1.strokeStyle = "black";
context1.lineCap = "square";

var canvas2 = document.getElementById("canv2");
canvas2.width = offset*2+graphicsSize;
canvas2.height = graphicsSize + offset*2;

var context2 = canvas2.getContext('2d');
context2.translate(0.5, 0.5);
context2.font = textSize + "px sans-serif";
context2.strokeStyle = "black";
context2.lineCap = "square";

var transformTable = document.querySelector("#matrix-table > tbody");

drawDecFigure(context1, offset, offset, graphicsSize, gridFreq, graphVal, data);
drawDecFigure(context2, offset, offset, graphicsSize, gridFreq, graphVal, convertedData);

canvas1.addEventListener("click", setDot);

let resetButton = document.getElementById("reset");
resetButton.addEventListener("click", ()=>{
    if (isAnimated) {
        disableAnimation();
    }
    data = [];
    convertedData = [];
    redraw();
    updateDotsTable();
    transformMatrix = regularMatrix();
    mode = MODES.REGULAR;
    fillTransformTable();
});

let enterButton = document.getElementById("enter");
enterButton.addEventListener("click", ()=>{
    redraw();
    updateDotsTable();
});

let moveButton = document.getElementById("move");
moveButton.addEventListener("click", ()=>{
    if (isAnimated) {
        disableAnimation();
    }
    mode = MODES.MOVE;
    canvas1.removeEventListener("click", setDot);
    canvas1.removeEventListener("click", chooseDot);
    canvas1.addEventListener("click", chooseCoord);
});

let scaleButton = document.getElementById("scale");
let coeffButton = document.getElementById("coeff-input");
scaleButton.addEventListener("click", ()=>{
    if (isAnimated) {
        disableAnimation();
    }
    mode = MODES.SCALE;
    
    canvas1.removeEventListener("click", setDot);
    canvas1.removeEventListener("click", chooseDot);
    canvas1.addEventListener("click", chooseCoord);
});

let rotateButton = document.getElementById("rotate");
let angleField = document.getElementById("angle-input");
rotateButton.addEventListener("click", ()=>{
    if (isAnimated) {
        disableAnimation();
    }
    mode = MODES.ROTATE;
    canvas1.removeEventListener("click", setDot);
    canvas1.removeEventListener("click", chooseCoord);
    canvas1.addEventListener("click", chooseDot);
});

let reflectButton = document.getElementById("reflect");
reflectButton.addEventListener("click", ()=>{
    if (isAnimated) {
        disableAnimation();
    }
    mode = MODES.REFLECT;
    canvas1.removeEventListener("click", setDot);
    canvas1.removeEventListener("click", chooseCoord);
    canvas1.addEventListener("click", chooseDot);
});

let dynamicButton = document.getElementById("dynamic");
let timeInput = document.getElementById("time-input");
dynamicButton.addEventListener("click", ()=>{
    if (isAnimated) {
        disableAnimation();
    } else {
        isAnimated = true;
        animatedData = data;
        let time = parseInt(timeInput.value, 10);
        if (!time) {
            time = 1000;
        }
        animationTimer = setInterval(drawAnimation, time);
        canvas1.removeEventListener("click", setDot);
        
    }
});

function drawAnimation() {
    context2.clearRect(0, 0, canvas2.width, canvas2.height);
    doTransform();
    drawDecFigure(context2, offset, offset, graphicsSize, gridFreq, graphVal, animatedData);
}

function disableAnimation() {
    isAnimated = false;
    clearTimeout(animationTimer);
    canvas1.addEventListener("click", setDot);
    redraw();
}

function redraw() {
    context1.clearRect(0, 0, canvas1.width, canvas1.height);
    context2.clearRect(0, 0, canvas2.width, canvas2.height);
    drawDecFigure(context1, offset, offset, graphicsSize, gridFreq, graphVal, data);
    doTransform();
    drawDecFigure(context2, offset, offset, graphicsSize, gridFreq, graphVal, convertedData);
    updateDotsTable();
};

function toGraph(screenX, screenY) {
    let graphX = (screenX - graphicsSize/2) / gridSize;
    let graphY = -(screenY - graphicsSize/2) / gridSize;
    return [graphX, graphY];
}

function toScreen(graphX, graphY) {
    let screenX = graphX * gridSize + graphicsSize/2;
    let screenY = -(graphY * gridSize) + graphicsSize/2;
    return [screenX, screenY];
}

function updateDotsTable() {
    let table = document.querySelector("#dots-table > tbody");
    table.innerHTML = "";
    for (let i = 0; i < data.length; i++) {
        let row = document.createElement("tr");
        let dot = document.createElement("td");
        dot.textContent = i+1;
        let x1 = document.createElement("td");
        x1.textContent = data[i][0].toFixed(3);
        let y1 = document.createElement("td");
        y1.textContent = data[i][1].toFixed(3);
        let x2 = document.createElement("td");
        x2.textContent = convertedData[i][0].toFixed(3);
        let y2 = document.createElement("td");
        y2.textContent = convertedData[i][1].toFixed(3);
        row.appendChild(dot);
        row.appendChild(x1);
        row.appendChild(y1);
        row.appendChild(x2);
        row.appendChild(y2);
        table.appendChild(row);
    }
}

function matrixMul(a, b) {
    let r = [];
    for (let i = 0; i < a.length; i++) {
        r.push([]);
        for (let j = 0; j < b[0].length; j++) {
            let s = 0;
            for (let x = 0; x < b.length; x++) {
                s += a[i][x] * b[x][j];
            }
            r[i][j] = s;
        }
    }
    return r;
}

function degToRad(deg) {
  return deg * (Math.PI/180);
}

function scaleMatrix(a, b) {
    return [[a, 0, 0],
            [0, b, 0],
            [0, 0, 1]];
}

function rotateMatrix(deg) { // против часовой
    let a = degToRad(deg);
    return [[Math.cos(a), -Math.sin(a), 0],
            [Math.sin(a), Math.cos(a), 0],
            [0, 0, 1]];
}

function moveMatrix(a, b) {
    return [[1, 0, 0],
            [0, 1, 0],
            [a, b, 1]];
}

function reflectMatrix() {
    return scaleMatrix(-1, -1);
}

function regularMatrix() {
    return [[1, 0, 0],
            [0, 1, 0],
            [0, 0, 1]];
}

function getDot(dot) {
    let x = dot[0];
    let y = dot[1];
    for (let i = 0; i < data.length; i++) {
        if (Math.abs(x-data[i][0]) <= eps && Math.abs(y-data[i][1]) <= eps) {
            return data[i];
        }
    }
    return undefined;
}

function chooseDot(event) {
    if (event.offsetX < offset || event.offsetY < offset || event.offsetX > graphicsSize+offset || event.offsetY > graphicsSize+offset) {
        return;
    }
    let clickX = event.offsetX - offset;
    let clickY = event.offsetY - offset;
    let dotCoord = toGraph(clickX, clickY);
    let d = getDot(dotCoord);
    if (d != undefined) {
        inputCoords = d;
        canvas1.removeEventListener("click", chooseDot);
        canvas1.addEventListener("click", setDot);
        redraw();
    }
}

function chooseCoord(event) {
    if (event.offsetX < offset || event.offsetY < offset || event.offsetX > graphicsSize+offset || event.offsetY > graphicsSize+offset) {
        return;
    }
    let clickX = event.offsetX - offset;
    let clickY = event.offsetY - offset;
    let dotCoord = toGraph(clickX, clickY);
    inputCoords = dotCoord;
    canvas1.removeEventListener("click", chooseCoord);
    canvas1.addEventListener("click", setDot);
    redraw();
}

function setDot(event) {
    if (event.offsetX < offset || event.offsetY < offset || event.offsetX > graphicsSize+offset || event.offsetY > graphicsSize+offset) {
        return;
    }
    drawDot(context1, event.offsetX, event.offsetY, data.length+1);
    let clickX = event.offsetX - offset;
    let clickY = event.offsetY - offset;
    let dotCoord = toGraph(clickX, clickY);
    data.push([dotCoord[0], dotCoord[1], 1]);
    convertedData.push([0, 0, 1]);
    updateDotsTable();
}

function doTransform() {
    switch (mode) {
        case MODES.REGULAR:
            transformMatrix = regularMatrix();
            break;
        case MODES.MOVE:
            transformMatrix = moveMatrix(inputCoords[0], inputCoords[1]);
            break;
        case MODES.SCALE:
            inputVal = parseFloat(coeffButton.value, 10);
            if (!inputVal)  {
                inputVal = 1;
            }
            let l = Math.sqrt(inputCoords[0]**2 + inputCoords[1]**2);
            inputCoords[0] = inputCoords[0]/l;
            inputCoords[1] = inputCoords[1]/l;
            transformMatrix = scaleMatrix(inputCoords[0]*inputVal, inputCoords[1]*inputVal);
            break;
        case MODES.REFLECT:
            transformMatrix = matrixMul(moveMatrix(-inputCoords[0], -inputCoords[1]), matrixMul(reflectMatrix(), moveMatrix(inputCoords[0], inputCoords[1])));
            break;
        case MODES.ROTATE:
            inputVal = parseInt(angleField.value, 10);
            transformMatrix = matrixMul(moveMatrix(-inputCoords[0], -inputCoords[1]), matrixMul(rotateMatrix(inputVal), moveMatrix(inputCoords[0], inputCoords[1])));
            break;
    }
    if (isAnimated) {
        animatedData = matrixMul(animatedData, transformMatrix);
    } else {
        convertedData = matrixMul(data, transformMatrix);
    }
    fillTransformTable()
}

function fillTransformTable() {
    let i = 0;
    
    for (let tr of transformTable.children) {
        let j = 0;
        for (let td of tr.children) {
            td.innerHTML = transformMatrix[i][j].toFixed(3)
            j++
        }
        i++;
    }
}
fillTransformTable()