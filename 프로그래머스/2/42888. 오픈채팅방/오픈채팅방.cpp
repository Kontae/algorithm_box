#include <string>
#include <vector>
#include <map>
#include <sstream>
using namespace std;

vector<string> solution(vector<string> record) {
    vector<string> answer;
    vector<string> v;
    map<string,string> m;
    vector<string> result;
    for(int i=0;i<record.size();i++)
    {
        string fi,se,th;
        stringstream ss(record[i]);
        ss>>fi>>se>>th;
        
        if(fi=="Enter")
        {
            v.push_back("님이 들어왔습니다.");
            answer.push_back(se);
            m[se]=th;
        }
        else if(fi=="Leave")
        {
            v.push_back("님이 나갔습니다.");
            answer.push_back(se);
        }
        else if(fi=="Change")
        {
            m[se]=th;
        }
    }
    for(int i=0;i<answer.size();i++)
    {
        result.push_back(m[answer[i]]+v[i]);
    }
    return result;
}