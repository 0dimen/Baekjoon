let fs = require("fs");
const filePath = process.platform === "linux" ? "/dev/stdin" : "js/example.txt";
let input = fs.readFileSync(filePath, "utf8").trim().split("\n");

let T = Number(input[0]);
let lineN = 1;

let directions = [
  [0, 1],
  [0, -1],
  [1, 0],
  [-1, 0],
];

for (let t = 1; t <= T; t++) {
  let N = Number(input[lineN++]);
  let map = [];
  let maxN = 0;
  let minRoomNum = N * N + 1;
  // line 초기화
  for (let i = 0; i < N; i++) {
    let line = input[lineN++].split(" ").map((v) => Number(v));
    map.push(line);
  }

  // BFS
  for (let Y = 0; Y < N; Y++) {
    for (let X = 0; X < N; X++) {
      if (map[Y][X] !== -1) {
        // 방문하지 않은 노드
        // 초기화
        let n = 0;
        let queue = [[X, Y]];
        let roomN = N * N + 1;

        while (queue.length != 0) {
          let newQ = [];
          for (q of queue) {
            let [x, y] = q;
            if (map[y][x] === -1) {
              continue;
            }

            // 최소 방 번호
            let roomNum = map[y][x];
            if (roomNum < roomN) {
              roomN = roomNum;
            }
            // 방문 처리
            map[y][x] = -1;
            n++;

            for (dir of directions) {
              let dx = dir[0] + x;
              let dy = dir[1] + y;

              if (dx >= 0 && dx < N && dy >= 0 && dy < N) {
                if (map[dy][dx] === roomNum + 1) {
                  newQ.push([dx, dy]);
                }
              }
            }
          }
          queue = newQ;
        }

        // 최소 노드 확인
        if (maxN < n) {
          maxN = n;
          minRoomNum = roomN;
        } else if (maxN === n) {
          if (minRoomNum > roomN) {
            minRoomNum = roomN;
          }
        }
      }
    }
  }
  console.log(`#${t} ${minRoomNum} ${maxN}`);
}
