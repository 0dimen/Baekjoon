let fs = require("fs");
const filePath = process.platform === "linux" ? "/dev/stdin" : "js/example.txt";
let input = fs.readFileSync(filePath, "utf8").trim().split("\n");

const v = Number(input[0]);
const connect = Array.from({ length: v }, () => []);

for (let i = 1; i <= v; i++) {
  const line = input[i].split(" ").map((v) => Number(v));
  const index = line[0] - 1;
  for (let j = 1; j < line.length - 1; j += 2) {
    connect[index].push([line[j] - 1, line[j + 1]]);
  }
}

var max = 0;
var maxNode = 0;
// 자식 노드를 탐색 (말단 노드)
var visit = Array.from({ length: v }, () => false);
dfs(0, 0);

function dfs(node, d) {
  for ([nextNode, distance] of connect[node]) {
    if (!visit[nextNode]) {
      visit[node] = true;
      const sum = d + distance;
      if (sum > max) {
        max = sum;
        maxNode = nextNode;
      }

      dfs(nextNode, sum);
    }
  }
}

visit = Array.from({ length: v }, () => false);
dfs(maxNode, 0);

console.log(max);
