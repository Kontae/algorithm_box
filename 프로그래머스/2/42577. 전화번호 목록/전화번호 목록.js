function solution(phone_book) {
    phone_book.sort((a,b)=>a.length-b.length);
    let map = {};
    for(const num of phone_book){
        let tmp = "";
        for(const x of [...num]){
            tmp+=x;
            if(map[tmp]) return false;
        }
        map[num]=true;
    }
    return true;
}