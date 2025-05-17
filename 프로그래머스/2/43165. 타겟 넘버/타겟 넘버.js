let answer=0;

function DFS(result, cnt, numbers, target){
    if(cnt===numbers.length){
        if(result===target) answer++;
        return;
    } 
    DFS(result+numbers[cnt],cnt+1,numbers,target);
    DFS(result-numbers[cnt],cnt+1,numbers,target);
}

function solution(numbers, target) {
    DFS(0,0,numbers,target);
    return answer;
}