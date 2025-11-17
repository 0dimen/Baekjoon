let fs = require("fs");
const filePath = process.platform === "linux" ? "/dev/stdin" : "js/example.txt";
let input = fs.readFileSync(filePath, "utf8").trim().split("\n");

let [n, w, L] = input[0].split(" ").map((v) => Number(v));
let truck = input[1].split(" ").map((v) => Number(v));

let bridge = [];

let t = 0;
let sum = 0;
while (bridge.length != 0 || truck.length != 0) {
  t++;
  // 트럭 이동
  for (let i = 0; i < bridge.length; i++) {
    bridge[i][1]++;
  }
  if (bridge.length != 0) {
    if (bridge[0][1] >= w) sum -= bridge.shift()[0];
  }

  // 새로운 트럭 추가
  if (sum + truck[0] <= L) {
    sum += truck[0];
    bridge.push([truck.shift(), 0]);
  }
}

console.log(t);
