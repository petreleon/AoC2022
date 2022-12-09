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
        }
    }
    int maximum = 0;
    for (int i = 1; i < lines.size() - 1; i++){
        for (int j = 1; j < lines[0].length() - 1; j++){
            int height = trees[make_pair(i, j)];
            int x1 = 0, x2 = 0, y1 = 0, y2 = 0;
            for (int k = i-1; k >= 0; k--){
                x1 += 1;
                if (trees[make_pair(k, j)] >= height){
                    break;
                }
            }
            for (int k = i+1; k < lines.size(); k++){
                x2 += 1;
                if (trees[make_pair(k, j)] >= height){
                    break;
                }
            }
            for (int k = j-1; k >= 0; k--){
                y1 += 1;
                if (trees[make_pair(i, k)] >= height){
                    break;
                }
            }
            for (int k = j+1; k < lines[0].length(); k++){
                y2 += 1;
                if (trees[make_pair(i, k)] >= height){
                    break;
                }
            }
            // assign product of x1, x2, y1, y2 to a new variable
            int product = x1 * x2 * y1 * y2;
            if (product > maximum){
                maximum = product;
            }
        }
    }
    cout << maximum << endl;
    return EXIT_SUCCESS;
}