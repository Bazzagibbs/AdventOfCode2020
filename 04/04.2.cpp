#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <map>

using namespace std;



int main(){

    vector<string> entries;
    string temp;
    string entry;
    while(getline(cin, temp)){
        if(temp.length() == 1){
            entries.push_back(entry);
            entry.clear();
        } else{
            entry.append(temp + ' ');
        }
    }
    entries.push_back(entry);
    int validCount = 0;
    for(string e : entries){
        stringstream ss(e);
        map<string,string> lookup; 
        cout << "Entry:" << '\n';       
        while(ss){
            string word;
            ss >> word;
            if(word.length() > 0){
            string key;
            key = word.substr(0, 3);
            string value;
            value = word.substr(4);
            lookup[key] = value;
            cout << key << " --> " << value << "\n";
            }
        }   
  
        map<string,string>::iterator byr, iyr, eyr, hgt, hcl, ecl, pid;
        byr = lookup.find("byr");
        iyr = lookup.find("iyr");
        eyr = lookup.find("eyr");
        hgt = lookup.find("hgt");
        hcl = lookup.find("hcl");
        ecl = lookup.find("ecl");
        pid = lookup.find("pid");

        bool isValid = true;
        if(byr != lookup.end()){
            int byrint = stoi(byr->second);
            if(byrint > 2002 || byrint < 1920) isValid = false;
        } else isValid = false;
        
        if(iyr != lookup.end()){
            int iyrint = stoi(iyr->second);
            if(iyrint > 2020 || iyrint < 2010) isValid = false;
        } else isValid = false;

        if(eyr != lookup.end()){
            int eyrint = stoi(eyr->second);
            if(eyrint > 2030 || eyrint < 2020) isValid = false;
        } else isValid = false;

        if(hgt != lookup.end()){
            stringstream hs(hgt->second);
            int height;
            string unit;
            hs >> height;
            hs >> unit;

            cout << height << " " << unit << "\n";
            if(unit == "cm"){
                if(height > 193 | height < 150) isValid = false;
            }
            else if(unit == "in"){
                if(height > 76 || height < 59) isValid = false;
            }
            else isValid = false;
        } else isValid = false;

        if(hcl != lookup.end()){
            string hclstr = hcl->second;
            if(hclstr[0] == '#' && hclstr.length() == 7){
                for(int i = 1; i < 7; i++){
                    char thisChar = hclstr[i];
                    if(!((thisChar >='0' && thisChar <='9') || (thisChar >='a' && thisChar <='f'))){
                        isValid = false;
                    }
                }
            }
            else isValid = false;
        } else isValid = false;
        
        if(ecl != lookup.end()){
            string eclstr = ecl->second;
            if(!(
                eclstr == "amb" ||
                eclstr == "blu" ||
                eclstr == "brn" ||
                eclstr == "gry" ||
                eclstr == "grn" ||
                eclstr == "hzl" ||
                eclstr == "oth"
            )){
                isValid =false;
            }
        } else isValid = false;
        if(pid != lookup.end()){
            if(pid->second.length() == 9){
                try{
                long pidint = stol(pid->second);
                } catch(invalid_argument){
                    isValid = false;
                }
            }
            else isValid =false;
        } else isValid = false;



        if(isValid) validCount++;
    }
    cout << "Entry count: " << entries.size() << "\nValid count: " << validCount << "\n";
    return 0;
}
