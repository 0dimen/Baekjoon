let fs = require("fs");
const filePath = process.platform === "linux" ? "/dev/stdin" : "js/example.txt";
let input = fs.readFileSync(filePath, "utf8").trim().split("\n");

const N = Number(input[0]);

let tree = new Map();

// 트리 기록

for (let n = 1; n <= N; n++) {
  const [root, l, r] = input[n].split(" ").map((v) => (v === "." ? null : v));

  tree.set(root, { ...tree.get(root), lNode: l, rNode: r });
  if (l !== null) {
    tree.set(l, { pNode: root, lNode: null, rNode: null });
  }
  if (r !== null) {
    tree.set(r, { pNode: root, lNode: null, rNode: null });
  }
}

const treeRoot = findRoot();

// 루트 노드 찾기
function findRoot() {
  let root = input[1][0];
  let node = tree.get(root);
  while (node.pNode !== undefined) {
    root = node.pNode;
    node = tree.get(root);
  }
  return root;
}

let result;

console.log(rLR());
console.log(LrR());
console.log(LRr());

function rLR() {
  result = "";
  recursiverLR(treeRoot);
  return result;
}

function recursiverLR(root) {
  const node = tree.get(root);
  result += root;
  if (node.lNode !== null) {
    recursiverLR(node.lNode);
  }
  if (node.rNode !== null) {
    recursiverLR(node.rNode);
  }
}

function LrR() {
  result = "";
  recursiveLrR(treeRoot);

  return result;
}

function recursiveLrR(root) {
  const node = tree.get(root);
  if (node.lNode !== null) {
    recursiveLrR(node.lNode);
  }
  result += root;

  if (node.rNode !== null) {
    recursiveLrR(node.rNode);
  }
}

function LRr() {
  result = "";
  recursiveLRr(treeRoot);

  return result;
}

function recursiveLRr(root) {
  const node = tree.get(root);
  if (node.lNode !== null) {
    recursiveLRr(node.lNode);
  }
  if (node.rNode !== null) {
    recursiveLRr(node.rNode);
  }
  result += root;
}
