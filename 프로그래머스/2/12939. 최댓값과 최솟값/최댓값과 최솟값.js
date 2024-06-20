function solution(s) {
    var answer = '';
    var arr = s.split(' ').map(n=>n=parseInt(n));
    arr.sort((a,b)=>a-b);
    
    return arr[0]+' '+arr[arr.length-1];
}