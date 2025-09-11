let fs = require("fs");
const filePath = process.platform === "linux" ? "/dev/stdin" : "js/example.txt";
let input = fs.readFileSync(filePath).toString().split("\n");
// let input = fs.readFileSync("/dev/stdin").toString().split("\n");

let T = Number(input[0]);

// greedy이므로 중복확인 안해도 됨.
for (let t = 1; t <= T; t++) {
  let N = Number(input[t]);
  let methods = [[[0, 0, 0]]]; // 1,2, 3 순서
  // 내가 아닌 다른 methods의 값들에 대해
  for (let i = 3; i >= 1; i--) {
    // j는 더한 값
    for (let n = 0; n < methods.length; n++) {
      if (n + i > N) {
        // 앞으로의 값들이 n보다 크면 종료.
        break;
      }

      for (let k = 0, l = methods[n] ? methods[n].length : 0; k < l; k++) {
        let newM = { ...methods[n][k] };
        newM[i - 1]++;
        methods[n + i] ??= [];

        methods[n + i].push(newM);
      }
    }
  }

  console.log(calcMethods(methods[N]));
}

function calcMethods(methods) {
  let totalSum = 0;
  for (let m = 0; m < methods.length; m++) {
    let result = 1;
    let sum = 0;
    for (let j = 1; j <= 3; j++) {
      sum += methods[m][j - 1];
      result /= factorial(methods[m][j - 1]);
    }
    totalSum += result * factorial(sum);
  }
  return totalSum;
}

function factorial(n) {
  let answer = 1;
  for (let i = n; i > 1; i--) {
    answer *= i;
  }
  return answer;
}
