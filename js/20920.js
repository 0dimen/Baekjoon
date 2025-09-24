let fs = require("fs");
const filePath = process.platform === "linux" ? "/dev/stdin" : "js/example.txt";
let input = fs.readFileSync(filePath, "utf8").trim().split("\n");

let [N, M] = input[0].split(" ").map((v) => Number(v));

let words = new Map();

// 단어 받아오기.
for (let i = 1; i <= N; i++) {
  let word = input[i];
  if (word.length < M) {
    continue;
  }
  let n = words.get(word);

  if (n !== undefined) {
    words.set(word, n + 1);
  } else {
    words.set(word, 1);
  }
}

let wordList = [...words];

wordList.sort((a, b) => (a[0] > b[0] ? 1 : -1));
wordList.sort((a, b) => b[0].length - a[0].length);
wordList.sort((a, b) => b[1] - a[1]);

let answer = [];
for (w of wordList) {
  answer.push(w[0]);
}
console.log(answer.join("\n"));
