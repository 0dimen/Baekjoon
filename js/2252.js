let fs = require("fs");
const filePath = process.platform === "linux" ? "/dev/stdin" : "js/example.txt";
let input = fs.readFileSync(filePath, "utf8").trim().split("\n");

let [N, M] = input[0].split(" ").map((v) => Number(v));
// tree 연결 방식

class Node {
  constructor(n) {
    this.next = [];
    this.minNode = n;
  }

  pushNext(num) {
    // 차집합
    this.next = this.next.filter((x) => {
      if (tree[num].next.includes(x) != undefined) {
        tree[x].minNode = this.maxNode;
        return false;
      } else {
        this.minNode = num;
        return true;
      }
    });
    this.next.push(num);
  }

  findMaxNode() {}
}

let tree = Array.from({ length: N + 1 }, (_, i) => new Node(i));

for (let i = 1; i <= M; i++) {
  let [a, b] = input[i].split(" ").map((v) => Number(v));

  tree[a].pushNext(b);
}
console.log(tree);

let visited = new Array({ length: N + 1 }).fill(false);

function bfs(firstNum) {
  let str = [];
  let q = [firstNum.minNode];

  // next
  while (q.length != 0) {
    num = q.shift();

    if (visited[num]) {
      continue;
    }

    str.push(num);
    visited[num] = true;
    for (nextNum of tree[num].next) {
      if (!visited[nextNum]) {
        q.push(nextNum);
      }
    }
  }

  return str.join(" ");
}

let answer = [];

for (let i = 1; i <= N; i++) {
  if (!visited[i]) {
    answer.push(bfs(i));
  }
}

console.log(answer.join(" "));
