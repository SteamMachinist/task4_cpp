#include <fstream>
#include <sstream>
#include "FileUtils.h"
Graph<string> FileUtils::graphFromFile(string filename)
{
    string line;
    ifstream file("../resources/" + filename);
    map<string, set<string>> graph = *new map<string, set<string>>();
    list<string> vertices = *new list<string>();
    if (file.is_open())
    {
        getline(file, line);
        int n = stoi(line);
        while (getline(file, line))
        {
            string vertex = line.substr(0, line.find(':'));
            vertices.push_back(vertex);
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

    return *new Graph<string>(vertices, graph);
}
