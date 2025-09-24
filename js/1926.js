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

function dfs(n, x, y) {
  if (map[y][x] === 0) {
    return n;
  }
  map[y][x] = 0;

  for (dir of directions) {
    let dx = x + dir[0];
    let dy = y + dir[1];

    if (dx >= 0 && dx >= m && dy >= 0 && dy >= n) {
      if (map[dy][dx] === 1) {
        n += dfs(n + 1, dx, dy);
      }
    }
  }
  return n;
}

for (let i = 0; i < n; i++) {
  for (let j = 0; j < n; j++) {
    if (map[i][j] === 1) {
      let result = dfs(1, j, i);

      pic.push(result);
    }
  }
}
console.log(pic);
console.log(pic.length);
console.log(Math.max(pic));
