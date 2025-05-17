function solution(participant, completion) {
    let map = {};
    participant.forEach(x=>map[x]=(map[x]||0)+1);
    completion.forEach(x=>map[x]--);
    return Object.keys(map).find(x=>map[x]!==0);
}