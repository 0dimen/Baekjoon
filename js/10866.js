let fs = require("fs");
let input = fs.readFileSync("example.txt").toString().split("\n");
// let input = fs.readFileSync("/dev/stdin").toString().split("\n");

let N = Number(input[0]);
let dq = [];
let str = [];
for (let i = 1; i <= N; i++) {
  let [prompt, n] = input[i].split(" ");

  switch (prompt) {
    case "push_back":
      dq.push(n);
      break;
    case "push_front":
      dq.unshift(n);
      break;
    case "pop_front":
      str.push(dq.shift() || -1);
      break;
    case "pop_back":
      str.push(dq.pop() || -1);
      break;
    case "size":
      str.push(dq.length);
      break;
    case "empty":
      str.push(dq.length === 0 ? 1 : 0);
      break;
    case "front":
      str.push(dq[0] || -1);
      break;
    case "back":
      str.push(dq[dq.length - 1] || -1);
      break;
  }
}
console.log(str.join("\n"));
