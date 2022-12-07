#include <bits/stdc++.h>
using namespace std;
struct File
{
    File(long long int size)
    {
        this->size = size;
    }
    File (){
        this->size = 0;
    }
    long long int size;
};

map<string, long long int> sizes;

struct Folder
{
    const Folder *parent;
    Folder(Folder *parent) : parent(parent)
    {
    }
    Folder() : parent(this)
    {
    }
    Folder (const Folder *&parent) : parent(parent)
    {
    }
    
    map<string, Folder> folders;
    map<string, File> files;
    Folder &operator=(const Folder &other)
    {
        parent = other.parent;
        folders = other.folders;
        files = other.files;
        return *this;
    }
};

long long int getFolderSize(Folder &folder, string path = "/"){
    long long int size = 0;
    for (auto &file : folder.files){
        size += file.second.size;
    }
    for (auto &folder : folder.folders){
        size += getFolderSize(folder.second, path + folder.first + "/");
    }
    sizes[path] = size;
    return size;
}

int main(){
    ifstream file("input.txt");
    
    
    Folder root;
    string temp;
    Folder *currentFolder = &root;
    while (getline(file, temp))
    {
        stringstream lineStream(temp);
        string command_or_folder_or_file;
        lineStream >> command_or_folder_or_file;
        if (command_or_folder_or_file == "$"){
            lineStream >> command_or_folder_or_file;
            if (command_or_folder_or_file == "cd"){
                lineStream >> command_or_folder_or_file;
                if (command_or_folder_or_file == ".."){
                    currentFolder = currentFolder->parent;
                }
                else if (command_or_folder_or_file == "/"){
                    currentFolder = &root;
                }
                else{
                    lineStream >> command_or_folder_or_file;
                    currentFolder = &(currentFolder->folders[command_or_folder_or_file]);
                }
            }
        }
        else if (command_or_folder_or_file == "dir"){
            lineStream >> command_or_folder_or_file;
            if (currentFolder->folders.find(command_or_folder_or_file) == currentFolder->folders.end()){
                currentFolder->folders[command_or_folder_or_file] = Folder (currentFolder);
            }
        }
        else {
            long long int size = stoi(command_or_folder_or_file);
            lineStream >> command_or_folder_or_file;
            if (currentFolder->files.find(command_or_folder_or_file) == currentFolder->files.end()){
                currentFolder->files[command_or_folder_or_file] = File(size);
            }
        }
    }

    long long int space = getFolderSize(root);
    long long int freeSpace = 70000000 - space;
    long long int neededSpace = 30000000 - freeSpace;
    long long int minSize = 1000000000;
    for (auto &size : sizes){
        if (size.second >= neededSpace && size.second < minSize){
            minSize = size.second;
        }
    }
    cout << minSize << endl;
    return EXIT_SUCCESS;
}