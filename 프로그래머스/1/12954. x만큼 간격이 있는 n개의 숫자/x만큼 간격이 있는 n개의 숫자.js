function solution(x, n) {
    
    return Array(n).fill(x).map((cur,idx)=>cur*(idx+1));
}