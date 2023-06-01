#ifndef GRAPHUTILS_H
#define GRAPHUTILS_H

#include "Graph.h"

class GraphUtils
{
public:
    static Graph<string> graphFromString(string graphString);
    static Graph<string> graphFromFile(string filepath);
    static string graphToString(Graph<string> graph);
    static void graphToFile(Graph<string> graph, string filepath);
};


#endif //GRAPHUTILS_H