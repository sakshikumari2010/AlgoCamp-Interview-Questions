#include<bits/stdc++.h>

using namespace std;

// Que 1 > Remove all adjacent duplicate in string.
// Que 2 > Valid Parenthesis
// Que 3 > Simplify Path
// Que 4> Remove Duplicate Letters



// Que 1 > Remove all adjacent duplicate in string.
 string removeDuplicates(string s) {
        stack<char> st;
        int n = s.size();
        st.push(s[0]);
        for(int i =1; i<n; i++){
            if(st.empty()){
                st.push(s[i]);
            }
            else{
                if(st.top() == s[i]){
                    st.pop();
                }
                else{
                    st.push(s[i]);
                }
            }
        }
        string ans = "";
        while(!st.empty()){
            ans += st.top();
            st.pop();

        }
         reverse(ans.begin(), ans.end());
         return ans;
        
    }


// Que 2 > Valid Parenthesis

bool isValid(string s) {
        int n = s.size();
        stack<char> st;

        for(int i =0; i<n; i++){

            if(s[i] == '(' || s[i] == '{' || s[i] == '['){
                st.push(s[i]);
            }
            else {
            if(st.empty()) return false; 
            if(s[i] == ')' && st.top() == '(')  st.pop();
            else if(s[i] == '}' && st.top() == '{')  st.pop();
            else if(s[i] == ']' && st.top() == '[')  st.pop();
            else return false;
            }
        }

        if(st.empty()) return true;
        return false;
}


// Que 3 > Simplify Path

 class Solution{
    public:
    string simplifyPath(string path) {
     vector<string> arr;
     int n = path.size();
     string word = "";
    for(int i =0; i< path.size(); i++){
        if(path[i] == '/' ) {
            arr.push_back(word);
            word = "";
        }else{
            word += path[i];
        }
    }
    if(path[n-1] !=  '/') arr.push_back(word);
    // for(auto x : arr) cout<<"Arr:  "<<x<<endl;

    stack<string> st;

    for(int i =0; i< arr.size(); i++){
        if(arr[i] == "" || arr[i] == ".") continue;
        else if(arr[i] == ".." ){
            if( !st.empty()) st.pop();
        }
        else{
            st.push(arr[i]);
        }
        // if(st.top()!= "")
        // cout<<"Top "<<st.top()<<endl;
    }
    string res = "";
    while(!st.empty()){
        res = "/"+ st.top()+ res;
        // cout<<"Res: "<<res<<endl;
        st.pop();
    }
    return (res.size() > 0)? res: "/";
 }

};

// Que 4> Remove Duplicate Letters

string removeDuplicateLetters(string s) {
        stack<char> st;
        set<char> seen;
        map<char, int> lastOccurence;
        for(int i = 0; i< s.length() ; i++){
            lastOccurence[s[i]] = i;
        }
        for(int i =0; i< s.length() ; i++){
            char c = s[i];
            if(seen.find(c) == seen.end()){
                while(!st.empty() && c < st.top() && lastOccurence[st.top()] > i)
                {
                    seen.erase(st.top());
                    st.pop();
                }
                seen.insert(c);
                st.push(c);
            }
        }
        string ans = "";
      while(!st.empty()){
          ans = ans + st.top();
          st.pop();
      }
      reverse(ans.begin(), ans.end());
      return ans;
        
    }