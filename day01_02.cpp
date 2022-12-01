#include <fstream>
#include <string>
#include <sstream>
#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

int main() {
    ifstream inp("input.txt");
    string line;
    int sum = 0;
    vector<int> sums;
    while (getline(inp, line))
    {
        /* code */
        if (line.empty()){
            sums.push_back(sum);
            sum = 0;
        }
        if (!line.empty()){
            int tempNumber;
            istringstream i(line);
            i >> tempNumber;
            sum += tempNumber;
        }
    }
    sums.push_back(sum);
    sort(sums.begin(), sums.end(), greater<int>());
    cout << sums[0] + sums[1] + sums[2] << endl;

    return 0;
}