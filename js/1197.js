let fs = require("fs");
const filePath = process.platform === "linux" ? "/dev/stdin" : "js/example.txt";
let input = fs.readFileSync(filePath, "utf8").trim().split("\n");

let [V, E] = input[0].split(" ").map((v) => Number(v));

let Vs = [];

for (let i = 0; i <= V; i++) {
  Vs.push(i);
}

let vertex = [];
for (let i = 1; i <= E; i++) {
  let [A, B, C] = input[i].split(" ").map((v) => Number(v));

  if (A < B) {
    vertex.push([A, B, C]);
  } else {
    vertex.push([B, A, C]);
  }
}

// vertex  오름차순 소팅
vertex.sort((a, b) => a[2] - b[2]);

function findRoot(n) {
  if (Vs[n] === n) {
    return n;
  }
  return (Vs[n] = findRoot(Vs[n])); // 경로 압축
}

let vNum = 1;
let total = 0;
vertex.forEach((v) => {
  let rootA = findRoot(v[0]);
  let rootB = findRoot(v[1]);

  if (rootA !== rootB) {
    if (v[0] > v[1]) {
      Vs[rootB] = rootA;
    } else Vs[rootA] = rootB;

    total += v[2];
    vNum++;
  }
});

console.log(total);
