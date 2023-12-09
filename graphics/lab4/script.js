var graphicsSize = 450;
var gridFreq = 5;
var graphVal = 5;
var graphicThickness = 1;
var accurancy = 0;
var textSize = 18;
var color = "red";
var dotSize = 5;
var vectorColor = "DodgerBlue";
var offset = 1;
var gridSize = graphicsSize/(gridFreq*2);
var dots = [];
var rotatedDots = [];
var lines = [];
var rotateAngle = 0;
var rotateAngleDeg = 0;
var rotateAngleTransitionTo = 0;
var projectionAngle = 0;
var projectionAngleDeg = 0;
var projectionAngleTransitionTo = 0;
var projectionVector = [0, 0, 1, 1];
var distance = 0;
var distanceTransitionTo = 0;
var xzAngle;
var xzAngleDeg = 90;
var xzAngleTransitionTo = 90;

var animationTimer = null;

var transformMatrix = parallelMatrix();
const AXIS = ["x", "y", "z"];

function drawAxis(ctx, x, y, size) {
    ctx.stroke();
    ctx.lineWidth = 3;
    ctx.beginPath();
    ctx.moveTo(x, y + size/2);
    ctx.lineTo(x + size, y + size/2);
    ctx.moveTo(x + size, y + size/2);
    ctx.lineTo(x + size-10, y + size/2+5);
    ctx.moveTo(x + size, y + size/2);
    ctx.lineTo(x + size-10, y + size/2-5);
    ctx.moveTo(x+size/2, y);
    ctx.lineTo(x+size/2, y+size);
    ctx.moveTo(x+size/2, y);
    ctx.lineTo(x+size/2-5, y+10);
    ctx.moveTo(x+size/2, y);
    ctx.lineTo(x+size/2+5, y+10);
    ctx.stroke();
}

function drawLabels(ctx, x, y, size, maxVal, gridStep, gridSize, n, xid, yid) {
    for (let i = 1; i < 2*n; i++) {
        ctx.textAlign = "center";
        ctx.fillText((-maxVal+(i*gridStep)).toFixed(accurancy), x+i*gridSize-10, y+size/2+15);
        ctx.textAlign = "right";
        if (maxVal-i*gridStep != 0) ctx.fillText((maxVal-i*gridStep).toFixed(accurancy), x+size/2-5, y+i*gridSize+15);
    }
    ctx.strokeRect(x, y, size, size);
    ctx.textAlign = "center";
    ctx.fillText(AXIS[xid], x+size-10, y+size/2+15);
    ctx.textAlign = "right";
    ctx.fillText(AXIS[yid], x+size/2-5, y+15);
}

function drawSide(ctx, x, y, size, n, maxVal, xid=0, yid=1, matrix=frontalMatrix()) {
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

    drawLabels(ctx, x, y, size, maxVal, gridStep, gridSize, n, xid, yid)

    ctx.beginPath();
    let screenCoord1;
    let screenCoord2;
    ctx.strokeStyle = color;
    let newDots = matrixMul(rotatedDots, matrix);

    for (let i = 0; i < lines.length; i++) {
        screenCoord1 = toScreen(newDots[lines[i][0]][xid], newDots[lines[i][0]][yid]);
        screenCoord2 = toScreen(newDots[lines[i][1]][xid], newDots[lines[i][1]][yid]);
        ctx.moveTo(x+screenCoord1[0], y+screenCoord1[1]);
        ctx.lineTo(x+screenCoord2[0], y+screenCoord2[1]);
    }
    ctx.stroke();
    ctx.beginPath();
    ctx.strokeStyle = vectorColor;
    let vec = matrixMul([projectionVector], matrix);
    screenCoord1 = toScreen(0, 0);
    screenCoord2 = toScreen(vec[0][xid], vec[0][yid]);
    ctx.moveTo(x+screenCoord1[0], y+screenCoord1[1]);
    ctx.lineTo(x+screenCoord2[0], y+screenCoord2[1]);
    ctx.stroke();
}

function drawAxis3d(ctx, x, y, size) {
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

    if (xzAngle != 90) {
        lx = Math.cos(xzAngle)*size;
        ly = Math.sin(xzAngle)*size;
        ctx.moveTo(x+size/2-lx, y+size/2-ly);
        ctx.lineTo(x+size/2+lx, y+size/2+ly);
    }
    ctx.stroke();
}
function drawLabels3d(ctx, x, y, size, maxVal, gridStep, gridSize, n, xid, yid, zid) {
    ctx.beginPath();
    for (let i = 1; i < 2*n; i++) {
        ctx.textAlign = "center";
        ctx.fillText((-maxVal+(i*gridStep)).toFixed(accurancy), x+i*gridSize-10, y+size/2+15);
        ctx.textAlign = "right";
        if (maxVal-i*gridStep != 0) ctx.fillText((maxVal-i*gridStep).toFixed(accurancy), x+size/2-5, y+i*gridSize+15);
    }
    ctx.stroke();

    ctx.fillStyle = vectorColor;
    ctx.beginPath();
    for (let i = 0; i < 2*n+1; i++) {
        if (xzAngleDeg != 90 && projectionAngle != 0) {
            let zi = matrixMul([[0, 0, i-maxVal, 1]], transformMatrix);
            if (maxVal-i*gridStep != 0) ctx.fillText(i-maxVal, x+zi[0][0]*gridSize+size/2, y-zi[0][1]*gridSize+size/2);
        }
    }
    ctx.stroke();
    ctx.fillStyle = "black";
    ctx.beginPath();
    ctx.strokeRect(x, y, size, size);
    ctx.textAlign = "center";
    ctx.fillText(AXIS[xid], x+size-10, y+size/2+15);
    ctx.textAlign = "right";
    ctx.fillText(AXIS[yid], x+size/2-5, y+15);
    ctx.stroke();
}

function drawParallel(ctx, x, y, size, n, maxVal) {
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

    drawAxis3d(ctx, x, y, size);
    drawLabels3d(ctx, x, y, size, maxVal, gridStep, gridSize, n, 0, 1, 2);
    ctx.beginPath();
    let screenCoord1;
    let screenCoord2;
    ctx.strokeStyle = color;

    let newDots = matrixMul(rotatedDots, transformMatrix);
    
    for (let i = 0; i < lines.length; i++) {
        screenCoord1 = toScreen(newDots[lines[i][0]][0], newDots[lines[i][0]][1]);
        screenCoord2 = toScreen(newDots[lines[i][1]][0], newDots[lines[i][1]][1]);
        ctx.moveTo(x+screenCoord1[0], y+screenCoord1[1]);
        ctx.lineTo(x+screenCoord2[0], y+screenCoord2[1]);
    }
    ctx.stroke();
}

var canvases = document.getElementsByTagName("canvas");
var contexts = [];
for (let canv of canvases) {
    contexts.push(canv.getContext('2d'));
    contexts[contexts.length-1].translate(0.5, 0.5);
    contexts[contexts.length-1].font = textSize + "px sans-serif";
    contexts[contexts.length-1].strokeStyle = "black";
    contexts[contexts.length-1].lineCap = "square";
    canv.width = offset*2+graphicsSize;
    canv.height = graphicsSize + offset*2;
};

function redraw() {
    for (let i = 0; i < contexts.length; i++) {
        contexts[i].clearRect(0, 0, canvases[i].width, canvases[i].height);
    }

    drawSide(contexts[0], offset, offset, graphicsSize, gridFreq, graphVal, 0, 2, upMatrix());
    drawParallel(contexts[1], offset, offset, graphicsSize, gridFreq, graphVal, 0, 1);
    drawSide(contexts[2], offset, offset, graphicsSize, gridFreq, graphVal, 0, 1, frontalMatrix());
    drawSide(contexts[3], offset, offset, graphicsSize, gridFreq, graphVal, 2, 1, rightMatrix());
    updateParameters();
    updateDotsTable();
    fillTransformTable();
};

function updateParameters() {
    let paramText = document.getElementById("param");

    paramText.innerHTML = "mx = 1, my = 1, mz = " + Math.abs(Math.tan(projectionAngle)).toFixed(3) +
    " Sx = " + Math.cos(xzAngle).toFixed(3) + " Sy = " + Math.sin(xzAngle).toFixed(3) + " Sz = "
    + (1/Math.tan(projectionAngle)).toFixed(3);

    let projectionAngleText = document.getElementById("projectionAngleText");
    projectionAngleText.innerHTML = projectionAngleDeg;
    let rotateAngleText = document.getElementById("rotateAngleText");
    rotateAngleText.innerHTML = rotateAngleDeg;
    let xzAngleText = document.getElementById("XZAngleText");
    xzAngleText.innerHTML = xzAngleDeg;
}

function toGraph(screenX, screenY) {
    let graphX = (screenX - graphicsSize/2) / gridSize;
    let graphY = -(screenY - graphicsSize/2) / gridSize;
    return [graphX, graphY];
}

function toScreen(graphX, graphY) {
    let screenX = graphX * gridSize + graphicsSize/2;
    let screenY = -(graphY * gridSize) + graphicsSize/2;
    return [screenX, screenY, 1, 1];
}

let fileInputButton = document.getElementById("enterFile");
fileInputButton.addEventListener("click", getFile);

function getFile() {
    if (document.getElementById("fileInput").files.length < 1) {
        return;
    }
    let file = document.getElementById("fileInput").files[0];
    let reader = new FileReader();
    reader.readAsText(file);
    reader.onload = function() {
        dots = [];
        lines = [];
        parse(reader.result);
        redraw();
    };
    
    reader.onerror = function() {
        console.log(reader.error);
    };
};

function isLineInLines(lines, line){
    let str = JSON.stringify(line);
    let contains = lines.some(function(el){
        return JSON.stringify(el) === str;
    });
    if (contains) return true

    str = JSON.stringify(line.reverse());
    contains = lines.some(function(el){
        return JSON.stringify(el) === str;
    });
    return contains;
}

function parse(text) {
    let d = text.split(/\r\n| |\n|\r/);
    let l = parseInt(d[0]);
    for (let i = 0; i < l; i++) {
        dots.push([]);
        dots[i][0] = parseInt(d[i*3+1]);
        dots[i][1] = parseInt(d[i*3+2]);
        dots[i][2] = parseInt(d[i*3+3]);
        dots[i][3] = parseInt(1);
    }

    rotatedDots = dots;

    let j = 1;
    for (let i = 0; i < l; i++) {
        while (d[l*3+1+j] != ";") {
            if (isLineInLines(lines, [parseInt(d[l*3+1+j]), i])) {
                j++;
                continue;
            }
            lines.push([i, parseInt(d[l*3+1+j])]);
            j++;
        };
        j += 2;
    }
};

let projectionAngleInput = document.getElementById("projectionAngleInput");
projectionAngleInput.value = 0;
projectionAngleInput.addEventListener("change", getProjectionAngle);

function getProjectionAngle() {
    projectionAngleTransitionTo = projectionAngleInput.value;
}

let rotateAngleInput = document.getElementById("rotateAngleInput");
rotateAngleInput.value = 0;
rotateAngleInput.addEventListener("change", getRotateAngle);

function getRotateAngle() {
    rotateAngleTransitionTo = rotateAngleInput.value;
}

let distanceEnterButton = document.getElementById("enterDistance");
document.getElementById("distanceInput").value = 0;
distanceEnterButton.addEventListener("click", getDistance);

function getDistance() {
    distanceTransitionTo = document.getElementById("distanceInput").value;
}

let timeEnterButton = document.getElementById("enterTime");
document.getElementById("timeInput").value = 5;
timeEnterButton.addEventListener("click", getTime);

function getTime() {
    let timeInput = document.getElementById("timeInput");
    clearInterval(animationTimer);
    console.log(timeInput.value);
    animationTimer = setInterval(updateTransition, timeInput.value);
}

let xzAngleInput = document.getElementById("XZAngleInput");
xzAngleInput.value = 90;
xzAngleInput.addEventListener("change", getXZAngle);

function getXZAngle() {
    xzAngleTransitionTo = xzAngleInput.value;
}

function updateTransition() {
    let changed = false;
    if (rotateAngleDeg != rotateAngleTransitionTo) {
        if (rotateAngleDeg > rotateAngleTransitionTo) rotateAngleDeg -= 1;
        if (rotateAngleDeg < rotateAngleTransitionTo) rotateAngleDeg += 1;
        rotateAngle = degToRad(rotateAngleDeg);
        changed = true;
    }
    if (projectionAngleDeg != projectionAngleTransitionTo) {
        if (projectionAngleDeg > projectionAngleTransitionTo) projectionAngleDeg -= 1;
        if (projectionAngleDeg < projectionAngleTransitionTo) projectionAngleDeg += 1;
        projectionAngle = degToRad(projectionAngleDeg);
        projectionVector = [Math.cos(-xzAngle), Math.sin(-xzAngle), 1/Math.tan(projectionAngle), 1];
        changed = true;
    }
    if (distance != distanceTransitionTo) {
        if (distance > distanceTransitionTo) distance -= 0.1;
        if (distance < distanceTransitionTo) distance += 0.1;
        changed = true;
    }
    if (xzAngleDeg != xzAngleTransitionTo) {
        if (xzAngleDeg > xzAngleTransitionTo) xzAngleDeg -= 1;
        if (xzAngleDeg < xzAngleTransitionTo) xzAngleDeg += 1;
        xzAngle = degToRad(xzAngleDeg);
        projectionVector = [Math.cos(-xzAngle), Math.sin(-xzAngle), 1/Math.tan(projectionAngle), 1];
        changed = true;
    }

    if (changed) {
        transformMatrix = parallelMatrix();
        rotatedDots = matrixMul(dots, rotateYMatrix(rotateAngle));
        redraw();
    }
}

function updateDotsTable() {
    let table = document.querySelector("#dots-table > tbody");
    table.innerHTML = "";
    for (let i = 0; i < dots.length; i++) {
        let row = document.createElement("tr");
        let dot = document.createElement("td");
        dot.textContent = i+1;
        let x1 = document.createElement("td");
        x1.textContent = dots[i][0].toFixed(3);
        let y1 = document.createElement("td");
        y1.textContent = dots[i][1].toFixed(3);
        let z1 = document.createElement("td");
        z1.textContent = dots[i][2].toFixed(3);
        let x2 = document.createElement("td");
        x2.textContent = rotatedDots[i][0].toFixed(3);
        let y2 = document.createElement("td");
        y2.textContent = rotatedDots[i][1].toFixed(3);
        let z2 = document.createElement("td");
        z2.textContent = rotatedDots[i][2].toFixed(3);
        row.appendChild(dot);
        row.appendChild(x1);
        row.appendChild(y1);
        row.appendChild(z1);
        row.appendChild(x2);
        row.appendChild(y2);
        row.appendChild(z2);
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

function frontalMatrix() {
    return [[1, 0, 0, 0],
            [0, 1, 0, 0],
            [0, 0, 0, 0],
            [0, 0, 0, 1]];
}

function upMatrix() {
    return [[1, 0, 0, 0],
            [0, 0, 0, 0],
            [0, 0, 1, 0],
            [0, 0, 0, 1]];
}

function rightMatrix() {
    return [[0, 0, 0, 0],
            [0, 1, 0, 0],
            [0, 0, 1, 0],
            [0, 0, 0, 1]];
}

function rotateYMatrix(angle) {
    return [[Math.cos(angle), 0, Math.sin(angle), 0],
            [0, 1, 0, 0],
            [-Math.sin(angle), 0, Math.cos(angle), 0],
            [0, 0, 0, 1]];
}

function parallelMatrix() {
    return [[1, 0, 0, 0],
            [0, 1, 0, 0],
            [-(projectionVector[0]/projectionVector[2]), -(projectionVector[1]/projectionVector[2]), 0, 0],
            [-distance*projectionVector[0]/projectionVector[2], -distance*projectionVector[1]/projectionVector[2], 0, 1]];
}

function regularMatrix() {
    return [[1, 0, 0, 0],
            [0, 1, 0, 0],
            [0, 0, 1, 0],
            [0, 0, 0, 1]];
}

function fillTransformTable() {
    let transformTable = document.querySelector("#matrix-table > tbody");
    let i = 0;
    
    for (let tr of transformTable.children) {
        let j = 0;
        for (let td of tr.children) {
            td.innerHTML = transformMatrix[i][j].toFixed(3);
            j++;
        }
        i++;
    }
}

getXZAngle();
getTime();
getProjectionAngle();
getRotateAngle();
getDistance();
redraw();
fillTransformTable();
