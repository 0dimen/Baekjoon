let fs = require("fs");
let input = fs.readFileSync("example.txt").toString().split("\n");
// let input = fs.readFileSync("/dev/stdin").toString().split("\n");

let T = Number(input[0]);
for (let t = 0; t < T; t++) {
  let N = Number(input[1 + t * 2]);
  let cards = input[2 + t * 2].split(" ");

  let str = cards[0];
  for (let i = 1; i < N; i++) {
    let c = cards[i];
    if (c > str[0]) {
      str += c;
    } else {
      str = c + str;
    }
  }

  console.log(str);
}
