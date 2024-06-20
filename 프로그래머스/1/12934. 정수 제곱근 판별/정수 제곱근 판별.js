function solution(n) {
    var answer = 0;
    let tmp = parseInt(Math.sqrt(n));
    if(tmp*tmp===n) return (tmp+1)*(tmp+1);
    else return -1;
}