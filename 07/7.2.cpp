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

    int getNestedCount(map<string, Bag> definitions){
        int count = 0;
        if(!allowableBags.empty()){
            map<string, int>::iterator it;
            for( it = allowableBags.begin(); it != allowableBags.end(); it++ ){
                count+= it->second;
                count+= it->second * definitions[it->first].getNestedCount(definitions);
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

    
    cout << bagDefinitions["shiny gold"].getNestedCount(bagDefinitions) << '\n';
    return 0;
}
