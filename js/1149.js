let fs = require("fs");
const filePath = process.platform === "linux" ? "/dev/stdin" : "js/example.txt";
let input = fs.readFileSync(filePath, "utf8").trim().split("\n");

const n = Number(input[0]);
const houses = [];
for (let i = 1; i <= n; i++) {
  let [r, g, b] = input[i].split(" ").map((v) => Number(v));
  houses.push([r, g, b]);
}

const costs = Array.from({ length: n }, (_) => new Array(-1, -1, -1));

//bfs, dp
// [houseIdx, current]
var queue = [
  [0, 0],
  [0, 1],
  [0, 2],
];

costs[0] = houses[0];

while (queue.length > 0) {
  const newQ = [];
  for ([houseIdx, current] of queue) {
    if (houseIdx + 1 >= n) {
      break;
    }
    const nextNums = [0, 1, 2].filter((v) => v != current);

    for (next of nextNums) {
      const newValue = costs[houseIdx][current] + houses[houseIdx + 1][next];

      if (
        costs[houseIdx + 1][next] > newValue ||
        costs[houseIdx + 1][next] === -1
      ) {
        costs[houseIdx + 1][next] = newValue;
        newQ.push([houseIdx + 1, next]);
      }
    }
  }
  queue = newQ;
}

var min = costs[costs.length - 1][0];

for (cost of costs[costs.length - 1]) {
  if (min > cost) min = cost;
}
console.log(min);
