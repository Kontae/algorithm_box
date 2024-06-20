function solution(s){
    var answer = true;
    const strArr= [...s];
    var pc=0;
    var yc=0;
    strArr.map(x=>{
        if(x==='p'||x==='P') pc++;
        if(x==='y'||x==='Y') yc++;
    })
    answer=(pc===yc);
    return answer;
}