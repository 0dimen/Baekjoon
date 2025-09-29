let fs = require("fs");
const filePath = process.platform === "linux" ? "/dev/stdin" : "js/example.txt";
let input = fs.readFileSync(filePath, "utf8").trim().split("\n");

let [N, M, R] = input[0].split(" ").map((v) => Number(v));
let v = Array.from({ length: N + 1 }, () => []);
for (let m = 1; m <= M; m++) {
  let [a, b] = input[m].split(" ").map((v) => Number(v));
  v[a].push(b);
  v[b].push(a);
}
let visited = new Array(N + 1).fill(0);

let n = 1;
function dfs(R) {
  visited[R] = n;
  n++;
  v[R].sort((a, b) => a - b).forEach((x) => {
    if (visited[x] === 0) dfs(x);
  });
}

dfs(R);

console.log(visited.slice(1).join("\n"));
