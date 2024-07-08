const fs = require("fs");
const file = process.platform === "linux" ? "dev/stdin" : "./text.txt";
let input = fs.readFileSync(file).toString().trim().split("\n");

let num = input[0];

input.shift();
input.forEach(x=>{
    console.log(`${x[0]}${x[x.length-1]}`)          
})