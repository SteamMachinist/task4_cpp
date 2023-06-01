#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <list>
#include <algorithm>
#include <set>
#include <map>

using namespace std;

template<typename T>
class Graph
{
private:
    int verticesNumber;
    map<T, set<T>> adjacency;

    void addOneEdge(T i, T j);
    void removeOneEdge(T i, T j);

    void addSpanningFor(T current, map<T, set<T>> &spanning);

    friend class GraphUtils;
    friend class GraphWindow;

public:
    Graph(map<T, set<T>> adjacency);
    Graph(list<T> vertices, list<list<T>> adjacencyList);
    Graph(list<T> vertices);
    ~Graph();

    int size();

    void addVertex(T v);
    void removeVertex(T v);

    void addEdge(T i, T j);
    void removeEdge(T i, T j);

    Graph<T> getSpanningTree();
};

template<typename T>
Graph<T>::Graph(map<T, set<T>> adjacency) : verticesNumber(adjacency.size()), adjacency(adjacency)
{}

template<typename T>
Graph<T>::Graph(list<T> vertices, list<list<T>> adjacencyList) : verticesNumber(vertices.size())
{
    adjacency = *new map<T, set<T>>;
    for (int i = 0; i < verticesNumber; i++)
    {
        for (T v: adjacencyList[i])
        {
            adjacency[vertices[i]] = v;
        }
    }
}

template<typename T>
Graph<T>::Graph(list<T> vertices) : verticesNumber(vertices.size())
{
    adjacency = *new map<T, set<T>>;
    for (T v: vertices)
    {
        adjacency[v] = *new set<T>;
    }
}

template<typename T>
Graph<T>::~Graph()
{
    //delete adjacency;
}

template<typename T>
int Graph<T>::size()
{
    return verticesNumber;
}

template<typename T>
void Graph<T>::addVertex(T v)
{
    adjacency[v] = new set<T>;
    verticesNumber++;
}

template<typename T>
void Graph<T>::removeVertex(T v)
{
    adjacency.erase(v);
    for (auto const& [key, val] : adjacency)
    {
        val.erase(v);
    }
    verticesNumber--;
}

template<typename T>
void Graph<T>::addEdge(T i, T j)
{
    addOneEdge(i, j);
    addOneEdge(j, i);
}

template<typename T>
void Graph<T>::addOneEdge(T i, T j)
{
    set<T> adjacent;
    try
    {
        adjacent = adjacency.at(i);
    }
    catch (const out_of_range &e)
    {
        return;
    }
    adjacent.insert(j);
}

template<typename T>
void Graph<T>::removeEdge(T i, T j)
{
    removeOneEdge(i, j);
    removeOneEdge(j, i);
}

template<typename T>
void Graph<T>::removeOneEdge(T i, T j)
{
    set<T> adjacent;
    try
    {
        adjacent = adjacency.at(i);
    }
    catch (const out_of_range &e)
    {
        return;
    }
    adjacent.erase(j);
}

template<typename T>
Graph<T> Graph<T>::getSpanningTree()
{
    if (verticesNumber == 0)
    {
        return *new Graph<T>(*new list<T>());
    }
    map<T, set<T>> spanning = *new map<T, set<T>>();
    T root = adjacency.begin()->first;
    addSpanningFor(root, spanning);
    return *new Graph<T>(spanning);
}

template<typename T>
void Graph<T>::addSpanningFor(T current, map<T, set<T>> &spanning)
{
    set<T> adjacent = adjacency[current];
    for (T vertex: adjacent)
    {
        if (!spanning.contains(vertex))
        {
            spanning[vertex] = *new set<T>{current};
            if (spanning.contains(current))
            {
                spanning[current].insert(vertex);
            }
            else
            {
                spanning[current] = *new set<T>{vertex};
            }
            addSpanningFor(vertex, spanning);
        }
    }
}
#endif //GRAPH_H