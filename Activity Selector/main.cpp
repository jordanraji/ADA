#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string>
#include <vector>

using namespace std;

vector<int> a;

void RecursiveActivitySelector(vector<int> s, vector<int> f, int k){
    int m;
    m=k+1;
    while (m<=s.size() and s[m]<f[k]) {
        m++;
    }
    if (m <= s.size()) {
        a.push_back(m);
        RecursiveActivitySelector(s,f,m);
    }
}

vector<int> GreedyActivitySelector(vector<int> s, vector<int>f){
    vector<int> a2;
    int k=1;
    int m;
    a2.push_back(0);
    for (m=2; m<=s.size(); m++) {
        if (s[m]>=f[k]) {
            a2.push_back(m);
            k=m;
        }
    }
    return a2;
}

int main(int argc, const char * argv[]) {
    vector<int>s={1,3,0,5,3,5,6,8,8,2,12};
    vector<int>f={3,5,6,7,9,9,10,11,12,14,16};
//    vector<int>s = {2,1,4};
//    vector<int>f = {3, 5, 8};
    vector<int>act=GreedyActivitySelector(s,f);

    for(int i=0;i<act.size();i++)
        cout<<act[i]+1<<" ";


    cout<<endl;


    a.push_back(0);
    RecursiveActivitySelector(s, f, 0);
    for(int i=0;i<a.size();i++)
        cout<<a[i]+1<<" ";

    return 0;
}
