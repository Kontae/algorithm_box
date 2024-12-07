function solution(arr, n) {
    var answer = [];
    let length = arr.length;
    arr.forEach((x,idx)=>{
        if(length%2===1){
            if(idx%2===1){
                answer.push(x);
            }
            else{
                answer.push(x+n);
            }
        }
        else{
            if(idx%2===0){
                answer.push(x);
            }
            else{
                answer.push(x+n);
            }
        }
    })
    return answer;
}