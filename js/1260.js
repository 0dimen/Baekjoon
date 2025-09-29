let fs = require("fs");
const filePath = process.platform === "linux" ? "/dev/stdin" : "js/example.txt";
let input = fs.readFileSync(filePath, "utf8").trim().split("\n");

let [N, M, V] = input[0].split(" ").map((v) => Number(v));

let nodes = Array.from({ length: N + 1 }, () => []);

for (let i = 1; i <= M; i++) {
  let [a, b] = input[i].split(" ").map((v) => Number(v));
  nodes[a].push(b);
  nodes[b].push(a);
}

for (let i = 0; i < nodes.length; i++) {
  nodes[i] = nodes[i].sort((a, b) => a - b);
}

let answer1 = [];
let visited1 = new Array(N + 1).fill(false);
function dfs(n) {
  if (visited1[n]) {
    return;
  } else {
    visited1[n] = true;
    answer1.push(n);
    for (i of nodes[n]) {
      dfs(i);
    }
  }
}

let answer2 = [];
let visited2 = new Array(N + 1).fill(false);

function bfs(n) {
  let queue = [n];
  while (queue.length != 0) {
    let i = queue.shift();
    if (!visited2[i]) {
      visited2[i] = true;
      answer2.push(i);

      for (j of nodes[i]) {
        if (!visited2[j]) {
          queue.push(j);
        }
      }
    }
  }
}
dfs(V);
bfs(V);
console.log(answer1.join(" "));
console.log(answer2.join(" "));
