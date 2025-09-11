let fs = require("fs");
const filePath = process.platform === "linux" ? "/dev/stdin" : "js/example.txt";
let input = fs.readFileSync(filePath, "utf8").trim().split("\n");
let sum = 0;
let heights = [];
for (let i = 0; i < input.length; i++) {
  heights.push(Number(input[i]));
  sum += Number(input[i]);
}
heights.sort((a, b) => a - b);

sum -= 100;

outer: for (let i = 0; i < 9; i++) {
  for (let j = i + 1; j < 9; j++) {
    if (sum === heights[i] + heights[j]) {
      for (let idx = 0; idx < 9; idx++) {
        if (idx !== i && idx !== j) console.log(heights[idx]);
      }
      break outer;
    }
  }
}
