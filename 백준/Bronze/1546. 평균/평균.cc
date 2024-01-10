#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int n;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	double sum = 0;
	cin >> n;
	vector<double> score(n);
	for (int i = 0; i < n; i++)
	{
		cout << fixed;
		cout.precision(3);
		cin >> score[i];
	}
	int mx_score = *max_element(score.begin(), score.end());
	for (auto x : score)
	{
		x = x / mx_score * 100;
		sum += x;
	}
	cout << sum / score.size() << '\n';
	
}