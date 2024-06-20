function solution(n) {
    var answer='';
    const arr=String(n).split('').sort((a,b)=>b-a).map(Number);
    arr.forEach(x=> answer+=x)
    return parseInt(answer);
}