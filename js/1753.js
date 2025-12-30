let fs = require("fs");
const filePath = process.platform === "linux" ? "/dev/stdin" : "js/example.txt";
let input = fs.readFileSync(filePath, "utf8").trim().split("\n");
const INF = 2000001;
const [vNum, eNum] = input[0].split(" ").map((value) => Number(value));
const startNum = Number(input[1]) - 1;
const vectors = Array.from({ length: vNum }, (_) => []);
const d = Array.from({ length: vNum }, (_) => INF);
d[startNum] = 0;

for (let i = 2; i < eNum + 2; i++) {
  var [u, v, w] = input[i].split(" ").map((v) => Number(v));
  vectors[u - 1].push([v - 1, w]);
}

class MinHeap {
  constructor() {
    this.heap = [];
  }

  push(value) {
    this.heap.push(value);

    this.bubbleUp();
  }

  pop() {
    if (this.heap.length === 1) return this.heap.pop();
    const min = this.heap[0];
    this.heap[0] = this.heap.pop();
    this.bubbleDown();
    return min;
  }

  bubbleUp() {
    var targetIdx = this.heap.length - 1;
    var parentIdx = this.getParentIndex(targetIdx);
    while (targetIdx > 0 && this.heap[parentIdx][0] > this.heap[targetIdx][0]) {
      this.heap.push(this.heap[parentIdx]);
      this.heap[parentIdx] = this.heap[targetIdx];
      targetIdx = parentIdx;
      parentIdx = this.getParentIndex(targetIdx);
    }
  }

  bubbleDown() {
    var index = 0;
    const length = this.heap.length;

    while (true) {
      let min = index;
      const [leftIdx, rightIdx] = this.getChildIndex(index);

      if (leftIdx < length && this.heap[leftIdx][0] < this.heap[min][0]) {
        min = leftIdx;
      }
      if (rightIdx < length && this.heap[rightIdx][0] < this.heap[min][0]) {
        min = rightIdx;
      }
      if (min === index) break;

      [this.heap[index], this.heap[min]] = [this.heap[min], this.heap[index]];
      index = min;
    }
  }

  getParentIndex(index) {
    return Math.floor((index - 1) / 2);
  }
  getChildIndex(index) {
    return [2 * index + 1, 2 * index + 2];
  }
  length() {
    return this.heap.length;
  }
}

// 다익스트라
const q = new MinHeap();
q.push([0, startNum]);

while (q.length() > 0) {
  const [cost, current] = q.pop();
  if (cost > d[current]) continue;
  else {
    for ([next, nextCost] of vectors[current]) {
      nextCost += cost;
      if (nextCost < d[next]) {
        d[next] = nextCost;
        q.push([nextCost, next]);
      }
    }
  }
}

console.log(d.map((v) => (v === INF ? "INF" : v)).join("\n"));
