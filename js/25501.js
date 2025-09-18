let fs = require("fs");
const filePath = process.platform === "linux" ? "/dev/stdin" : "js/example.txt";
let input = fs.readFileSync(filePath, "utf8").trim().split("\n");

let T = Number(input[0]);
let n;
function recursion(s, l, r) {
  n++;
  if (l >= r) return 1;
  else if (s[l] != s[r]) return 0;
  else return recursion(s, l + 1, r - 1);
}

function isPalindrom(s) {
  return recursion(s, 0, s.length - 1);
}

for (let t = 1; t <= T; t++) {
  n = 0;
  let result = isPalindrom(input[t]);
  console.log(result + " " + n);
}
