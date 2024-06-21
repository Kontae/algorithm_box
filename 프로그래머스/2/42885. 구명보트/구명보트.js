function solution(people, limit) {
    var answer = 0;
    let n = people.length;
    let count =0;
    people.sort((a,b)=>a-b);
    
    for(let i=0,j=n-1;i<j;j--){
        if(people[i]+people[j]<=limit){
            i++;
            count++;
        }
    }
    return n-count;
}