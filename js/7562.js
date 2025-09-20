let fs = require("fs");
const filePath = process.platform === "linux" ? "/dev/stdin" : "js/example.txt";
let input = fs.readFileSync(filePath, "utf8").trim().split("\n");

let T = Number(input[0]);
let directions = [
  [2, -1],
  [-2, -1],
  [2, 1],
  [-2, 1],
  [1, -2],
  [1, 2],
  [-1, 2],
  [-1, -2],
];

for (let t = 0; t < T; t++) {
  let N = Number(input[t * 3 + 1]);
  let [nowX, nowY] = input[t * 3 + 2].split(" ").map((v) => Number(v));
  let [targetX, targetY] = input[t * 3 + 3].split(" ").map((v) => Number(v));

  let queue = [[nowX, nowY]];
  let memo = Array.from({ length: N }, () => Array(N).fill(false));

  let n = 0;

  label: while (queue.length != 0) {
    let newQ = [];

    for (q of queue) {
      let [x, y] = q;
      if (x === targetX && y === targetY) {
        console.log(n);
        break label;
      }

      if (memo[y][x]) {
        continue;
      }

      memo[y][x] = true;
      for (dir of directions) {
        let dx = dir[0] + x;
        let dy = dir[1] + y;
        if (dx >= 0 && dx < N && dy >= 0 && dy < N) {
          if (!memo[dy][dx]) {
            newQ.push([dx, dy]);
          }
        }
      }
    }

    queue = newQ;
    n++;
  }
}
