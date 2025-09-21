let fs = require("fs");
const filePath = process.platform === "linux" ? "/dev/stdin" : "js/example.txt";
let input = fs.readFileSync(filePath, "utf8").trim().split("\n");

let [M, N, K] = input[0].split(" ").map((v) => Number(v));
// 영역 초기화
let map = Array.from({ length: M }, () => Array(N).fill(true));

// 영역 채우기
for (let k = 1; k <= K; k++) {
  let [x1, y1, x2, y2] = input[k].split(" ").map((v) => Number(v));
  for (let y = y1; y < y2; y++) {
    for (let x = x1; x < x2; x++) {
      map[y][x] = false;
    }
  }
}

let answer = [];
let directions = [
  [0, 1],
  [0, -1],
  [1, 0],
  [-1, 0],
];
for (let m = 0; m < M; m++) {
  for (let n = 0; n < N; n++) {
    if (map[m][n]) {
      BFS(n, m);
    }
  }
}

function BFS(X, Y) {
  let queue = [[X, Y]];
  let n = 0;
  while (queue.length != 0) {
    let newQ = [];

    for (q of queue) {
      let [x, y] = q;
      if (!map[y][x]) {
        continue;
      }
      map[y][x] = false;
      n++;

      for (dir of directions) {
        let dx = dir[0] + x;
        let dy = dir[1] + y;

        if (dx >= 0 && dx < N && dy >= 0 && dy < M) {
          newQ.push([dx, dy]);
        }
      }
    }
    queue = newQ;
  }
  answer.push(n);
}

console.log(answer.length);
console.log(answer.sort((a, b) => a - b).join("\n"));
