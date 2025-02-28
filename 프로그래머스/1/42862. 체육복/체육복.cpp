#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    for(int i=0;i<lost.size();i++)
    {
        for(int j=0;j<reserve.size();j++)
        {
            if(lost[i]==reserve[j])
            {
                lost.erase(lost.begin()+i);
                reserve.erase(reserve.begin()+j);
                i--;
                //i쪽에서 다시 0부터 탐색하기위함
                break;
                //j쪽에서 다시 탐색하기 위함
            }
        }
    }
    //여벌 체육복 있는데 도난 당한 학생 제외

    answer=n-lost.size();
    //실행 전 체육복 있는 학생 수
    sort(lost.begin(),lost.end());
    sort(reserve.begin(),reserve.end());
    for(int i=0;i<lost.size();i++)
    {
        for(int j=0;j<reserve.size();j++)
        {
            if(lost[i]-1==reserve[j]||lost[i]+1==reserve[j])
            {
                reserve.erase(reserve.begin()+j);
                answer++;
                break;
            }
        }
    }
    //체육복 하나씩 빌려주는 과정
    return answer;
}