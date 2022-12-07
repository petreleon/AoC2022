#include <bits/stdc++.h>
using namespace std;
int main(){
    ifstream file("input.txt");
    string temp;
    while (getline(file, temp))
    {
        for(int i = 14; i <= temp.size(); i += 1){
            map<char, bool> symbols;
            bool isUnique = true;
            for(int j = i-14; j < i; j += 1){
                if (symbols[temp[j]]){
                    isUnique = false;
                    break;
                }
                symbols[temp[j]] = true;
            }
            if (isUnique){
                cout << i << endl;
                break;
            }
        }
    }
    
    return EXIT_SUCCESS;
}
