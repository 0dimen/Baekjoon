let fs = require("fs");
const filePath = process.platform === "linux" ? "/dev/stdin" : "js/example.txt";
let input = fs.readFileSync(filePath, "utf8").trim().split("\n");

let [A, K] = input[0].split(" ").map((v) => Number(v));
let n = 0;
let m = new Set();

function bfs(queue) {
  while (queue.length != 0) {
    let newQ = [];

    for (a of queue) {
      if (a === K) {
        console.log(n);
        return;
      } else if (a < K) {
        if (!m.has(a + 1)) {
          // m[a+1]이 없는 경우
          newQ.push(a + 1);
          m.add(a + 1);
        }
        if (!m.has(a * 2)) {
          newQ.push(a * 2);
          m.add(a * 2);
        }
      }
    }
    if (newQ.length != 0) {
      n++;
      queue = newQ;
    }
  }
}

bfs([A]);
