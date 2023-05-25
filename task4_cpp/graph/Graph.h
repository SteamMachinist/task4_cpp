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
    vector<T> vertices;
    map<T, set<T>> adjacency;

    void addOneEdge(T i, T j);
    void removeOneEdge(T i, T j);
    void findNextNewVertex(T current, map<T, set<T>> spanningMap);

public:
    Graph(list<T> vertices, map<T, set<T>> adjacency);
    Graph(list<T> vertices, list<list<T>> adjacencyList);
    Graph(list<T> vertices);
    ~Graph();

    void addEdge(T i, T j);
    void removeEdge(T i, T j);

    Graph<T> getSpanningTree();
};

template<typename T>
Graph<T>::Graph(list<T> vertices, map<T, set<T>> adjacency) : verticesNumber(adjacency.size()), vertices(vertices),
    adjacency(adjacency)
{}

template<typename T>
Graph<T>::Graph(list<T> vertices, list<list<T>> adjacencyList) : verticesNumber(vertices.size()), vertices(vertices)
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
Graph<T>::Graph(list<T> vertices) : verticesNumber(vertices.size()), vertices(vertices)
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
    //delete vertices;
    //delete adjacency;
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

    map<T, set<T>> spanningMap = *new map<T, set<T>>();
    T current = vertices[0];
    for (int i = 1; i < verticesNumber; i++)
    {
        if (spanningMap.contains(current))
        {
            current = vertices[i];
            continue;
        }
        set<T> adjacent = adjacency[current];
        if (adjacent.empty())
        {
            current = vertices[i];
            continue;
        }
        else
        {
            for (T vertex: adjacent)
            {
                if (!spanningMap.contains(vertex))
                {
                    spanningMap[current] = new set{vertex};
                    spanningMap[vertex] = new set{current};
                    current = vertex;
                    continue;
                }
            }
            current = vertices[i];
        }
    }

    return new Graph<T>(vertices, spanningMap);
}

template<typename T>
void Graph<T>::findNextNewVertex(T current, map<T, set<T>> spanningMap)
{

}

#endif //GRAPH_H