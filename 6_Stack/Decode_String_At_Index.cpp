#include <bits/stdc++.h>
using namespace std;


string decodeAtIndex(string s, int k)
{
    stack<pair<char,  long long int>> st;
   long long  int len = 0;
    string ch;
    for (int i = 0; i < s.size(); i++)
    {

        if (k > len){
            if (s[i] > 48 && s[i] <= 57){
                // cout << "Int : " << s[i] << endl;
                len = len * (s[i] - '0');
                // cout << "I am Length :" << len << endl;
            }else{
                len = len + 1;
                // cout << "Len : " << len << endl;
            }
            
        }
        if (s[i] > 58 || s[i] < 47) {
            st.push({s[i], len});
        }

        
        if (len >= k) {
            break;
        }
    }

    while (k != 0)
    {
        pair<char, int> p;
        p = st.top();
        len = p.second;
        // cout << k << " Len : " << len << endl;
        k = k % len;
        ch = p.first;
        st.pop();
    }
    return ch;
}


int main()
{

    string s = "leet2code3";
    cout << " Index at 10 : " << decodeAtIndex(s, 10) << endl;
    cout << " Index at 8 : " << decodeAtIndex(s, 8) << endl;

    return 0;
}