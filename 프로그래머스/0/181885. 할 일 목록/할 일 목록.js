function solution(todo_list, finished) {
    return todo_list.filter((x,idx)=>finished[idx]===false)
}