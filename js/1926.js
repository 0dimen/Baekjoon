let fs = require("fs");
const filePath = process.platform === "linux" ? "/dev/stdin" : "js/example.txt";
let input = fs.readFileSync(filePath, "utf8").trim().split("\n");

let [n, m] = input[0].split(" ").map((v) => Number(v));

let map = [];
for (let i = 1; i <= n; i++) {
  map.push(input[i].split(" ").map((v) => Number(v)));
}

let pic = [];
let directions = [
  [0, 1],
  [0, -1],
  [1, 0],
  [-1, 0],
];

function bfs(firstX, firstY) {
  let queue = [[firstX, firstY]];
  let num = 0;
  while (queue.length !== 0) {
    let newQ = [];
    for (q of queue) {
      let [x, y] = q;
      if (map[y][x] === 0) {
        continue;
      }
      map[y][x] = 0;
      num++;
      for (dir of directions) {
        let dx = dir[0] + x;
        let dy = dir[1] + y;
        if (dx >= 0 && dx < m && dy >= 0 && dy < n) {
          if (map[dy][dx] === 1) {
            newQ.push([dx, dy]);
          }
        }
      }
    }
    queue = newQ;
  }

  pic.push(num);
}

for (let i = 0; i < n; i++) {
  for (let j = 0; j < m; j++) {
    if (map[i][j] === 1) {
      bfs(j, i);
    }
  }
}
console.log(pic.length);
if (pic.length > 0) {
  console.log(Math.max(...pic));
} else {
  console.log(0);
}
