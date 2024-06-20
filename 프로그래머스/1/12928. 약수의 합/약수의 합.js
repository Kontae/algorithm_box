function solution(n) {
    var answer = 0;
    for(let i=1;i<=Math.sqrt(n);i++){
        if(n%i==0){
            answer+=i;
            if(i*i!==n)
            answer+=(n/i);
        }
    }
    return answer;
}