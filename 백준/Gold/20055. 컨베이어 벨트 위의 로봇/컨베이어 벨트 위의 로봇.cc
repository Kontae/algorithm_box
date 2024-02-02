#include <iostream>
using namespace std;
int n, k, zeroCnt, answer;
int belt[202];
bool robot[202];
void Input()
{
	cin >> n >> k;
	for (int i = 0; i < 2 * n; i++)
	{
		cin >> belt[i];
	}
}
void Rotate()
{
	int tmp = belt[2 * n - 1];
	for (int i = 2 * n - 1; i >= 0; i--)
	{
		if (i == 0)
		{
			belt[0] = tmp;
			break;
		}
		belt[i] = belt[i - 1];
	}

	robot[n-1] = false;
	for (int i = n - 2; i >= 1; i--)
	{
		robot[i] = robot[i - 1];
	}
	robot[0] = false;
}
void Move()
{
	for (int i = n - 1; i >= 0; i--)
	{
		if (robot[i])
		{
			if (!robot[i + 1] && belt[i + 1] >= 1)
			{
				if (belt[i + 1] == 1)zeroCnt++;
				if (i == n - 1)
				{
					robot[i] = false;
					belt[i + 1]--;
					continue;
				}
				robot[i] = false;
				robot[i + 1] = true;
				belt[i + 1]--;
			}
		}
	}
}

void Load()
{
	if (belt[0] >= 1)
	{
		if (belt[0] == 1)
		{
			zeroCnt++;
		}
		robot[0] = true;
		belt[0]--;
	}
}

void Execute()
{
	while(zeroCnt<k)
	{
		answer++;
		Rotate();
		Move();
		Load();
	}
	cout << answer << '\n';
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	Input();
	Execute();
	

	return 0;
}