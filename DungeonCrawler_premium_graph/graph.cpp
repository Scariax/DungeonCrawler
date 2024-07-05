#include "graph.h"


Graph::Graph()
{

}

void Graph::addNode(int row, int col)
{
    if (!hasNode(row, col)) {
        m_nodes.push_back({std::make_pair(row, col)});
    }
}

void Graph::addEdge(int from_r, int from_c, int to_r, int to_c)
{
    if (isConnected(from_r, from_c, to_r, to_c)) {
        return;
    }

    auto fromPointer = getNodePointer(std::make_pair(from_r,from_c));
    if (fromPointer == nullptr) {
        return;
    }

    auto toPointer = getNodePointer(std::make_pair(to_r, to_c));
    if (toPointer == nullptr) {
        return;
    }
    Edge newEdge;
    newEdge.from = fromPointer;
    newEdge.to = toPointer;
    newEdge.weight = 1;
    m_edges.push_back(newEdge);
}

void Graph::clearEdges()
{
    m_edges.clear();
}

bool Graph::hasNode(int row, int col)
{
    for (const auto &node : m_nodes) {
        if (node.Position.first == row && node.Position.second == col) {
            return true;
        }
    }
    return false;
}

bool Graph::isConnected(int from_r, int from_c, int to_r, int to_c)
{
    auto fromPointer = getNodePointer(std::make_pair(from_r,from_c));
    if (fromPointer == nullptr) {
        return false;
    }

    auto toPointer = getNodePointer(std::make_pair(to_r, to_c));
    if (toPointer == nullptr) {
        return false;
    }
    for (const auto &edge : m_edges) {
        if (edge.from == fromPointer && edge.to == toPointer) {
            return true;
        }
    }
    return false;

}

double Graph::getDist(Node *from, Node *to) {
    for (const auto &edge : m_edges) {
        if (edge.from == from && edge.to == to) {
            return edge.weight;
        }
    }
    return 0;
}


std::vector<Node> Graph::breadthFirstSearch(std::pair<int, int> from)
{
    Node* start =getNodePointer(from);
    for (auto &node : m_nodes) {
        node.color = 0;
        node.distance = std::numeric_limits<int>::max();
        node.parent = nullptr;
    }
    start->color = 1;
    start->distance = 0;
    start->parent = nullptr;

    std::queue<Node *> q;
    q.push(start);
    while (!q.empty()) {
        auto *u = q.front();
        q.pop();
        auto nearMe = getConnectedNodes(u);
        for (auto &v : nearMe) {
            if (v->color == 0) {
                v->color = 1;
                v->distance = u->distance + getDist(u, v);
                v->parent = u;
                q.push(v);
            }
        }
        u->color = 2;
    }
    /*for (auto &node : m_nodes) {
        std::cout << node.Position.first << "/"<< node.Position.second << " -> " << node.distance << std::endl;
    }
    std::cout << "-----------------------------------------------------------" << std::endl;*/
    return nodes();
}

std::vector<Node> Graph::nodes() const
{
    return m_nodes;
}

Node *Graph::getNodePointer(std::pair<int,int> pos) {
    for (auto &node : m_nodes) {
        if (node.Position.first == pos.first && node.Position.second == pos.second) {
            return &node;
        }
    }
    return nullptr;
}

std::vector<Node *> Graph::getConnectedNodes(Node *node)
{
    std::vector<Node*> tmp;
    for (auto &n : m_nodes) {
        if (isConnected(node->Position.first, node->Position.second , n.Position.first, n.Position.second)) {
            tmp.push_back(&n);
        }
    }
    return tmp;
}

