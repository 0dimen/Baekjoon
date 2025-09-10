let fs = require("fs");
let input = fs.readFileSync("example.txt").toString().split("\n");
// let input = fs.readFileSync("/dev/stdin").toString().split("\n");

let N = Number(input[0]);
let q = [];
let str = [];

for (let i = 1; i <= N; i++) {
  let [cmd, n] = input[i].split(" ");
  switch (cmd) {
    case "push":
      q.push(n);
      break;
    case "pop":
      str.push(q.shift() || -1);
      break;
    case "size":
      str.push(q.length);
      break;
    case "empty":
      str.push(q.length > 0 ? 0 : 1);
      break;
    case "front":
      str.push(q[0] || -1);
      break;
    case "back":
      str.push(q[q.length - 1] || -1);
      break;
  }
}

console.log(str.join("\n"));
