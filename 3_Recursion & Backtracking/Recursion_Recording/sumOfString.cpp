#include<iostream>
#include<vector>

using namespace std;

int sumString(string s, int i){
    if(i == s.size() - 1) return (s[i] - '0');

    return sumString(s, i+1) + (s[i] - '0');
}



int main(){
    string st = "234519";
    cout<<sumString(st, 0);
}