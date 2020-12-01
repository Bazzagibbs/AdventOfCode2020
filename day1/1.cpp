#include <iostream>
#include <vector>

using namespace std;


int main(){
    
    vector<int> v;
    int y; 
    while(cin >> y){
       v.push_back(y); 
    }

    // O(n^3) solution
    for(int i = 0; i < v.size()-2; i++){
        for(int j = i+1; j < v.size()-1; j++){
            for(int k = j+1; k < v.size(); k++){
                if(v[i] + v[j] + v[k] == 2020){
                    cout << v[i] * v[j] * v[k];
                }
            }
        }
    } 
    return 0;
}
