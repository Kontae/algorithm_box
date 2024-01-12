#include <iostream>
#include <algorithm>
using namespace std;
struct DC {
	int w;
	int h;
	int rank;
};
DC arr[51];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i].w >> arr[i].h;
		arr[i].rank = 1;
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (arr[i].w < arr[j].w && arr[i].h < arr[j].h)
			{
				arr[i].rank++;
			}
		}
	}
	for (int i = 0; i < n; i++)
	{
		cout << arr[i].rank << " ";
	}
	return 0;
}