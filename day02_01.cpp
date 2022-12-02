#include <bits/stdc++.h>
using namespace std;
enum RPS{
    ROCK = 1,
    PAPER,
    SCISSORS
} rps;


int main(){
    ifstream inp("input.txt");
    string line;
    map<pair<RPS, RPS>, int> gamePoints = {
        {{ROCK, ROCK}, 3},
        {{PAPER, PAPER}, 3},
        {{SCISSORS, SCISSORS}, 3},
        {{ROCK, SCISSORS}, 6},
        {{SCISSORS, PAPER}, 6},
        {{PAPER, ROCK}, 6}
    };
    map<char, RPS> opponentPlayDict = {
        {'A', ROCK},
        {'B', PAPER},
        {'C', SCISSORS}
    },
    myPlayDict = {
        {'X', ROCK},
        {'Y', PAPER},
        {'Z', SCISSORS}
    };
    int totalPoints = 0;
    while (getline(inp, line))
    {
        stringstream lineStream(line);
        char myPlayChar, opponentPlayChar;
        lineStream >> opponentPlayChar >> myPlayChar;
        RPS myPlay = myPlayDict[myPlayChar];
        RPS opponentPlay = opponentPlayDict[opponentPlayChar];
        totalPoints += myPlay + gamePoints[{myPlay, opponentPlay}];
    }

    cout << totalPoints << endl;
    return 0;
}

