#include <iostream>
#include <vector>
#include <map>
#include <string>
using namespace std;

int main(){
    map<char, int> inputs;
    string thisInput;
    int qCount = 0;
    while(getline(cin, thisInput)){
        if(thisInput.length() == 1){
            qCount += inputs.size();
            inputs.clear();
        }
        else {
            for (int i = 0; i < thisInput.length() - 1; i++) {
                char a = thisInput[i];
                inputs[a]++;
            }
        }
    }
    qCount += inputs.size();
    cout <<"Total unique questions answered per group: "  << qCount << '\n';

    return 0;
}
