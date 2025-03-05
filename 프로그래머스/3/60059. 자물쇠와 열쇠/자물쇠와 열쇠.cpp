#include <string>
#include <vector>
#include <iostream>

using namespace std;

int grooveCount = 0; 
int m,n=0;

// 오른쪽으로 90도 회전시키는 함수
vector<vector<int>> rotateKey(vector<vector<int>>& key) {
    
    vector<vector<int>> newKey(n,vector<int>(m,0));
    
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<m;j++)
        {
            newKey[i][j]=key[m-1-j][i];
        }
    }
    
    return newKey;
}

// 가운데에 lock, 주변에 key 사이즈만큼 확장시키는 함수
vector<vector<int>> expandLock(vector<vector<int>>& lock)
{
    // 외부 영역은 -1로 초기화
    vector<vector<int>> newLock(2*(m-1)+n,vector<int>(2*(m-1)+n,-1));
    for(int i=m;i<m+n;i++)
    {
        for(int j=m;j<m+n;j++)
        {
            newLock[i-1][j-1]=lock[i-m][j-m];
            if(lock[i-m][j-m]==0) grooveCount++;
        }
    }
    return newLock;
    
}

bool check(vector<vector<int>>& key, vector<vector<int>>& lock, int iIdx, int jIdx)
{
    bool flag = false;
    int keyX=0;
    int keyY=0;
    int count=0;
    for(int a=iIdx;a<iIdx+m;a++,keyX++)
    {
        for(int b=jIdx;b<jIdx+m;b++,keyY++)
        {
            if(lock[a][b]==0 && key[keyX][keyY]==0) return false;
            if(lock[a][b]==1 && key[keyX][keyY]==1) return false;
            if(lock[a][b]==0 && key[keyX][keyY]==1) count++;
        }
        keyY=0;
    }
    return count==grooveCount;
}

bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
    m = key.size();
    n = lock.size();
    lock = expandLock(lock);
    
    for(int d=0;d<4;d++) {
       for(int i=0;i<m+n-1;i++) {
           for(int j=0;j<m+n-1;j++) {
                if(check(key,lock,i,j)) return true;
            }
        } 
        key = rotateKey(key);
    }
    
    return false;
}