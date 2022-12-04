#include <bits/stdc++.h>
using namespace std;
int main(){
    ifstream inp("input.txt");
    string temp;
    string first_compartiment;
    string second_compartiment;
    string third_compartiment;
    int sum_of_priorities = 0;
    while (inp >> first_compartiment >> second_compartiment >> third_compartiment)
    {
        set<char> first_compartiment_set (begin(first_compartiment), end(first_compartiment));
        set<char> second_compartiment_set (begin(second_compartiment), end(second_compartiment));
        set<char> third_compartiment_set (begin(third_compartiment), end(third_compartiment));
        set<char> intersection, intersection2;
        set_intersection(first_compartiment_set.begin(), first_compartiment_set.end(), second_compartiment_set.begin(), second_compartiment_set.end(), inserter(intersection, intersection.begin()));
        set_intersection(intersection.begin(), intersection.end(), third_compartiment_set.begin(), third_compartiment_set.end(), inserter(intersection2, intersection2.begin()));
        for (char priority: intersection2){
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