let fs = require("fs");
const filePath = process.platform === "linux" ? "/dev/stdin" : "js/example.txt";
let input = fs.readFileSync(filePath, "utf8").trim().split("\n");

let [N, M] = input[0].split(" ").map((v) => Number(v));
let v = Array.from({ length: N }, () => []);

for (let m = 1; m <= M; m++) {
  let [a, b] = input[m].split(" ").map((v) => Number(v));
  v[a].push(b);
  v[b].push(a);
}

let visited = new Array(N).fill(false);
let flag = 0;
function dfs(n, num, root) {
  visited[n] = true;

  if (num === 5) {
    if (v[n].includes(root) != -1) {
      flag = 1;
      visited[n] = false;
      return;
    }
  }

  for (x of v[n]) {
    if (!visited[x]) dfs(x, num + 1, root);
  }
  visited[n] = false;
}

for (let n = 0; n < N; n++) {
  if (!visited[n]) {
    dfs(n, 1, n);
  }
  if (flag === 1) {
    break;
  }
  visited[n] = false;
}

console.log(flag);
