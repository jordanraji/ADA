#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <vector>

using namespace std;

vector<int> insertsort(vector<int> &A){
    int i,key;
    for(int j=1; j<A.size(); j++){
        key = A[j];
        i= j-1;
        while (i>-1 && A[i]>key){
            A[i+1]=A[i];
            i = i-1;
        }
        A[i+1]=key;
    }
    return A;
}

vector<int> merge(vector<int> &A , int p , int q , int r){
    int n1=q-p+1;
    int n2=r-q;
    vector<int> L,R;
    for(int i=1;i<=n1;i++){
        L.push_back(A[p+i-1]);
    }
    for (int j=1; j<=n2; j++) {
        R.push_back(A[q+j]);
    }
    L.push_back(1000000000);
    R.push_back(1000000000);
    int i=0,j=0;
    for (int k=p; k<=r; k++) {
        if (L[i]<=R[j]) {
            A[k]=L[i];
            i++;
        } else {
            A[k]=R[j];
            j++;
        }
    }
    return A;
}

void mergeSort(vector<int> &A, int p, int r){
    int q;
    if (p<r) {
        q=(p+r)/2;
        mergeSort(A, p, q);
        mergeSort(A, q+1, r);
        merge(A,p,q,r);
    }
}

void mostrar(vector <int> A){
    for(int i=0; i<A.size(); i++){
        cout<<A[i]<<endl;
    }
}

int main(int argc, const char * argv[]) {
    vector<int> lista;
    lista.push_back(31);
    lista.push_back(25);
    lista.push_back(59);
    lista.push_back(3000);
    lista.push_back(10);
    lista.push_back(8);
//    mostrar(lista);
//    insertsort(lista);
//    cout<<endl<<endl;
//    mostrar(lista);
//    cout<<"Hola, mundo!"<<endl;
    mergeSort(lista, 0, 5);
    mostrar(lista);
    
    return 0;
}
