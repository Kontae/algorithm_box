#include <iostream>
#include <string>

using namespace std;

int main(void) {
    string str;
    cin >> str;
    for(auto &x: str){
        cout<<x<<'\n';
    }
    return 0;
}