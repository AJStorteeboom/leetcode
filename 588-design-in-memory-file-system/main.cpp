#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class FileSystem {
    //parent map - underlying maps
    unordered_map<string, unordered_set<string>> parentMapMap;

    //parent map - filename
    unordered_map<string, unordered_set<string>> filesMap;

    //file name - content
    unordered_map<string, string> contentMap;


public:
    FileSystem() {
        parentMapMap.insert({"0_", {}});
    }

    vector<string> ls(string path) {
        string hashedPath = pathToHashedPath(path);
        vector<string> result;

        if (parentMapMap.find(hashedPath) != parentMapMap.end()) {
            result.insert(result.end(), filesMap[hashedPath].begin(), filesMap[hashedPath].end());
            result.insert(result.end(), parentMapMap[hashedPath].begin(), parentMapMap[hashedPath].end());
        } else if (contentMap.find(hashedPath) != contentMap.end()) {
            result.push_back(hashedPath);
        }

        for (int x = 0; x < result.size(); x++) {
            int pos = result[x].size() - 1;
            while (result[x][pos] != '_') pos--;
            result[x] = result[x].substr(pos + 1);
        }

        sort(result.begin(), result.end());

        return result;
    }

    void mkdir(string path) {
        vector<string> splittedPath = split(path, '/');
        string lastMap;

        string parentPath = "0_";
        string hashedPath = "0_";

        for (int x = 0; x < splittedPath.size(); x++) {
            hashedPath.append(splittedPath[x]);

            if (parentMapMap.find(parentPath) != parentMapMap.end()) {
                if (parentMapMap[parentPath].find(hashedPath) == parentMapMap[parentPath].end()) {
                    parentMapMap[parentPath].insert(hashedPath);
                    parentMapMap.insert({hashedPath, {}});
                }

                parentPath = hashedPath;
            }

            if (x < splittedPath.size() - 1) hashedPath.append("_");
        }
    }

    void addContentToFile(string filePath, string content) {
        string hashedPath = pathToHashedPath(filePath);

        int pos = hashedPath.size() - 1;
        while (hashedPath[pos] != '_') pos--;
        string dirName = hashedPath.substr(0, pos);
        if(dirName == "0") dirName = "0_";

        if (contentMap.find(hashedPath) != contentMap.end()) {
            contentMap[hashedPath].append(content);
        } else {
            filesMap[dirName].insert(hashedPath);
            contentMap.insert({hashedPath, content});
        }
    }

    string readContentFromFile(string filePath) {
        string hashedPath = pathToHashedPath(filePath);

        if (contentMap.find(hashedPath) != contentMap.end()) {
            return contentMap[hashedPath];
        } else {
            return "";
        }
    }

    string pathToHashedPath(string path) {
        vector<string> splittedPath = split(path, '/');
        string hashedPath = "0_";

        for (int x = 0; x < splittedPath.size(); x++) {
            hashedPath.append(splittedPath[x]);
            if (x < splittedPath.size() - 1) hashedPath.append("_");
        }

        return hashedPath;
    }

    vector<string> split(string x, char delim = ' ') {
        x += delim; //includes a delimiter at the end so last word is also read
        vector<string> splitted;
        string temp;

        for (int i = 0; i < x.length(); i++) {
            if (x[i] == delim) {
                if (!temp.empty()) splitted.push_back(temp);

                temp = "";
            } else {
                temp += x[i];
            }
        }
        return splitted;
    }
};


//["FileSystem",    "mkdir",      "ls",          "ls",   "mkdir",   "ls",   "ls",      "addContentToFile",          "ls",    "ls",              "ls"]
//[[],              ["/goowmfn"],  ["/goowmfn"],  ["/"],  ["/z"],    ["/"],  ["/"],    ["/goowmfn/c","shetopcy"],   ["/z"],   ["/goowmfn/c"],   ["/goowmfn"]]


int main() {
    FileSystem fileSystem;

    fileSystem.ls("/");
    fileSystem.ls("/");
    fileSystem.ls("/");
    fileSystem.ls("/");
    fileSystem.ls("/");
    fileSystem.addContentToFile("/bne", "kvo");
    fileSystem.readContentFromFile("/bne");
    fileSystem.readContentFromFile("/bne");
    for(string value :fileSystem.ls("/")) cout << value << endl;

    return 0;
}
