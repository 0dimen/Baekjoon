let fs = require("fs");
const filePath = process.platform === "linux" ? "/dev/stdin" : "js/example.txt";
let input = fs.readFileSync(filePath, "utf8").trim().split("\n");

let N = Number(input[0]);
let arr = [];

for (let n = 1; n <= N; n++) {
  arr.push(Number(input[n]));
}

let seeCow = [];
let answer = 0;

for (cow of arr) {
  if (cow < seeCow[seeCow.length - 1]) {
    // 날 볼수 있는 경우
    seeCow.push(cow);
    console.log(seeCow);
    answer += seeCow.length;
  } else {
    // 날 볼수 없는 경우
    while (seeCow.length != 0 && seeCow[seeCow.length - 1] >= cow) {
      seeCow.pop();
    }
    seeCow.push(cow);
  }
}

console.log(answer);
