function solution(want, number, discount) {
    var answer = 0;
    const map = new Map();
    for(let i=0;i<discount.length-9;i++){
        const tmp=discount.slice(i,i+10);
        tmp.forEach(x=>{
            if(map.has(x)){
                map.set(x,map.get(x)+1);
            }
            else{
                map.set(x,1);
            }
        })
        let flag = true;
        for(let j=0;j<want.length;j++){
            if(map.get(want[j])!==number[j])flag=false;
        }
        if(flag===true) answer++;
        map.clear();
    }
    return answer;
}