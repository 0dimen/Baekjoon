let fs = require('fs');
let input = fs.readFileSync('example.txt').toString().split('\n');

let count = input[0];
let numbers = [];

for(let i = 1; i <= count; i++){
    numbers.push(input[i].split(' ').map((el) => parseInt(el)));
}

for(let i = 0; i < input[0][0]; i++){
    let H = numbers[i][0];
    let W = numbers[i][1];
    let N = numbers[i][2];
    H = N % H;
    W = (N - H * W) % W;
    if(W < 10){
        W = "0" + W;
    }
    console.log(H + ""+W);
}

return 0;
