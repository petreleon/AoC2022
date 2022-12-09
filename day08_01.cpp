#include <bits/stdc++.h>
using namespace std;
vector<string> lines;
map<pair<int, int>, int> trees;
map<pair<int, int>, bool> visible_trees;
int main(){
    ifstream file("input.txt");
    string temp;
    while (getline(file, temp))
    {
        lines.push_back(temp);
    }
    for (int i = 0; i < lines.size(); i++){
        for (int j = 0; j < lines[0].length(); j++){
            trees[make_pair(i, j)] = lines[i][j] - '0';
            visible_trees[make_pair(i, j)] = false;
        }
    }
    for (int i = 0; i < lines.size(); i++)
    {
        int maximum = -1;
        for (int j = 0; j < lines[0].length(); j++){
            if (trees[make_pair(i, j)] > maximum){
                maximum = trees[make_pair(i, j)];
                visible_trees[make_pair(i, j)] = true;
            }
        }
        maximum = -1;
        for (int j = lines[0].length()-1; j >= 0; j--){
            if (trees[make_pair(i, j)] > maximum){
                maximum = trees[make_pair(i, j)];
                visible_trees[make_pair(i, j)] = true;
            }
        }
    }
    for (int i = 0; i < lines[0].length(); i++)
    {
        int maximum = -1;
        for (int j = 0; j < lines.size(); j++){
            if (trees[make_pair(j, i)] > maximum){
                maximum = trees[make_pair(j, i)];
                visible_trees[make_pair(j, i)] = true;
            }
        }
        maximum = -1;
        for (int j = lines.size()-1; j >= 0; j--){
            if (trees[make_pair(j, i)] > maximum){
                maximum = trees[make_pair(j, i)];
                visible_trees[make_pair(j, i)] = true;
            }
        }
    }
    int count = 0;
    for (auto i = visible_trees.begin(); i != visible_trees.end(); i++){
        if (i->second){
            count += 1;
        }
    }
    cout << count << endl;
    return EXIT_SUCCESS;
    
}