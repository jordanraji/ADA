#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include <math.h>

using namespace std;

int parent(int i){
    return i/2;
}
int left(int i){
    return i*2;
}
int right(int i){
    return i*2+1;
}

class heap {
public:
    int heapsize;
    vector<int> A;
    void max_heapify(int i);
    void buildheap(vector<int> v);
};

void heap::max_heapify(int i)
{
    int l=left(i);
    int r=right(i);
    int largest;
    if ( (l<=heapsize) && (A[l]>A[i])) {
        largest = l;
    }
    else{
        largest = i;
    }
    if ((r<=heapsize) && (A[r]>A[largest])) {
        largest = r;
    }
    if (largest != i) {
        swap(A[i],A[largest]);
        max_heapify(largest);
    }
}

void heap::buildheap(vector<int> v)
{
    A = v;
    A.insert(A.begin(),0);
    heapsize = A.size()-1;
    for (int i=heapsize/2; i>=1; i--) {
        max_heapify(i);
    }
}

vector<int> heapsort(vector<int> vi) {
    heap h;
    h.buildheap(vi);
    vector<int> output;
    while (h.heapsize>0) {
        output.push_back(h.A[1]);
        swap(h.A[1],h.A[h.heapsize]);
        h.heapsize--;
        h.max_heapify(1);
    }
    return output;
}

void show(vector<int>B){
    for (int i=0; i<B.size(); i++) {
        cout << B[i]<< endl;
    }
}

// PRIORITY QUEUE

class priorityqueue {
public:
    heap h;
    void insert(int i);
    int heap_maximum();
    int heap_extract_max();
    void heap_increase_key(int i, int k);
};

void priorityqueue::insert(int i) {
    h.heapsize++;
    h.A.push_back(i);
    int j = h.heapsize;
    int p=parent(j);
    while (p>0 && h.A[p]<h.A[j]) {
        swap(h.A[p],h.A[j]);
        j = p;
    }
}

int priorityqueue::heap_maximum() {
    if (h.heapsize <= 0){
        return -1;
    }
    return h.A[1];
}

int priorityqueue::heap_extract_max() {
    if (h.heapsize < 1){
        return -1;
    }
    int max = h.A[1];
    h.A[1]=h.A[h.heapsize];
    h.heapsize--;
    h.max_heapify(1);
    return max;
}

void priorityqueue::heap_increase_key(int i, int key) {
    h.A[i] = key;
    while (i>1 && h.A[parent(i)]<h.A[i]) {
        swap(h.A[i],h.A[parent(i)]);
        i = parent(i);
    }
}

int main(int argc, const char * argv[]) {
    vector<int>v;
    v.push_back(4);
    v.push_back(3);
    v.push_back(1);
    v.push_back(2);
    v.push_back(6);
    vector<int> out = heapsort(v);
    show(out);
    return 0;
}
