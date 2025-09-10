let fs = require("fs");
let input = fs.readFileSync("example.txt").toString().split("\n");
// let input = fs.readFileSync("/dev/stdin").toString().split("\n");

let N = Number(input[0]);
let yourCards;
let win;
let lose;
for (let t = 1; t <= N; t++) {
  let myCards = [];
  win = 0;
  lose = 0;

  yourCards = input[t].split(" ").map((v) => Number(v));

  for (let i = 1; i <= 18; i++) {
    if (!yourCards.includes(i)) {
      myCards.push(i);
    }
  }

  put(0, myCards, 0);
  console.log(lose, win);
}

// 카드 내기
function put(idx, myCards, score) {
  // 종료 조건
  if (idx === 9) {
    if (score > (19 * 9) / 2) {
      win++;
    } else {
      lose++;
    }
    return;
  }

  // 남은 카드로 돌리기.
  for (let i = 0; i < myCards.length; i++) {
    let lastCards = [...myCards];
    let newScore = score;
    if (yourCards[idx] < myCards[i]) {
      newScore += yourCards[idx] + myCards[i];
    }
    lastCards.splice(i, 1);
    put(idx + 1, lastCards, newScore);
  }
}
