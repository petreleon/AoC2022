#include <bits/stdc++.h>
using namespace std;
map<char, int> symbols;
map<pair<int, int>, char> locations;
map<pair<int, int>, int> distances;

int main(){
    for (int i = 1; i < 27; i += 1){
        symbols['a' + i - 1] = i + 1;
    }
    symbols['E'] = 28;
    symbols['S'] = 1;
    ifstream file("input.txt");
    string temp;
    int iterations = 0;
    vector<pair<int, int>> queue;
    while (getline(file, temp))
    {
        for(int iterations_2 = 0; iterations_2 < temp.size(); iterations_2 += 1){
            locations[make_pair(iterations, iterations_2)] = temp[iterations_2];
            distances[make_pair(iterations, iterations_2)] = INT_MAX;
            if (temp[iterations_2] == 'S'){
                queue.push_back({iterations, iterations_2});
            }
        }
        iterations += 1;
    }
    vector<pair<int, int>> new_queue;
    int step = 0;
    while (queue.size())
    {
        for (pair<int, int> point: queue){
            if (distances[point] > step){
                distances[point] = step;
                if (locations[point] == 'E'){
                    cout << step << endl;
                    if (step >= 464){
                        cout << "Too high!" << endl;
                    }
                    return EXIT_SUCCESS;
                }
                vector<pair<int, int>> temp_queue;
                temp_queue.push_back({point.first + 1, point.second});
                temp_queue.push_back({point.first - 1, point.second});
                temp_queue.push_back({point.first, point.second + 1});
                temp_queue.push_back({point.first, point.second - 1});
                for (pair<int, int> new_point: temp_queue){
                    if (symbols[locations[new_point]] <= symbols[locations[point]] + 1 && find(queue.begin(), queue.end(), new_point) == queue.end() && find(new_queue.begin(), new_queue.end(), new_point) == new_queue.end()){
                        new_queue.push_back(new_point);
                    }
                }
            }
        }
        queue = new_queue;
        new_queue.clear();
        step += 1;
    }
    ofstream file2("output.txt");
    return EXIT_SUCCESS;
}