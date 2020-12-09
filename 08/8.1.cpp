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
    vector<Instruction> inputs;
    while(cin){
        string tempStr;
        int tempInt;
        cin >> tempStr >> tempInt;
        if(tempStr.length() > 2){
            Instruction tempInst(tempStr, tempInt);        
            inputs.push_back(tempInst);
        }
    }

    int i = 0;
    int accumulator = 0;
    while(i < inputs.size()){
        Instruction* thisInst = &inputs[i];
        if(thisInst->runCount >= 1) {
            cout << "Break at instruction " << i << ", accumulator: " << accumulator << "\n";
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
        cout << i << '\n';
    
    }
    
    return 0;
}
