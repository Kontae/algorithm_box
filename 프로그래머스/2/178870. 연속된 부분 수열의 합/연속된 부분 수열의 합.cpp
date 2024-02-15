#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> sequence, int k) {
    vector<int> answer;
    int left=0;
    int right=0;
    int sum=0;
    int MIN=1e9;
    int min_left,min_right;
    for(int right=0;right<sequence.size();right++)
    {
        sum+=sequence[right];
        while(sum>k&&left<=right)
        {
            sum-=sequence[left++];
        }
        if(sum==k)
        {
            if(right-left<MIN)
            {
                min_left=left;
                min_right=right;
                MIN=right-left;
            }
        }
    }
    answer.push_back(min_left);
    answer.push_back(min_right);
    return answer;
}