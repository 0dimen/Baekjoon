let fs = require("fs");
const filePath = process.platform === "linux" ? "/dev/stdin" : "js/example.txt";
let input = fs.readFileSync(filePath, "utf8").trim().split("\n");

let N = Number(input[0]);

let refs = [];

for (let i = 1; i <= N; i++) {
  let [min, max] = input[i].split(" ").map((v) => Number(v));
  let flag = false;
  for (let j = 0; j < refs.length; j++) {
    let [rMin, rMax] = refs[j];
    if (rMin <= min && rMax >= max) {
      // 사이인 경우
      refs[j] = [min, max];
      flag = true;
    } else if (rMax >= min && rMin <= min) {
      // min이 사이에 있는 경우
      refs[j][0] = min;
      flag = true;
    } else if (rMin <= max && rMax >= max) {
      // max가 사이에 있는 경우
      refs[j][1] = max;
      flag = true;
    }
  }
  if (flag === false) {
    refs.push([min, max]);
  }
}
console.log(refs.length);
