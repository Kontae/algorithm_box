#include <iostream>
#include <list>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n, k;
	cin >> n >> k;
	list<int> li;
	
	for (int i = 0; i < n; i++)
	{
		li.push_back(i+1);
	}
	
	list<int>::iterator it = li.begin();
	cout << "<";
	while (li.size()!=1)
	{
		for (int i = 0; i < k-1; i++)
		{
			it++;
			if (it == li.end()) it = li.begin();
			//범위 맞춰줌
		}
		cout << *it << ", ";
		it = li.erase(it);
		//지우고 난 후, 인덱스 맞춰줌
		if (it == li.end())	it = li.begin();
		//지우고 나서도 범위 판단 
	}
	cout << *it << ">" << '\n';

	return 0;
}
