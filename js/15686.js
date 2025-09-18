let fs = require("fs");
const filePath = process.platform === "linux" ? "/dev/stdin" : "js/example.txt";
let input = fs.readFileSync(filePath, "utf8").trim().split("\n");
// let input = fs.readFileSync("/dev/stdin").toString().split("\n");

let house = [];
let chicken = [];
let chickenLength = [];

let [N, M] = input[0].split(" ").map((v) => Number(v));

for (let i = 1; i <= N; i++) {
  for (let j = 0; j < N; j++) {
    switch (input[i][j * 2]) {
      case "1":
        house.push([i - 1, j]);
        break;
      case "2":
        chicken.push([i - 1, j]);
        break;
    }
  }
}

// 집마다 치킨 거리 구하기
for (let i = 0; i < chicken.length; i++) {
  calcLength(i);
}

function calcLength(idx) {
  let c = chicken[idx];
  chickenLength[idx] = [];
  for (h of house) {
    chickenLength[idx].push(Math.abs(c[0] - h[0]) + Math.abs(c[1] - h[1]));
  }
}

let min = 9999999;

pick(-1, []);

// M개 조합
function pick(idx, arr) {
  if (arr.length >= M) {
    findMin(arr);
    return;
  }
  for (let i = idx; i < chicken.length - 1; i++) {
    let newArr = [...arr];
    newArr.push(i + 1);
    pick(i + 1, newArr);
  }
}

function findMin(pickedIdx) {
  let l = 0;
  for (let houseNum = 0; houseNum < house.length; houseNum++) {
    let minL = 9999;
    for (idx of pickedIdx) {
      let length = chickenLength[idx][houseNum];
      if (length < minL) {
        minL = length;
      }
    }
    l += minL;
  }
  if (l < min) min = l;
}

console.log(min);
