#include <bits/stdc++.h>
using namespace std;

map<pair<int, int>, bool> pixels;

bool checkPixel(int currentX, int currentCycle){
    int currentLateral = (currentCycle - 1) % 40;
    if (currentLateral >= currentX - 1 && currentLateral <= currentX + 1){
        return true;
    }
    return false;
}

void drawPixel(int currentX, int currentCycle){
    int currentLateral = (currentCycle - 1) % 40;
    int currentVertical = (currentCycle - 1) / 40;
    pixels[make_pair(currentVertical, currentLateral)] = checkPixel(currentX, currentCycle);
}

void drawPixelAndContinue(int currentX, int* currentCycle){
    drawPixel(currentX, *currentCycle);
    *currentCycle += 1;
}

void printPixels(){
    for(int i = 0; i < 6; i += 1){
        for(int j = 0; j < 40; j += 1){
            if (pixels[make_pair(i, j)]){
                cout << "#";
            }
            else {
                cout << ".";
            }
        }
        cout << endl;
    }
}


int main(){
    ifstream file("input.txt");
    string temp;
    int x = 1;
    int cycle = 1;
    int lateral = (cycle - 1) % 40;
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
            drawPixelAndContinue(x, &cycle);
            drawPixelAndContinue(x, &cycle);
            ss >> num;
            x += num;
        }
        else {
            drawPixelAndContinue(x, &cycle);
        }
        if (cycle > 240) break;
    }
    printPixels();
    return EXIT_SUCCESS;
}