#include <iostream>
#include <vector>
#include <map>
#include <string>
using namespace std;

int calcUnanimousAnswer(map<char, int> inputMap, int peopleCount){
    map<char,int>::iterator it;
    int count = 0;
    for(it = inputMap.begin(); it != inputMap.end(); it++){
        if (it->second == peopleCount){
            count++;
        }
    }
    return count;
}

int main(){
    map<char, int> inputs;
    string thisInput;
    int peopleCount = 0, qCount = 0;
    while(getline(cin, thisInput)){
        if(thisInput.length() == 1){
            qCount += calcUnanimousAnswer(inputs, peopleCount);
            inputs.clear();
            peopleCount = 0;
        }
        else {
            peopleCount++;
            for (int i = 0; i < thisInput.length() - 1; i++) {
                char a = thisInput[i];
                inputs[a]++;
            }
        }
    }
    qCount += calcUnanimousAnswer(inputs, peopleCount);
    cout <<"Total unanimous questions answered per group: "  << qCount << '\n';

    return 0;
}
