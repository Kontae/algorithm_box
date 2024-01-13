#include <iostream>
#include <vector>
using namespace std;
int change(int n)
{
	if (n == 0) return 1;
	else return 0;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int s_num;
	cin >> s_num;
	vector<int> v(s_num + 1, 0);
	for (int i = 1; i <= s_num; i++)
	{
		cin >> v[i];
	}
	int n;
	cin >> n;
	while (n--)
	{
		int sex, num;
		cin >> sex >> num;
		//남
		if (sex == 1)
		{
			int plus = num;
			while (num <= s_num)
			{
				v[num]=change(v[num]);
				num += plus;
			}
		}
		//여
		else
		{
			int left = num-1;
			int right = num+1;
			while (left >=1  && right <= s_num)
			{
				if (v[left] == v[right])
				{
					v[left]=change(v[left]);
					v[right]=change(v[right]);
					left--;
					right++;
				}
				else break;
			}
			v[num] = change(v[num]);
		}
	}

	for (int i = 1; i <= s_num; i++)
	{
		cout << v[i] << " ";
		if (i % 20 == 0)
			cout << "\n";
	}
	return 0;
}