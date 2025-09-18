let fs = require("fs");
const filePath = process.platform === "linux" ? "/dev/stdin" : "js/example.txt";
let input = fs.readFileSync(filePath, "utf8").trim().split("\n");
// let input = fs.readFileSync("/dev/stdin").toString().split("\n");

let T = Number(input[0]);
let minPrice;
let price;
let plan;
for (let t = 1; t <= T; t++) {
  price = input[t].split(" ").map((v) => Number(v));
  plan = input[t + 1].split(" ").map((v) => Number(v));
  let priceArr = [];

  for (p of plan) {
    if (p > 0) {
      priceArr.push(0);
    } else {
      priceArr.push(-1);
    }
  }
  minPrice = price[3];
  combi(priceArr, 0);

  console.log(minPrice);
}

function combi(priceArr, arrIdx) {
  if (arrIdx >= 12) {
    return;
  }
  calcPrice(priceArr);
  combi(priceArr, arrIdx + 1);

  for (let m = arrIdx; m < 12; m++) {
    let newPriceArr = [...priceArr];
    switch (priceArr[m]) {
      case 0:
        newPriceArr[m] = 1;

        combi(newPriceArr, arrIdx + 1);
        break;
      case 1:
        newPriceArr[m] = 2;
        if (newPriceArr[m + 1] != undefined) newPriceArr[m + 1] = -1;
        if (newPriceArr[m + 2] != undefined) newPriceArr[m + 2] = -1;
        combi(newPriceArr, arrIdx + 1);
        break;
    }
  }
}

function calcPrice(priceArr) {
  let p = 0;
  for (let m = 0; m < 12; m++) {
    switch (priceArr[m]) {
      case 0:
        p += plan[m] * price[0];
        break;
      case 1:
        p += price[1];
        break;
      case 2:
        p += price[2];
        break;
    }
  }

  if (p < minPrice) {
    minPrice = p;
    console.log(priceArr);
  }
}
