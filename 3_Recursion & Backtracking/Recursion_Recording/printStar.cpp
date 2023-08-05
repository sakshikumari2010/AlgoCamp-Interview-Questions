#include<iostream>

using namespace std;

void printStar(int row, int col, int n){
    if(row > n) return;
    if(col > row){
        printf("\n");
        printStar(row+1, 0, n);
        return;
    }
    printf("*");
    printStar(row, col + 1, n);
}



int main(){

    printStar(0,0,5);

    return 0;
}
