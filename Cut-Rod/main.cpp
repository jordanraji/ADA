#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include <math.h>
#include <ctime>

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
    int arr[] = {0, 1, 5, 8, 9, 10, 17, 17, 20, 24, 30};
    int size = sizeof(arr)/sizeof(arr[0]);
    int start_s=clock();
    cout<<CutRod(arr,size)<<endl;
    int stop_s=clock();
    cout << "time: " << (stop_s-start_s)/double(CLOCKS_PER_SEC)*1000 << endl;
    start_s=clock();
    cout<<MemoizedCutRod(arr, size)<<endl;
    stop_s=clock();
    cout << "time: " << (stop_s-start_s)/double(CLOCKS_PER_SEC)*1000 << endl;
    start_s=clock();
    cout<<BottomUpCutRod(arr, size)<<endl;
    stop_s=clock();
    cout << "time: " << (stop_s-start_s)/double(CLOCKS_PER_SEC)*1000 << endl;
    start_s=clock();
    ExtendedBottomUpCutRod(arr, size);
    stop_s=clock();
    cout << "time: " << (stop_s-start_s)/double(CLOCKS_PER_SEC)*1000 << endl;
    return 0;
}

// OUTPUT
// 30
// time: 0.114
// 30
// time: 0.034
// 30
// time: 0.005
// 1 10 time: 0.003
