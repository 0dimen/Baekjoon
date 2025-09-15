let fs = require("fs");
const filePath = process.platform === "linux" ? "/dev/stdin" : "js/example.txt";
let input = fs.readFileSync(filePath, "utf8").trim().split("\n");
// let input = fs.readFileSync("/dev/stdin").toString().split("\n");

let [N, K] = input[0].split(" ").map((v) => Number(v));
let words = [];
let selectedChars = ["a", "n", "t", "i", "c"];
let max = 0;

if (K < 5) {
  console.log(0);
  return;
}

for (let n = 1; n <= N; n++) {
  let newWord = input[n];
  let newChars = new Set();
  // 중복되지 않도록 값 넣기.
  for (c of newWord) {
    newChars.add(c);
  }
  words.push(newChars);
}

let canSelectChars = [
  "b",
  "d",
  "e",
  "f",
  "g",
  "h",
  "j",
  "k",
  "l",
  "m",
  "o",
  "p",
  "q",
  "r",
  "s",
  "u",
  "v",
  "w",
  "x",
  "z",
  "y",
];
combi(0, selectedChars);
// 남은 글자 조합
function combi(idx, selectedArr) {
  if (selectedArr.length >= K) {
    diff(selectedArr);
    return;
  }
  for (let i = idx; i < canSelectChars.length; i++) {
    selectedArr.push(canSelectChars[i]);

    combi(i + 1, selectedArr);
    selectedArr.pop();
  }
}

function diff(selectedArr) {
  let n = 0;
  for (word of words) {
    let flag = 1;
    for (c of word) {
      if (selectedArr.indexOf(c) < 0) {
        flag = 0;
        break;
      }
    }
    n += flag;
  }
  if (max < n) max = n;
}
console.log(max);
