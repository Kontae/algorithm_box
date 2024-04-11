#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T, N, M;
    int answer;
    cin >> T;
    for (int t = 1; t <= T; t++)
    {
        cin >> N >> M;
        cout << "#" << t << " ";
        for (int i = 1; i <= abs(N - M) + 1; i++)
        {
            if(N<M) cout << N + i << " ";
            else cout << M + i << " ";
        }
        cout << '\n';
    }

    return 0;
}
