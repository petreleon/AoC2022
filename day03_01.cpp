#include <bits/stdc++.h>
using namespace std;
int main(){
    ifstream inp("input.txt");
    string temp;
    int sum_of_priorities = 0;
    while (inp >> temp)
    {
        string first_compartiment = temp.substr(0, temp.size()/2);
        string second_compartiment = temp.substr(temp.size()/2);
        set<char> first_compartiment_set (begin(first_compartiment), end(first_compartiment));
        set<char> second_compartiment_set (begin(second_compartiment), end(second_compartiment));
        set<char> intersection;
        set_intersection(first_compartiment_set.begin(), first_compartiment_set.end(), second_compartiment_set.begin(), second_compartiment_set.end(), inserter(intersection, intersection.begin()));
        for (char priority: intersection){
            if ('a' <= priority && priority <= 'z'){
                sum_of_priorities += priority - 'a' + 1;
            }
            if ('A' <= priority && priority <= 'Z'){
                sum_of_priorities += priority - 'A' + 27;
            }
        }
    }
    cout << sum_of_priorities << endl;
    
    return EXIT_SUCCESS;
}