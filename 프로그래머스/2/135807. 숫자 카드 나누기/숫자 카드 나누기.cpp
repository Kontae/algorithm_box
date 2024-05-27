#include <string>
#include <vector>
#include <algorithm>


using namespace std;
int GCD(int a, int b)
{
    if(b==0) return a;
    return GCD(b,a%b);
}

int vecGCD(vector<int> a)
{
    int tmp=a[0];
    for(int i=1;i<a.size();i++)
    {
        tmp = GCD(tmp,a[i]);
    }
    return tmp;
}


int solution(vector<int> arrayA, vector<int> arrayB) {
    int answer = 0;
    int valA=vecGCD(arrayA);
    int valB=vecGCD(arrayB);
    bool flagA = true;
    bool flagB = true;
    for(int i=0;i<arrayB.size();i++)
    {
        if(arrayB[i]%valA==0){
            flagA = false; break;
        }
    }
    if(flagA) answer = valA;
    
    for(int i=0;i<arrayA.size();i++)
    {
        if(arrayA[i]%valB==0){
            flagB = false; break;
        }
    }
    if(flagB) answer= answer > valB ? answer: valB;
    
    return answer;
}