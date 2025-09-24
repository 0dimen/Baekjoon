let fs = require("fs");
const filePath = process.platform === "linux" ? "/dev/stdin" : "js/example.txt";
let input = fs.readFileSync(filePath, "utf8").trim().split("\n");

let [N, M] = input[0].split(" ").map((v) => Number(v));

let map = [];
for (let i = 1; i <= N; i++) {
  map.push(input[i].split("").map((v) => Number(v)));
}

let n = 0;
let queue = [[0, 0]];
let directions = [
  [0, 1],
  [0, -1],
  [1, 0],
  [-1, 0],
];

while (queue.length != 0) {
  let newQ = [];
  n++;
  for (q of queue) {
    let [x, y] = q;

    if (map[y][x] === 0) {
      continue;
    }
    map[y][x] = 0;

    if (x === M - 1 && y === N - 1) {
      console.log(n);
      return;
    }

    for (dir of directions) {
      let dx = dir[0] + x;
      let dy = dir[1] + y;

      if (dx >= 0 && dx < M && dy >= 0 && dy < N) {
        if (map[dy][dx] !== 0) {
          newQ.push([dx, dy]);
        }
      }
    }
  }
  queue = newQ;
}
