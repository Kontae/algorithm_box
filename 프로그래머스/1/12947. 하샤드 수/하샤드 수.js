function solution(x) {
    return x%String(x).split('').map(Number).reduce((a,b)=>a+b)===0;
}