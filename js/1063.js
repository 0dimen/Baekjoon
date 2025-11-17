let fs = require("fs");
const filePath = process.platform === "linux" ? "/dev/stdin" : "js/example.txt";
let input = fs.readFileSync(filePath, "utf8").trim().split("\n");

let [startK, startR, N] = input[0].split(" ");
N = Number(N);
let ky = Number(startK[1]);
let kx = startK.charCodeAt(0) - "A".charCodeAt(0);
let ry = Number(startR[1]);
let rx = startR.charCodeAt(0) - "A".charCodeAt(0);

for (let i = 1; i <= N; i++) {
  let move = input[i];
  let [dx, dy] = [0, 0];
  switch (move[0]) {
    case "R":
      dx++;
      break;
    case "L":
      dx--;
      break;
    case "T":
      dy++;
      break;
    case "B":
      dy--;
      break;
  }

  if (move.length > 1) {
    switch (move[1]) {
      case "T":
        dy++;
        break;
      case "B":
        dy--;
        break;
    }
  }
  if (kx + dx >= 0 && kx + dx <= 7 && ky + dy >= 1 && ky + dy <= 8) {
    if (kx + dx === rx && ky + dy === ry) {
      if (rx + dx >= 0 && rx + dx <= 7 && ry + dy >= 1 && ry + dy <= 8) {
        rx += dx;
        ry += dy;
      } else {
        continue;
      }
    }
    kx += dx;
    ky += dy;
  }
}

console.log(String.fromCharCode(kx + "A".charCodeAt(0)) + ky);
console.log(String.fromCharCode(rx + "A".charCodeAt(0)) + ry);
