#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int num;
    int answer = 0;
    vector<int> v;
    cin >> num;
    for (int i = 0; i < num; i++)
    {
        int x;
        cin >> x;
        v.push_back(x);
    }
    sort(v.begin(), v.end());
    if (v.size() != 1)
        answer = v[0] * v[num-1];
    else
        answer = v[0] * v[0];

    cout << answer;
    return 0;
}