#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int arr[1001];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int tc;
	cin >> tc;
	vector<int> v;
	for(int t=1;t<=tc;t++)
	{
		int n;
		cin >> n;
		int ans = 0;
		for (int i = 0; i < n; i++)
		{
			cin >> arr[i];
		}
		v.push_back(arr[0]);
		ans++;
		for (int i = 1; i < n; i++)
		{
			//크면 그대로 배열 생성
			if (v.back() < arr[i])
			{
				v.push_back(arr[i]);
				ans++;
			}
			//작거나 같으면 뒤에서부터 갱신 필요함
			else
			{
				bool flag = false;
				for (int j = v.size()-1; j >=0 ; j--)
				{
					if (v[j] < arr[i])
					{
						v[j+1] = arr[i];
						flag = true;
						break;
					}
				}
				if (!flag) v[0] = arr[i];
			}
		}
		
		cout << "#" << t << " " << n - ans << '\n';
		v.clear();
	}
	return 0;
}