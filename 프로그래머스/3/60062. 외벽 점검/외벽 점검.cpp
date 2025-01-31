#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int solution(int n, vector<int> weak, vector<int> dist) {
    int answer = -1;
    vector<int> circle_weak = weak;
    for(auto x : weak){
        circle_weak.push_back(x+n);
    }
    
    for(int i=0;i<weak.size();i++){
        do{
            int wI=i,dI=0,cnt=0;
            for(dI;dI<dist.size();dI++){
                int distance = circle_weak[wI]+dist[dI];
                while(distance>=circle_weak[wI]&&cnt<weak.size()){
                    wI++; cnt++;
                }
                if(cnt==weak.size()){
                    break;
                }
            }
            if(cnt==weak.size()){
                int result = dI+1;
                if(answer==-1) answer=result;
                else answer= min(answer,result);
            }
        }while(next_permutation(dist.begin(),dist.end()));
    }
    
    
    return answer;
}