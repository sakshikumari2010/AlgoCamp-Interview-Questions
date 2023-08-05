#include<iostream>
using namespace std;

// Question: Given a positive integer N, count all possible distinct binary strings of length N, such that there are no consecutive 1's. Ex- N =2 Output = 3 
// The strings are 00, 01,10

// Here is a pattern in answer can be observe
// N = 1 Output- 2
// N = 2       - 3
// N = 3       - 5
// N = 4       - 8
// N = 5       - 13
// N = 6       - 21
// The answer is sum of previous two element. 

int fibNum(int num){
    if(num == 1) return 2;
    if(num == 2) return 3;

    return fibNum(num - 1) + fibNum(num - 2);
}


int main(){
    int n = 4;
    cout<<fibNum(4)<<endl;

    return 0;
}