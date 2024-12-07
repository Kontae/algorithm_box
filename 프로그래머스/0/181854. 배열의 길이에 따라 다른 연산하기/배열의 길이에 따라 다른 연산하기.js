function solution(arr, n) {
    var answer = [];
    answer = arr.map((x,idx)=>{
        return arr.length%2===idx%2
        ? x
        : x+n
    });
    return answer;
}