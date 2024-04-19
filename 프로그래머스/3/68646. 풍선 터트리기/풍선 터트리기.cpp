#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(vector<int> a) {
    int answer = 0;
    vector<int> left_min(a.size());
    vector<int> right_min(a.size());
    int min = a[0];
    for(int i = 0 ; i < a.size() ; i++)
    {
        if(a[i] < min) min = a[i];
        //각 인덱스마다 왼쪽값의 최솟값
        left_min[i] = min;
    }
    min = a[a.size() - 1];
    for(int i = a.size() - 1 ; i >= 0 ; i--)
    {
        if(a[i] < min) min = a[i];
        right_min[i] = min;
    }
    for(int i = 0 ; i < a.size() ; i++)
    {
        if(a[i] <= left_min[i] || a[i] <= right_min[i]) answer++;
    }
    return answer;
}