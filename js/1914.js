let fs = require("fs");
// let input = fs.readFileSync("example.txt").toString().split("\n");
// let input = fs.readFileSync("/dev/stdin").toString().split("\n");

// let N = input[0];
let K = 0;

hanoi(4, 1, 3);

function hanoi(num, start, destination) {
  if (num == 0) {
    return;
  }
  let temp = 6 - start - destination;
  hanoi(num - 1, destination, temp);

  console.log(`${start} ${destination}`);
}
