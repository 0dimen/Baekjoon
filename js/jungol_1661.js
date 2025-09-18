let fs = require("fs");
const filePath = process.platform === "linux" ? "/dev/stdin" : "js/example.txt";
let input = fs.readFileSync(filePath, "utf8").trim().split("\n");

let [X, Y] = input[0].split(" ").map((v) => Number(v));
let [startX, startY, endX, endY] = input[1]
  .split(" ")
  .map((v) => Number(v - 1));

let map = [];
for (let i = 2; i <= Y + 1; i++) {
  map.push(input[i].split("").map((v) => (v == "0" ? 0 : -1)));
}

let q = [[startX, startY, 1]];
let min = 10000;
const directions = [
  [0, 1],
  [0, -1],
  [1, 0],
  [-1, 0],
];

while (q.length != 0) {
  // console.log(q);
  let [x, y, depth] = q[0];
  q.shift();
  if (map[y][x] !== 0) {
    // already visited
    continue;
  }
  map[y][x] = depth;
  for (dir of directions) {
    let dx = x + dir[0];
    let dy = y + dir[1];

    if (dx < X && dx >= 0 && dy < Y && dy >= 0) {
      // case of in map
      q.push([dx, dy, depth + 1]);
    }
  }
}

let answer = map[endY][endX];
console.log(answer === 0 ? -1 : answer - 1);
