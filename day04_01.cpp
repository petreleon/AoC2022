#include <bits/stdc++.h>
using namespace std;
int main(){
    ifstream file("input.txt");
    string temp;
    char lineSymbol, commaSymbol;
    int counter = 0;
    while (file >> temp)
    {
        stringstream lineStream(temp);
        int firstStart, firstEnd, secondStart, secondEnd;
        lineStream >> firstStart >> lineSymbol >> firstEnd >> commaSymbol >> secondStart >> lineSymbol >> secondEnd;
        if (firstStart >= secondStart && firstEnd <= secondEnd || secondStart >= firstStart && secondEnd <= firstEnd)
            counter++;
    }
    cout << counter << endl;
    return EXIT_SUCCESS;
    
}