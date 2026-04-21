let fs = require("fs");
const filePath = process.platform === "linux" ? "/dev/stdin" : "js/example.txt";
let input = fs.readFileSync(filePath, "utf8").trim().split("\n");

let [N, M] = input[0].split(" ").map((v) => Number(v));

// sort
const set = new Set();
let map = [];
input[1].split(" ").map((v) => set.add(Number(v)));
map = [...set];
map.sort((a, b) => a - b);
map.map((v) => set.add(v));

// 조합
const result = [];
const temp = [];
comb(0);

function comb(mIndex) {
  // 초기 조건
  if (temp.length === M) {
    result.push(temp.join(" "));
    return;
  }

  for (let i = mIndex; i < map.length; i++) {
    temp.push(map[i]);
    comb(i); // 다음 조합들을 사용.
    temp.pop();
  }
}

console.log(result.join("\n"));
