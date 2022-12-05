#include <bits/stdc++.h>
using namespace std;
int main(){
    ifstream file("input.txt");
    string temp, moveString, fromString, toString;
    char lineSymbol, commaSymbol;
    int counter = 0, move, from, to;
    vector<deque<char>> symbols(10);
    while (getline(file, temp))
    {
        if (temp == "")
            break;
        for(int i = 0; i < temp.size(); i++){
            if (temp[i] >= 'A' && temp[i] <= 'Z')
                symbols[i/4+1].push_back(temp[i]);
        }
    }
    while(getline(file, temp)){
        stringstream lineStream(temp);
        lineStream >> moveString >> move >> fromString >> from >> toString >> to;
        if (move == 1){
            char temp = symbols[from].front();
            symbols[from].pop_front();
            symbols[to].push_front(temp);
        }
        else {
            deque<char> temp;
            for (;move--;){
                temp.push_front(symbols[from].front());
                symbols[from].pop_front();
            }
            while (!temp.empty()){
                symbols[to].push_front(temp.front());
                temp.pop_front();
            }
        }
    }
    for (int i = 1; i < symbols.size(); i++){
        cout << symbols[i].front();
    }
    cout << endl;
    return EXIT_SUCCESS;
    
}