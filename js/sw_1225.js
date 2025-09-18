let fs = require("fs");
const filePath = process.platform === "linux" ? "/dev/stdin" : "js/example.txt";
let input = fs.readFileSync(filePath, "utf8").trim().split("\n");

for (let t = 0; t < 10; t++) {
  let numbers = input[2 * t + 1].split(" ").map((v) => Number(v));

  let i = 1;
  while (numbers[numbers.length - 1] != 0) {
    if (i === 6) i = 1;
    let sliced = numbers.slice(1);
    let newNum = numbers[0] - i;
    if (newNum <= 0) {
      numbers = [...sliced, 0];
    } else {
      numbers = [...sliced, newNum];
    }

    i++;
  }

  console.log(numbers);
}
