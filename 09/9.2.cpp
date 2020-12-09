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
    vector<int> allInputs;
    for(int i = 0; i < preambleCount; i++){
        cin >> temp;
        allInputs.push_back(temp);
        inputs.push_back(temp);
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

            for(int i = 0; i < allInputs.size(); i++){
                int sum = 0;
                int smallestNum = allInputs[i];
                int largestNum = allInputs[i];
                for(int j = i; sum < temp && j < allInputs.size(); j++){
                    sum+= allInputs[j];
                    if(allInputs[j] > largestNum) largestNum = allInputs[j];
                    if(allInputs[j] < smallestNum) smallestNum = allInputs[j];
                    if(sum == temp){
                        cout << "Solution: " << smallestNum + largestNum << "\n";
                        return 0;
                    }
                }
            }
            cout << "Error: solution not found...\n";
            return 0;
        }

        inputs.push_back(temp);
        allInputs.push_back(temp);
        inputs.pop_front();
    }


    
    return 0;
}
