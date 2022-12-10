#include <bits/stdc++.h>
using namespace std;
template <typename T,typename U>                                                   
std::pair<T,U> operator+(const std::pair<T,U> & l,const std::pair<T,U> & r) {   
    return {l.first+r.first,l.second+r.second};                                    
}
template <typename T,typename U>
std::pair<T,U> operator-(const std::pair<T,U> & l,const std::pair<T,U> & r) {   
    return {l.first-r.first,l.second-r.second};                                    
}
template <typename T,typename U>
std::pair<T,U> operator*(const std::pair<T,U> & l,const std::pair<T,U> & r) {   
    return {l.first*r.first,l.second*r.second};                                    
}
template <typename T,typename U>
std::pair<T,U> operator/(const std::pair<T,U> & l,const std::pair<T,U> & r) {   
    return {l.first/r.first,l.second/r.second};                                    
}                                                                                  

int main(){
    ifstream file("input.txt");
    string temp;
    map<pair<int, int>, bool> visitedByTail;
    vector< pair<int, int>> vectorOfPositions(10, {0, 0});
    vector< pair<int, int>> vectorOfPreviousPositions(10, {0, 0});
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
            vectorOfPositions[0] = vectorOfPositions[0] + directionVector;
            for (int j = 1; j < 10; j += 1){
                if (abs(vectorOfPositions[j-1].first - vectorOfPositions[j].first) > 1 || abs(vectorOfPositions[j-1].second - vectorOfPositions[j].second) > 1){
                    if (vectorOfPositions[j-1].first == vectorOfPositions[j].first){
                        if (vectorOfPositions[j-1].second > vectorOfPositions[j].second){
                            vectorOfPositions[j] = vectorOfPositions[j] + pair<int, int>{0, 1};
                        }
                        else{
                            vectorOfPositions[j] = vectorOfPositions[j] + pair<int, int>{0, -1};
                        }
                    }
                    else if (vectorOfPositions[j-1].second == vectorOfPositions[j].second){
                        if (vectorOfPositions[j-1].first > vectorOfPositions[j].first){
                            vectorOfPositions[j] = vectorOfPositions[j] + pair<int, int>{1, 0};
                        }
                        else{
                            vectorOfPositions[j] = vectorOfPositions[j] + pair<int, int>{-1, 0};
                        }
                    }
                    else {
                        if (vectorOfPositions[j-1].first > vectorOfPositions[j].first && vectorOfPositions[j-1].second > vectorOfPositions[j].second){
                            vectorOfPositions[j] = vectorOfPositions[j] + pair<int, int>{1, 1};
                        }
                        else if (vectorOfPositions[j-1].first > vectorOfPositions[j].first && vectorOfPositions[j-1].second < vectorOfPositions[j].second){
                            vectorOfPositions[j] = vectorOfPositions[j] + pair<int, int>{1, -1};
                        }
                        else if (vectorOfPositions[j-1].first < vectorOfPositions[j].first && vectorOfPositions[j-1].second > vectorOfPositions[j].second){
                            vectorOfPositions[j] = vectorOfPositions[j] + pair<int, int>{-1, 1};
                        }
                        else if (vectorOfPositions[j-1].first < vectorOfPositions[j].first && vectorOfPositions[j-1].second < vectorOfPositions[j].second){
                            vectorOfPositions[j] = vectorOfPositions[j] + pair<int, int>{-1, -1};
                        }
                    }
                }
            }
            visitedByTail[vectorOfPositions[9]] = true;
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
