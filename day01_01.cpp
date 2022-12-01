#include <fstream>
#include <string>
#include <sstream>
#include <iostream>
using namespace std;



int main() {
    ifstream inp("input.txt");
    string line;
    int sum = 0;
    int maxSum = 0;
    while (getline(inp, line))
    {
        /* code */
        if (line.empty()){
            if (sum > maxSum){
                maxSum = sum;
            }
            sum = 0;
        }
        if (!line.empty()){
            int tempNumber;
            istringstream i(line);
            i >> tempNumber;
            sum += tempNumber;
        }
    }
    if (sum > maxSum){
        maxSum = sum;
    }
    cout << maxSum << endl;

    return 0;
}