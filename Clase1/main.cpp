#include <iostream>
#include <stdio.h>
#include <stdlib.h>
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

void mostrar(vector <int> A){
    for(int i=0; i<A.size(); i++){
        cout<<A[i]<<endl;
    }
}

int main()
{
    vector<int> lista;
    lista.push_back(31);
    lista.push_back(25);
    lista.push_back(59);
    lista.push_back(3000);
    lista.push_back(10);
    lista.push_back(8);
    mostrar(lista);
    insertsort(lista);
    cout<<endl<<endl;
    mostrar(lista);
    cout << "Hello world!" << endl;
    return 0;
}
