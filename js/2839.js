let fs = require("fs");
const filePath = process.platform === "linux" ? "/dev/stdin" : "js/example.txt";
let input = fs.readFileSync(filePath, "utf8").trim().split("\n");

let N = Number(input[0]);

let [five, three] = [0, 0];

five = Math.floor(N / 5);

for (; five >= 0; five--) {
  if ((N - five * 5) % 3 === 0) {
    console.log(five + (N - five * 5) / 3);
    return;
  }
}
console.log(-1);
