#include <iostream>
#include <vector>
#include <map>
#include <string>
using namespace std;

class Bag{
public:
    string identifier;
    map<string, int> allowableBags;
    int contains = -1;
    Bag(){    }
    Bag(string bagIdentifier){
        identifier = bagIdentifier;
    }

    int getAllowable(map<string, Bag> definitions, string targetBagID){
        int count = 0;
        if(!allowableBags.empty()){
            map<string, int>::iterator it;
            for( it = allowableBags.begin(); it != allowableBags.end(); it++ ){
                if(it->first == targetBagID) count += it->second;
                else count+= definitions[it->first].getAllowable(definitions, targetBagID);
            } 
        }
        return count;
    }

};


int main(){
    map<string, Bag> bagDefinitions;
    while(cin){
        string externalBagID, containsCount, internalBagID, trash, temp;
        
        cin >> externalBagID >> temp;
        if(externalBagID.length() < 1) break;
        externalBagID.append( " " + temp);
        bagDefinitions[externalBagID] = Bag(externalBagID);
        
        cin >> trash >> trash >> containsCount;
        if(containsCount != "no"){
            bool stillContainsBags = true;
            while(stillContainsBags){
                int containsInt = stoi(containsCount);
                
                cin >> internalBagID >> temp;
                internalBagID.append(" " + temp);
                bagDefinitions[externalBagID].allowableBags[internalBagID] = containsInt;

                cin >> temp;
                if(temp[temp.length()-1] == '.') stillContainsBags = false;
                else cin >> containsCount;                
        
            }          
        } else {
            getline(cin, trash);
        }
    }

    int bagsThatCanHoldGold = 0;
    map<string, Bag>::iterator it;
    for(it = bagDefinitions.begin(); it != bagDefinitions.end(); it++){
        if(it->second.getAllowable(bagDefinitions, "shiny gold") != 0) {
            bagsThatCanHoldGold++;
        }
    }
    cout << bagsThatCanHoldGold << '\n';
    return 0;
}
