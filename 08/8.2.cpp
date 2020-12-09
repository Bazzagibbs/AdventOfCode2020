#include <iostream>
#include <vector>
using namespace std;

class Instruction{
    public:
    string instruction;
    int offset = 0;
    int runCount = 0;

    Instruction(){instruction = "nop";}
    Instruction(string inst, int off){
        instruction = inst;
        offset = off;
    }
};

int main(){
    vector<Instruction> inputs, backup;
    while(cin){
        string tempStr;
        int tempInt;
        cin >> tempStr >> tempInt;
        if(tempStr.length() > 2){
            Instruction tempInst(tempStr, tempInt);        
            inputs.push_back(tempInst);
        }
    }
    backup = inputs;


    for(int j = 0; j < inputs.size(); j++){
        inputs = backup;
        int accumulator = 0;
        if(inputs[j].instruction == "nop" && inputs[j].offset != 0){
            inputs[j].instruction = "jmp";
        } else if(inputs[j].instruction == "jmp"){
            inputs[j].instruction = "nop";
        }
        else continue;

        int i;
        for(i = 0; i < inputs.size();){
            Instruction* thisInst = &inputs[i];
            // Handle loops
            if(thisInst->runCount >= 1) {
                break;
            }
            thisInst->runCount++;
            
            // Handle instructions
            if(thisInst->instruction == "nop"){
                i++;
                continue;
            }
            if(thisInst->instruction == "acc"){
                accumulator += thisInst->offset;
                i++;
                continue;
            }
            if(thisInst->instruction == "jmp"){
                i += thisInst->offset;
                continue;
            }
        }
        
        if(i == inputs.size()){
            cout << "Program terminated successfully.\nAccumulator: " << accumulator << "\n";
            return 0;
        } 
    }
    
    return 0;
}
