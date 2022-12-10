#include <bits/stdc++.h>
using namespace std;
template <typename T,typename U>                                                   
std::pair<T,U> operator+(const std::pair<T,U> & l,const std::pair<T,U> & r) {   
    return {l.first+r.first,l.second+r.second};                                    
}                                                                                  

int main(){
    ifstream file("input.txt");
    string temp;
    map<pair<int, int>, bool> visitedByTail;
    pair<int, int> head = {0, 0};
    pair<int, int> tail = {0, 0};
    while (getline(file, temp))
    {
        stringstream ss(temp);
        string direction;
        int distance;
        ss >> direction >> distance;
        pair<int, int> directionVector;
        if (direction == "U"){
            directionVector = {1, 0};
        }
        else if (direction == "D"){
            directionVector = {-1, 0};
        }
        else if (direction == "R"){
            directionVector = {0, 1};
        }
        else if (direction == "L"){
            directionVector = {0, -1};
        }
        for (int i = 0; i < distance; i += 1){
            pair<int, int> prevHead = head;
            head = head + directionVector;
            if (abs(head.first - tail.first) > 1 || abs(head.second - tail.second) > 1){
                tail = prevHead;
            }
            visitedByTail[tail] = true;
        }
    }
    int countVisited = 0;
    for (auto &visited : visitedByTail){
        if (visited.second){
            countVisited += 1;
        }
    }
    cout << countVisited << endl;
    return EXIT_SUCCESS;
}
