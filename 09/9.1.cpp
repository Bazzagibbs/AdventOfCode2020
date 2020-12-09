#include <iostream>
#include <vector>
#include <deque>
#include <string>
using namespace std;

int main(int argv, char** argc){
    int preambleCount = 25;
    if(argv != 1){
        preambleCount = stoi(argc[1]);
    }

    int temp;
    deque<int> inputs;
    for(int i = 0; i < preambleCount; i++){
        cin >> temp;
        inputs.push_front(temp);
    }

    while(cin >> temp){
        bool isSum = false;
        for(int i = 0; i < inputs.size()-1; i++){
            for(int j = i+1; j < inputs.size(); j++){
                if(inputs[i] + inputs[j] == temp){
                    isSum = true;
                    break;
                }
            }
            if(isSum) break;
        }
        if(!isSum){
            cout << "Number does not fit criteria: " << temp << "\n";
            return 0;
        }
        inputs.push_front(temp);
        inputs.pop_back();
    }


    
    return 0;
}
