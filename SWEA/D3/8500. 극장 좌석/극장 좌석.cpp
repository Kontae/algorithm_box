#include <iostream>
#include <algorithm>
using namespace std;
int arr[10001];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T, N;
    int answer;
    cin >> T;
    for (int t = 1; t <= T; t++)
    {
        cin >> N;
        answer = 0;
        for (int i = 0; i < N; i++)
        {
            cin >> arr[i];
            answer += arr[i];
        }
        answer += *max_element(arr, arr + N) + N;

        cout << "#" << t << " " << answer << '\n';
    }

    return 0;
}
