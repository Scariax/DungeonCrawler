#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <limits>
#include <queue>
#include <vector>
#include <string>

struct Node{
    std::pair<int,int> Position;
    int color = 0;
    int distance = std::numeric_limits<int>::max();
    Node *parent = nullptr;
};

struct Edge{
    Node* from;
    Node* to;
    double weight =1;
};

class Graph{
private:
    std::vector<Node> m_nodes;
    std::vector<Edge> m_edges;

    Node* getNodePointer(std::pair<int,int> pos);
    std::vector<Node*> getConnectedNodes(Node *node);
    double getDist(Node *from, Node *to);
public:
    Graph();
    ~Graph()=default;

    void addNode(int row, int col);
    void addEdge(int from_r, int from_c, int to_r, int to_c);
    void clearEdges();
    bool hasNode(int row, int col);
    bool isConnected(int from_r, int from_c, int to_r, int to_c);

    std::vector<Node> breadthFirstSearch(std::pair<int,int> from);
    std::vector<Node> nodes() const;
};
#endif // GRAPH_H
