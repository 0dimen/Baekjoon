let fs = require("fs");
const filePath = process.platform === "linux" ? "/dev/stdin" : "js/example.txt";
let input = fs.readFileSync(filePath, "utf8").trim().split("\n");

let N = Number(input[0]);
let papers = [];
for (let i = 1; i <= N; i++) {
  let line = input[i].split(" ");
  papers.push(line);
}

let blue = 0;
let white = 0;
function conquere(n, x, y) {
  let first = papers[y][x];
  let flag = true;
  let max = n;
  find: for (let i = y; i < max + y; i++) {
    for (let j = x; j < max + x; j++) {
      if (papers[i][j] !== first) {
        flag = false;
        break find;
      }
    }
  }

  if (flag) {
    if (first === "0") {
      white++;
    } else {
      blue++;
    }
    return;
  } else {
    n /= 2;
    conquere(n, x, y);
    conquere(n, x + n, y);
    conquere(n, x, y + n);
    conquere(n, x + n, y + n);
  }
}

conquere(N, 0, 0);

console.log(white);
console.log(blue);
