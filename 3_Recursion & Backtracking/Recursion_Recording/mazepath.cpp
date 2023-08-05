#include<iostream>

using namespace std;

int ways = 0;

void printPaths(int i, int j, int n, int m, string output){
    if(i == n-1 && j == m-1){
        cout<<output<<endl;
        ways++;
        return;
    }
    if(i >= n || j >= m) return; // when gone beyond the grid.
     printPaths(i+1, j,n, m, output + "D"); // we go down side
     printPaths(i, j+1, n, m, output + "R"); // we go right side.
}


int totalPaths(int i, int j, int n, int m){
    if(i == n-1 && j == m-1){
        return 1;
    }
    if(i >= n || j >= m) return 0;
    
    return totalPaths(i+1, j,n, m ) + totalPaths(i, j+1, n, m );
}


int main(){
    printPaths(0,0,4,4,"");
    cout<<ways<<endl;
   cout<< totalPaths(0,0,4,4)<<endl;
    return 0;
}