let fs = require("fs");
let input = fs.readFileSync("example.txt").toString().split("\n");

let [N, M] = input[0].split(" ");
let woods = input[1].split(" ");

function binarySearch(low, high) {
  while (low <= high) {
    let mid = Math.floor(low + (high - low) / 2);
    let m = calc(mid);

    if (m == M) {
      return mid;
    } else if (m > M) {
      low = mid + 1;
    } else {
      high = mid - 1;
    }
  }

  return high;
}

function calc(minH) {
  let m = 0;
  for (w of woods) {
    if (w > minH) m += w - minH;
  }
  return m;
}

let minH = binarySearch(0, Math.max(...woods));

console.log(minH);
