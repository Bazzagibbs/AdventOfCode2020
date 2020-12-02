#include <iostream>
using namespace std;

int main(){
    int sum, min, max;
    char policy, trash;
    string password;
    
    while(cin){
        cin >> min >> trash >> max >> policy >> trash >> password;
        
        int policyCount = 0;
        for(string::size_type i = 0; i < password.size(); i++)
            if(password[i] == policy) policyCount++;
        
        if(policyCount >= min && policyCount <= max) sum++;

    }
    cout << sum << '\n';
    return 0;
}
