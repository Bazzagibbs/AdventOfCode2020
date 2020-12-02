#include <iostream>
#include <sstream>
using namespace std;

int main(){
    int sum = 0;

    string inString;
    int pos1;
    int pos2;
    char policy;
    char trash;
    string password;
    while(getline(cin, inString)){
        stringstream ss(inString);

        ss >> pos1 >> trash >> pos2 >> policy >> trash >> password;

        int policyCount = 0;
        pos1--;
        pos2--;
        if(password[pos1] == policy) policyCount++;
        if(password[pos2] == policy) policyCount++;

        if(policyCount == 1) sum++;

    }
    cout << sum << '\n';

    
    return 0;
}
