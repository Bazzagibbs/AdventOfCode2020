#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Required fields:
// byr
// iyr
// eyr
// hgt
// hcl
// ecl
// pid
// cid -- not for now



int main(){

    vector<string> entries;
    string temp;
    string entry;
    while(getline(cin, temp)){
        cout << temp.length() << '\n';
        if(temp.length() == 1){
            entries.push_back(entry);
            entry.clear();
        } else{
            entry.append(temp + ' ');
        }
    }
    int validCount = 0;
    for(string e : entries){
        cout << e << "\n";
        bool byr = string::npos != e.find("byr:");
        bool iyr = string::npos != e.find("iyr:");
        bool eyr = string::npos != e.find("eyr:");
        bool hgt = string::npos != e.find("hgt:");
        bool hcl = string::npos != e.find("hcl:");
        bool ecl = string::npos != e.find("ecl:");
        bool pid = string::npos != e.find("pid:");
        bool cid = string::npos != e.find("cid:");
        if(byr && iyr && eyr && hgt && hcl && ecl && pid){
            validCount++;
        }        
    }
    cout << "Valid entries: " << validCount << '\n';
    
    return 0;
}
