#include <iostream>
#include <stack>
using namespace std;
int arr[500001];
int ans[500001];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int N;
	stack<pair<int,int>> st;
	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		cin >> arr[i];
	}
	st.push({ arr[N],N });
	for (int i = N - 1; i >= 1; i--)
	{
		if (arr[i] < st.top().first)
		{
			st.push({ arr[i],i });
		}
		else if (arr[i] >= st.top().first)
		{
			while (!st.empty() && arr[i] >= st.top().first )
			{
				ans[st.top().second] = i;
				st.pop();
			}
			st.push({ arr[i],i });
		}
	}
	while (!st.empty())
	{
		ans[st.top().second] = 0;
		st.pop();
	}
	for (int i = 1; i <= N; i++)
	{
		cout << ans[i] << " ";
	}
	return 0;
}