let fs = require("fs");
const filePath = process.platform === "linux" ? "/dev/stdin" : "js/example.txt";
let input = fs.readFileSync(filePath, "utf8").trim().split("\n");

// O : 빈 공간, X : 벽, I : 도연, P : 사람

let [N, M] = input[0].split(" ").map((v) => Number(v));

let map = [];
let visited = [];
let q = [];
let num = 0;
for (let n = 1; n <= N; n++) {
  const line = input[n].split("");

  for (let m = 0; m < M; m++) {
    if (line[m] === "I") {
      q.push([m, n - 1]);
    }
  }
  map.push(line);
  visited.push([...line]);
}

// BFS : 너비 우선 탐색

let direction = [
  [1, 0],
  [0, 1],
  [-1, 0],
  [0, -1],
];

while (q.length != 0) {
  let [x, y] = q.shift();

  switch (map[y][x]) {
    case "O":
      break;
    case "I":
      break;
    case "P":
      num++;
      break;
  }

  map[y][x] = "X";

  for (dir of direction) {
    let dx = x + dir[0];
    let dy = y + dir[1];

    if (dx >= 0 && dx < M && dy >= 0 && dy < N) {
      if (visited[dy][dx] !== "X") {
        q.push([dx, dy]);
        visited[dy][dx] = "X";
      }
    }
  }
}

console.log(num > 0 ? num : "TT");
