#include<iostream>
using namespace std;

int count = 0;

void printSequence(string s, int ind, string output){
    if(ind == s.size()){
        cout<<output<<endl;
        count++;
        return;
    }
    printSequence(s, ind +1, output + s[ind]);
    printSequence(s, ind + 1, output);
}



int main(){
    string str = "abc";
    printSequence(str, 0, "");
    cout<<count<<endl;

    return 0;
}