function solution(elements) {
    let sumSet = new Set();
    let n = elements.length;
    for(let i=0;i<n;i++) {
        let sum = 0;
        for(let j=i;j<i+n;j++) {
            sum+=elements[j%n];
            sumSet.add(sum);
        }
    }
    return sumSet.size;
}