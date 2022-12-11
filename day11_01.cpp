#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
struct Monkey{
    int counter = 0;
    function<ll(ll)> evolution;
    vector<ll> numbers;
    ll verify;
    pair<ll, ll> true_false_redirection;
};
vector<Monkey> monkeys;
int main(int argc, char const *argv[])
{
    // monkeys.push_back(Monkey{0, [](ll old){return old * 19;}, {79, 98}, 23, {2, 3}});
    // monkeys.push_back(Monkey{0, [](ll old){return old + 6;}, {54, 65, 75, 74}, 19, {2, 0}});
    // monkeys.push_back(Monkey{0, [](ll old){return old * old;}, {79, 60, 97}, 13, {1, 3}});
    // monkeys.push_back(Monkey{0, [](ll old){return old + 3;}, {74}, 17, {0, 1}});
    monkeys.push_back(Monkey{0, [](ll old){return old * 17;}, {93, 98}, 19, {5,3}});
    monkeys.push_back(Monkey{0, [](ll old){return old + 5;}, {95, 72, 98, 82, 86}, 13, {7, 6}});
    monkeys.push_back(Monkey{0, [](ll old){return old + 8;}, {85, 62, 82, 86, 70, 65, 83, 76}, 5, {3, 0}}); 
    monkeys.push_back(Monkey{0, [](ll old){return old + 1;}, {86, 70, 71, 56}, 7, {4, 5}});
    monkeys.push_back(Monkey{0, [](ll old){return old + 4;}, {77, 71, 86, 52, 81, 67}, 17, {1, 6}});
    monkeys.push_back(Monkey{0, [](ll old){return old * 7;}, {89, 87, 60, 78, 54, 77, 98}, 2, {1, 4}});
    monkeys.push_back(Monkey{0, [](ll old){return old + 6;}, {69, 65, 63}, 3, {7, 2}});
    monkeys.push_back(Monkey{0, [](ll old){return old * old;}, {89}, 11, {0, 2}});

    for (int i = 0; i < 20; i++){
        for (int j = 0; j < monkeys.size(); j++){
            for (int k = 0; k < monkeys[j].numbers.size(); k++){
                monkeys[j].counter += 1;
                ll new_number = monkeys[j].evolution(monkeys[j].numbers[k]);
                new_number = (new_number) / 3;
                if (new_number % monkeys[j].verify == 0){
                    monkeys[monkeys[j].true_false_redirection.first].numbers.push_back(new_number);
                } else {
                    monkeys[monkeys[j].true_false_redirection.second].numbers.push_back(new_number);
                }
            }
            monkeys[j].numbers.clear();
        }
    }
    vector<int> final_counters;
    for (int i = 0; i < monkeys.size(); i++){
        final_counters.push_back(monkeys[i].counter);
    }
    sort(final_counters.rbegin(), final_counters.rend());
    cout << final_counters[0] * final_counters[1] << endl;

    return 0;
}


