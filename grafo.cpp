#include <vector>
#include <iostream>
#include <string>

using namespace std;

class Node;

class Edge
{
public:
    Edge(Node *org, Node *dest, int dist)
    {
        origin = org;
        destination = dest;
        distance = dist;
    }

    Node* getOrigin() {return origin;}
    Node* getDestination() {return destination;}
    int getDistance() {return distance;}
private:
    Node* origin;
    Node* destination;
    int distance;
};

class Node
{
public:
    Node(string id)
    {
        name = id;
    }

    void addEdge(Node *v, int dist)
    {
        Edge newEdge(this, v, dist);
        edges.push_back(newEdge);
    }

    void printEdges()
    {
        cout << name << ":" << endl;
        for (int i = 0; i < edges.size(); i++)
        {
        Edge e = edges[i];
        cout << e.getDestination()->getName() <<
            " - " << e.getDistance() << endl;
        }
        cout << endl;
    }

    string getName() {return name;}
    vector<Edge> getEdges() {return edges;}

private:
    string name;
    vector<Edge> edges;
};


class Graph
{
public:
    Graph() {}

    void insert(Node *v)
    {
        vertices.push_back(v);
    }

    void showGraph()
    {
        for (int i = 0; i < vertices.size(); i++)
            vertices[i]->printEdges();
    }

private:
    vector<Node*> vertices;
};

int main()
{
Graph g;

Node v1 = Node("A");
Node v2 = Node("B");
Node v3 = Node("C");
Node v4 = Node("D");


Node *vp1 = &v1;
Node *vp2 = &v2;
Node *vp3 = &v3;
Node *vp4 = &v4;


v1.addEdge(vp2, 100);
v1.addEdge(vp4, 20);
v2.addEdge(vp1, 100);
v2.addEdge(vp4, 30);
v3.addEdge(vp4, 10);
v3.addEdge(vp3, 20);
v4.addEdge(vp2, 15);


g.insert(vp1);
g.insert(vp2);
g.insert(vp3);
g.insert(vp4);

g.showGraph();

return 0;
}
