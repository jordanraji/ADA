//
//  main.cpp
//  ADA
//
//  Created by Jordán Raji Lazo Cahua on 1/6/16.
//  Copyright © 2016 Jordán Raji Lazo Cahua. All rights reserved.
//

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string>
#include <vector>
#include <list>

using namespace std;

class Graph{
    int V;
    list<int> *adj;
    void DFSUtil(int v, bool visited[]);
public:
    Graph(int V);
    void addEdge(int v, int w);
    void BFS(int s);
    void DFS(int v);
};

Graph::Graph(int V){
    this->V = V;
    adj = new list<int>[V];
}

void Graph::addEdge(int v, int w){
    adj[v].push_back(w);
}

enum {
    WHITE,
    GRAY
};

void Graph::BFS(int s){
    bool *visited = new bool[V];
    for(int i = 0; i < V; i++)
        visited[i] = WHITE;
    list<int> queue;
    visited[s] = GRAY;
    queue.push_back(s);
    list<int>::iterator i;
    while(!queue.empty()){
        s = queue.front();
        cout << s << " ";
        queue.pop_front();
        for(i = adj[s].begin(); i != adj[s].end(); i++){
            if(!visited[*i]){
                visited[*i] = GRAY;
                queue.push_back(*i);
            }
        }
    }
}

void Graph::DFSUtil(int v, bool visited[]){
    visited[v] = GRAY;
    cout << v << " ";
    list<int>::iterator i;
    for (i = adj[v].begin(); i != adj[v].end(); ++i)
        if (!visited[*i])
            DFSUtil(*i, visited);
}

void Graph::DFS(int v){
    bool *visited = new bool[V];
    for (int i = 0; i < V; i++)
        visited[i] = WHITE;
    DFSUtil(v, visited);
}

int main(int argc, const char * argv[]) {
    Graph g(6);
    g.addEdge(0, 1);
    g.addEdge(0, 3);
    g.addEdge(3, 1);
    g.addEdge(1, 4);
    g.addEdge(4, 3);
    g.addEdge(2, 4);
    g.addEdge(2, 5);
    g.addEdge(5, 5);
    cout<<"Ingrese el nodo a empezar(BFS): "<<endl;
    int num;
    cin>>num;
    cout << "Inicia en "<<num<<endl;
    g.BFS(num);
    cout<<endl<<"Ingrese el nodo a empezar(DFS): "<<endl;
    cin>>num;
    cout << "Inicia en "<<num<<endl;
    g.DFS(num);
    return 0;
}