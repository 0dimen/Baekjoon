let fs = require("fs");
const filePath = process.platform === "linux" ? "/dev/stdin" : "js/example.txt";
let input = fs.readFileSync(filePath, "utf8").trim().split("\n");

let cNum = Number(input[0]);
let vNum = Number(input[1]);
let v = Array.from({ length: cNum + 1 }, () => []);

for (let i = 2; i < 2 + vNum; i++) {
  let [a, b] = input[i].split(" ").map((v) => Number(v));

  v[a].push(b);
  v[b].push(a);
}

let visited = new Array({ length: cNum + 1 }).fill(false);
let n = 0;
function dfs(num) {
  visited[num] = true;
  n++;
  for (idx of v[num]) {
    if (!visited[idx]) dfs(idx);
  }
}

dfs(1);
console.log(n - 1);
