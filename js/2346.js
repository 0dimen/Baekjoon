let fs = require("fs");
let input = fs.readFileSync("example.txt").toString().split("\n");
// let input = fs.readFileSync("/dev/stdin").toString().split("\n");

let N = input[0];
let balloons = input[1].split(" ").map((v, idx) => {
  return [idx, parseInt(v)];
});
let idx = 0;
let answer = [];

while (balloons.length > 0) {
  let [bIndex, nextMove] = balloons[idx];
  balloons.splice(idx, 1);
  answer.push(bIndex + 1);

  // index 정정
  if (nextMove > 0) idx--;

  idx = (idx + nextMove) % balloons.length;

  if (idx < 0) {
    idx = balloons.length + idx;
  }
}

console.log(answer.join(" "));
