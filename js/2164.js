let fs = require("fs");
let input = fs.readFileSync("example.txt").toString().split("\n");
// let input = fs.readFileSync("/dev/stdin").toString().split("\n");

let N = Number(input[0]);

class LinkedList {
  constructor(v, prev, next) {
    this.v = v;
    this.prev = prev;
    this.next = next;
  }
  remove = () => {
    this.next.prev = this.prev;
    this.prev.next = this.next;
    // 삭제하고, 다음 다음카드로 이동.
    return this.next.next;
  };
}

function link(prev, next) {
  prev.next = next;
  next.prev = prev;
}

// list 초기화
let first = new LinkedList(1, null, null);
let last = new LinkedList(N, null, null);
link(last, first);

let temp = first;

for (let i = 2; i < N; i++) {
  let l = new LinkedList(i, null, null);
  link(temp, l);
  temp = l;
}
link(temp, last);

let current = first;

// 카드 작업
while (!(current.prev.v === current.next.v && current.v === current.prev.v)) {
  current = current.remove();
}

console.log(current.v);
