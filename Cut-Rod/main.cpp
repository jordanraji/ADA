#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include <math.h>

using namespace std;

int CutRod(int p[], int n){
    if(n==0){
        return 0;
    }
    int q=-99999999;
    for (int i=0; i<n ; i++) {
        q = max(q, p[i]+CutRod(p, n-i-1));
    }
    return q;

}

int MemoizedCutRodAux(int p[], int n, int r[]){
    int q;
    if (r[n]>=0) {
        return r[n];
    }
    if (n==0) {
        q=0;
    }
    else{
        q=-99999999;
        for (int i=0; i<n ; i++) {
            q=max(q, p[i]+ MemoizedCutRodAux(p,n-i-1,r));
        }
    }
    return q;
}

int MemoizedCutRod(int p[], int n){
    int *r = new int[n];
    for (int i=0 ; i<=n; i++) {
        r[i]=-99999999;
    }
    return MemoizedCutRodAux(p, n, r);
}

int BottomUpCutRod(int p[], int n){
    int *r = new int[n];
    r[0]=0;
    int q=-99999999;
    for (int j=1; j<=n; j++) {
        q=-99999999;
        for (int i=0; i<j; i++) {
            q=max(q, p[i]+r[j-i-1]);
        }
        r[j]=q;
    }
    return r[n];
}


void PrintCutRodSolution(int *s, int n, int max_value) {
    while (n > 0) {
        cout<<s[n]<<" ";
        n = n - s[n];
    }
}

void ExtendedBottomUpCutRod(int p[],int n){
    int *r = new int[n+1];
    int *s = new int[n+1];
    r[0]=0;
    for (int j=1; j<=n; j++) {
        int q=-99999999;
        for (int i=1; i<=j; i++) {
            if (q<p[i]+r[j-i]) {
                q=p[i]+r[j-i];
                s[j]=i;
            }
        }
        r[j]=q;
    }
    PrintCutRodSolution(s, n, r[n]);
}


int main(int argc, const char * argv[]) {
//    int arr[] = {1, 5, 8, 9, 10, 17, 17, 20};
    int arr[] = {0, 1, 5, 8, 9, 10, 17, 17, 20, 24, 30};
    int size = sizeof(arr)/sizeof(arr[0]);
    cout<<CutRod(arr,size)<<endl;
    cout<<MemoizedCutRod(arr, size)<<endl;
    cout<<BottomUpCutRod(arr, size)<<endl;
    ExtendedBottomUpCutRod(arr, size);
    return 0;
}
