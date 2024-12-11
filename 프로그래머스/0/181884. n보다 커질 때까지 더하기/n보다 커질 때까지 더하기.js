function solution(numbers, n) {
    
    return numbers.reduce((cur,acc)=>cur>n?cur:cur+acc,0);
}