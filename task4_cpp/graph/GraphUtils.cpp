#include <fstream>
#include <sstream>
#include "GraphUtils.h"

Graph<string> GraphUtils::graphFromString(string graphString)
{
    string line;
    ifstream str(graphString);
    map<string, set<string>> graph = *new map<string, set<string>>();
    getline(str, line);
    int n = stoi(line);
    while (getline(str, line))
    {
        string vertex = line.substr(0, line.find(':'));
        line = line.erase(0, line.find(':') + 1);

        set<string> adjacent = *new set<string>;
        stringstream stream (line);
        std::string segment;
        while(getline(stream, segment, ' '))
        {
            if (!segment.empty()) adjacent.insert(segment);
        }

        graph[vertex] = adjacent;
    }

    return *new Graph<string>(graph);
}

Graph<string> GraphUtils::graphFromFile(string filepath)
{
    string line;
    ifstream file(filepath);
    map<string, set<string>> graph = *new map<string, set<string>>();
    if (file.is_open())
    {
        getline(file, line);
        int n = stoi(line);
        while (getline(file, line))
        {
            string vertex = line.substr(0, line.find(':'));
            line = line.erase(0, line.find(':') + 1);

            set<string> adjacent = *new set<string>;
            stringstream stream (line);
            std::string segment;
            while(getline(stream, segment, ' '))
            {
                if (!segment.empty()) adjacent.insert(segment);
            }

            graph[vertex] = adjacent;
        }
        file.close();
    }
    else cout << "Unable to open file";

    return *new Graph<string>(graph);
}

void GraphUtils::graphToFile(Graph<string> graph, string filepath)
{
    std::ofstream out(filepath);
    out << graphToString(graph);
    out.close();
}

string GraphUtils::graphToString(Graph<string> graph)
{
    string graphString;
    graphString += to_string(graph.size()) + "\n";
    for (auto const& [key, val] : graph.adjacency)
    {
        graphString += key + ":";
        for (string v : val)
        {
            graphString += " " + v;
        }
        graphString += "\n";
    }
    return graphString;
}
