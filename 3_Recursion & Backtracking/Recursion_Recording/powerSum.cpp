#include<iostream>
#include<math.h>

using namespace std;
int result =0;
void f(int x, int n, int i){
    int p = (int) pow(i,n);
    if(x == 0){
        result++;
        return;

    }
    if(i * i > x) return;
    if( x < 0) return ;
    f(x-p, n, i+1);
    f(x,n, i+1);
}
int powerSum(int X, int N){
    f(X, N,1);
    return result;
}
int main(){
int n,x;
cin>>x>>n;
cout<<powerSum(x,n);

    return 0;
}