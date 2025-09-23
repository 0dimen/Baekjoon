let fs = require("fs");
const filePath = process.platform === "linux" ? "/dev/stdin" : "js/example.txt";
let input = fs.readFileSync(filePath, "utf8").trim().split("\n");
let [N, d, k, c] = input[0].split(" ").map((v) => Number(v));
c = `${c}`;
let dishes = [];
for (let n = 1; n <= N; n++) {
  dishes.push(input[n]);
}
let select = new Map();
add(c);

for (let i = 0; i < k; i++) {
  let d = dishes[i];
  if (select.has(d)) {
    select.set(d, select.get(d) + 1);
  } else {
    select.set(d, 1);
  }
}

let max = select.size;

for (let i = 1; i < N; i++) {
  let cur = dishes[(i + k - 1) % N];
  if (dishes !== c) {
    add(cur);
  }

  let prev = dishes[i - 1];
  if (prev !== c) {
    let num = select.get(prev);
    if (num > 1) {
      select.set(prev, num - 1);
    } else {
      select.delete(prev);
    }
  }

  if (max < select.size) {
    max = select.size;
  }
}

function add(d) {
  if (select.has(d)) {
    select.set(d, select.get(d) + 1);
  } else {
    select.set(d, 1);
  }
}

console.log(max);
