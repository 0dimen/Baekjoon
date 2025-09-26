let fs = require("fs");
const filePath = process.platform === "linux" ? "/dev/stdin" : "js/example.txt";
let input = fs.readFileSync(filePath, "utf8").trim().split("\n");

let [M, N, H] = input[0].split(" ").map((v) => Number(v));
let boxDays = [];
let originBox = [];
let lineN = 1;
for (let i = 1; i <= H; i++) {
  let floor = [];
  let boxFloor = [];
  for (let n = 0; n < N; n++) {
    let line = input[lineN++].split(" ").map((v) => Number(v));
    let col = [];
    for (let m = 0; m < M; m++) {
      if (line[m] === -1) {
        col.push(-1);
      } else {
        col.push(Infinity);
      }
    }
    floor.push(line);
    boxFloor.push(col);
  }
  boxDays.push(boxFloor);
  originBox.push(floor);
}

let directions = [
  [0, 0, 1],
  [0, 0, -1],
  [0, 1, 0],
  [0, -1, 0],
  [1, 0, 0],
  [-1, 0, 0],
];

//
function bfs(firstX, firstY, firstZ) {
  let queue = [[firstX, firstY, firstZ]];
  let n = 0;
  while (queue.length != 0) {
    let newQ = [];
    for (q of queue) {
      let [x, y, z] = q;
      if (boxDays[z][y][x] <= n) {
        continue;
      }

      boxDays[z][y][x] = n;

      for (dir of directions) {
        let dx = dir[0] + x;
        let dy = dir[1] + y;
        let dz = dir[2] + z;
        if (dx >= 0 && dx < M && dy >= 0 && dy < N && dz >= 0 && dz < H) {
          if ((boxDays[dz][dy][dx] !== 0) & (boxDays[dz][dy][dx] > n + 1)) {
            newQ.push([dx, dy, dz]);
          }
        }
      }
    }
    queue = newQ;
    n++;
  }
}

for (let k = 0; k < H; k++) {
  for (let j = 0; j < N; j++) {
    for (let i = 0; i < M; i++) {
      if (originBox[k][j][i] === 1) {
        bfs(i, j, k);
      }
    }
  }
}

// 전체적으로 0인 토마토 있는지 확인.
let maxDays = 0;
done: for (let k = 0; k < H; k++) {
  for (let j = 0; j < N; j++) {
    for (let i = 0; i < M; i++) {
      let days = boxDays[k][j][i];
      if (days === Infinity) {
        maxDays = Infinity;

        break done;
      }
      if (days > maxDays) {
        maxDays = days;
      }
    }
  }
}

if (maxDays !== Infinity) {
  console.log(maxDays);
} else {
  console.log(-1);
}
