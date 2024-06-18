#include <string>
#include <vector>
#include <unordered_map>
using namespace std;
typedef long long ll;
ll solution(vector<int> weights) {
    ll answer = 0;
    unordered_map<int,ll> m;
    for(auto x:weights)
    {
        m[x]++;
    }
    for(auto x:m)
    {
        ll w=x.first;
        ll c=x.second;
        if (c > 1)
			answer += (c * (c - 1) / 2);

		if (w * 3 % 2 == 0)
			if (m.find(w * 3 / 2) != m.end())
				answer += (m[w * 3 / 2] * c);

		if (w * 4 % 2 == 0)
			if (m.find(w * 4 / 2) != m.end())
				answer += (m[w * 4 / 2] * c);

		if (w * 4 % 3 == 0)
			if (m.find(w * 4 / 3) != m.end())
				answer += (m[w * 4 / 3] * c);
    }
    return answer;
}