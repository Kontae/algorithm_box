#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

void sumDFS(vector<vector<int>>& dice, vector<int>& v, vector<int>& sumV, int count, int sum) {
    if (count == 0) {
        sumV.push_back(sum);
        return;
    }
    for (int i = 0; i < 6; i++) {
        int cur = dice[v[count - 1]][i];
        sumDFS(dice, v, sumV, count - 1, sum + cur);
    }
}

// 주사위 나눠 갖는 모든 조합 저장
// ex) A [[1,2],[1,3],[1,4],[2,3],...] B [[3,4],[2,4],[2,3],[1,4],...]
vector<vector<int>> generateAllCombinations(int n, int k) {
    vector<vector<int>> combinations;
    
    vector<int> v(n, 0);
    fill(v.end() - k, v.end(), 1);
    do {
        vector<int> comb;
        for (int i = 0; i < n; i++) {
            if (v[i] == 1) {
                comb.push_back(i);
            }
        }
        combinations.push_back(comb);
    } while (next_permutation(v.begin(), v.end()));
    
    return combinations;
}

vector<int> solution(vector<vector<int>> dice) {
    vector<int> answer;
    int n = dice.size();
    int half = n / 2;
    
    vector<vector<int>> allCombinationsA = generateAllCombinations(n, half);
    
    int maxWins = -1;
    vector<int> bestCombination;
    
    for (auto& combA : allCombinationsA) {
        vector<int> combB;
        for (int i = 0; i < n; i++) {
            if (find(combA.begin(), combA.end(), i) == combA.end()) {
                combB.push_back(i);
            }
        }
        
        vector<int> sumsA, sumsB;
        sumDFS(dice, combA, sumsA, combA.size(), 0);
        sumDFS(dice, combB, sumsB, combB.size(), 0);
        
        // 이진 탐색
        int wins = 0;
        sort(sumsB.begin(), sumsB.end());
        for (int sumA : sumsA) {
            auto it = lower_bound(sumsB.begin(), sumsB.end(), sumA);
            wins += (it - sumsB.begin());
        }
        
        if (wins > maxWins) {
            maxWins = wins;
            bestCombination = combA;
        }
    }
    
    for (int idx : bestCombination) {
        answer.push_back(idx + 1);
    }
    
    return answer;
}