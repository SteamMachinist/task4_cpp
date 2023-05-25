#ifndef FILEUTILS_H
#define FILEUTILS_H

#include "../graph/Graph.h"

class FileUtils
{
public:
    Graph<string> graphFromFile(string filename);
};


#endif //FILEUTILS_H