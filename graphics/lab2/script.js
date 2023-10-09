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
var offset = 10;

var gridSize = graphicsSize/(gridFreq*2);

function drawAxis(x, y, size) {
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

function drawLabels(x, y, size, maxVal, gridStep, gridSize, n) {
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

function drawDecFigure(x, y, size, n, maxVal, data) {
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

    drawAxis(x, y, size)

    drawLabels(x, y, size, maxVal, gridStep, gridSize, n)

    ctx.beginPath();
    ctx.strokeStyle = color;
    let screenCoord1;
    let screenCoord2;
    for (let i = 1; i < data.length; i++) {
        screenCoord1 = toScreen(data[i-1][0], data[i-1][1]);
        screenCoord2 = toScreen(data[i][0], data[i][1]);
        ctx.moveTo(x+screenCoord1[0], y+screenCoord1[1]);
        ctx.lineTo(x+screenCoord2[0], y+screenCoord2[1]);
    }
    if (data.length > 0) {
        screenCoord1 = toScreen(data[0][0], data[0][1]);
        screenCoord2 = toScreen(data[data.length-1][0], data[data.length-1][1]);
        ctx.moveTo(x+screenCoord1[0], y+screenCoord1[1]);
        ctx.lineTo(x+screenCoord2[0], y+screenCoord2[1]);
    }
    ctx.stroke();

    for (let i = 0; i < data.length; i++) {
        let screenCoord = toScreen(data[i][0], data[i][1]);
        drawDot(x+screenCoord[0], y+screenCoord[1], i+1);
    }
    
}

function drawDot(x, y, label) {
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

var data = [];
var convertedData = [];

var transformMatrix = regularMatrix();

var canvas = document.getElementById("graphics");
canvas.width = offset*3+graphicsSize*2;
canvas.height = graphicsSize + offset*2;

var ctx = canvas.getContext('2d');
ctx.translate(0.5, 0.5);
ctx.font = textSize + "px sans-serif";
ctx.strokeStyle = "black";
ctx.lineCap = "square";

drawDecFigure(offset, offset, graphicsSize, gridFreq, graphVal, data);
drawDecFigure(offset*2+graphicsSize, offset, graphicsSize, gridFreq, graphVal, convertedData);

canvas.addEventListener("click", (event)=>{
    if (event.offsetX < offset || event.offsetY < offset || event.offsetX > graphicsSize+offset || event.offsetY > graphicsSize+offset) {
        return;
    }
    drawDot(event.offsetX, event.offsetY, data.length+1);
    let clickX = event.offsetX - offset;
    let clickY = event.offsetY - offset;
    let dotCoord = toGraph(clickX, clickY);
    data.push(dotCoord);
    convertedData.push([0, 0]);  // ****
    updateDotsTable();
});

let resetButton = document.getElementById("reset");
resetButton.addEventListener("click", ()=>{
    data = [];
    convertedData = [];
    redraw();
    updateDotsTable();
});

let enterButton = document.getElementById("enter");
enterButton.addEventListener("click", ()=>{
    redraw();
    updateDotsTable();
});



function redraw() {
    transformMatrix = scaleMatrix(5, 5);
    ctx.clearRect(0, 0, canvas.width, canvas.height);
    drawDecFigure(offset, offset, graphicsSize, gridFreq, graphVal, data);
    convert(transformMatrix);
    drawDecFigure(offset*2+graphicsSize, offset, graphicsSize, gridFreq, graphVal, convertedData);
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

function getNewCoords(coords, matrix) {
    let r = matrixMul(matrix, [[coords[0]], [coords[1]], [1]]);
    return [r[0][0], r[1][0]];
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
    return [[1, 0, a],
            [0, 1, b],
            [0, 0, 1]];
}

function reflectMatrix() {
    return scaleMatrix(-1, -1);
}

function regularMatrix() {
    return [[1, 0, 0],
            [0, 1, 0],
            [0, 0, 1]];
}

function convert(matrix) {
    for (let i = 0; i < data.length; i++) {
        convertedData[i] = getNewCoords(data[i], matrix);
    }
}