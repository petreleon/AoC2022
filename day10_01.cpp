#include <bits/stdc++.h>
using namespace std;

int main(){
    ifstream file("input.txt");
    string temp;
    int x = 1;
    int cycle = 1;
    int sumOfSignalStrengths = 0;
    vector<string> lines;
    while (getline(file, temp))
    {
        lines.push_back(temp);
    }
    int lineIndex = 0;
    while(1){
        stringstream ss(lines[(lineIndex) % lines.size()]);
        lineIndex += 1;
        string command;
        ss >> command;
        int num = 0;
        if (command == "addx"){
            ss >> num;
            if ((cycle + 20) % 40 == 0){
                sumOfSignalStrengths += cycle * x;
            }
            cycle += 1;
        }
        if ((cycle + 20) % 40 == 0){
            sumOfSignalStrengths += cycle * x;
        }
        x += num;
        if (cycle > 220) break;
        cycle += 1;
    }
    cout << sumOfSignalStrengths << endl;
    return EXIT_SUCCESS;
    
}