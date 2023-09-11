var step = 0.001;
var graphicsSize = 600;
var gridFreq = 6;
var graphVal = 6;
var graphicThickness = 2;
var accurancy = 0;
var textSize = 16;
var color = "red";

function f(x) {
    return Math.sin(x)*3+2;
}

// function f(x) {
//     return (x+2)**2;
// }

// function f(fi) {
//     let a = 2;
//     let m = -2.5; //2.5, -2.5
//     return Math.pow(Math.pow(a, m)*Math.cos(m*fi), 1/m);
// }

function decToPol(x, y) {
    let fi = Math.atan2(y, x);
    let r = Math.sqrt(x*x+y*y);
    return [fi, r];
}

function polToDec(fi, r) {
    let x = r*Math.cos(fi);
    let y = r*Math.sin(fi);
    return [x, y];
}

function drawDec(f, x, y, size, n, maxVal) {
    let gridSize = size/(n*2);
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
    ctx.lineWidth = 3;
    ctx.beginPath();
    ctx.moveTo(x, y + size/2);
    ctx.lineTo(x + size, y + size/2);
    ctx.moveTo(x+size/2, y);
    ctx.lineTo(x+size/2, y+size);
    ctx.stroke();

    ctx.fillStyle = color;
    for (let i = -maxVal; i <= maxVal; i += step) {
        let val = f(i);
        if (Math.abs(val) >= maxVal) continue;
        ctx.fillRect(x+size/2+i*gridSize/gridStep, y+size/2-val*gridSize/gridStep, graphicThickness, graphicThickness);
    }
    ctx.fillStyle = "black";

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

function drawPol(f, x, y, size, n, maxVal) {
    let gridSize = size/(n*2);
    ctx.beginPath();
    ctx.lineWidth = 1;
    let gridStep = maxVal/n;
    for (let i = 1; i <= n; i++) {
        ctx.arc(x+size/2, y+size/2, gridSize*i, 0, 2*Math.PI);
    }
    
    ctx.stroke();
    ctx.lineWidth = 3;
    ctx.beginPath();
    ctx.moveTo(x, y + size/2);
    ctx.lineTo(x + size, y + size/2);
    ctx.moveTo(x+size/2, y);
    ctx.lineTo(x+size/2, y+size);
    ctx.stroke();

    ctx.fillStyle = color;
    for (let i = -Math.PI*2; i <= Math.PI*2; i += step) {
        let val = f(i);
        let screenX = val*Math.cos(i);
        let screenY = val*Math.sin(i);
        if (Math.abs(screenY) >= maxVal || Math.abs(screenX) >= maxVal) continue;
        ctx.fillRect(x+size/2+screenX*gridSize/gridStep, y+size/2-screenY*gridSize/gridStep, graphicThickness, graphicThickness);
    }
    ctx.fillStyle = "black";
    
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

var canvas = document.getElementById("graphics");
ctx = canvas.getContext('2d');
ctx.translate(0.5, 0.5);
ctx.font = textSize + "px sans-serif";
ctx.strokeStyle = "black";
ctx.lineCap = "square";

drawDec(f, 25, 25, graphicsSize, gridFreq, graphVal)
drawPol(f, graphicsSize+50, 25, graphicsSize, gridFreq, graphVal);
