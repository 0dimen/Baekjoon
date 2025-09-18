let fs = require("fs");
const filePath = process.platform === "linux" ? "/dev/stdin" : "js/example.txt";
let input = fs.readFileSync(filePath, "utf8").trim().split("\n");

let [N, K] = input[0].split(" ").map((v) => Number(v));
let A = input[1].split(" ").map((v) => Number(v));
let k = [];
function merge_sort(A, p, r) {
  if (p < r) {
    let q = Math.floor((p + r) / 2);
    // 1/2씩 쪼개서 sorting하기
    merge_sort(A, p, q);
    merge_sort(A, q + 1, r);
    merge(A, p, q, r);
  }
}

function merge(A, p, q, r) {
  let i = p;
  let j = q + 1;

  let temp = [];
  while (i <= q && j <= r) {
    if (A[i] <= A[j]) {
      // 오른쪽 배열보다 작은 경우
      temp.push(A[i++]);
      k.push(temp[temp.length - 1]);
    } else {
      temp.push(A[j++]);
      k.push(temp[temp.length - 1]);
    }
  }
  while (i <= q) {
    // 남은 왼쪽 배열
    temp.push(A[i++]);
    k.push(temp[temp.length - 1]);
  }
  while (j <= r) {
    // 남은 오른쪽 배열
    temp.push(A[j++]);
    k.push(temp[temp.length - 1]);
  }
  // 배열 바꿔치기
  A.splice(p, temp.length, ...temp);
}

merge_sort(A, 0, A.length - 1);
console.log(k[K - 1] ? k[K - 1] : -1);
