#include<iostream>

using namespace std;
void removeStr(string s, int i, char c, string output){
    if(i == s.size()) {
        cout<<output<<endl;
        return;
    }
    if(s[i] == c){
        removeStr(s, i+1, c, output);
        // return;
    }
  else  removeStr(s, i+1, c, output + s[i]);
}
int main(){
    string s = "mnbvxxdfrxxxsedx";
    removeStr(s, 0, 'x', "");
    return 0;
}