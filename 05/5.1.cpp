#include <iostream>
#include <vector>
using namespace std;

int main(){
    int highestSeat = 0;

    string s;
    while(cin >> s){
        int lower = 0;
        int higher = 127;
        int row, column;

        for(int i = 0; i < 7; i++){
            if(s[i] == 'F') higher = (higher - lower)/2 + lower;
            else lower = (higher-lower)/2 + lower +1;
        }
        row = lower;

        lower = 0;
        higher = 7;
        for(int i = 7; i < 10; i++){
            if(s[i] == 'R') lower = (higher - lower)/2 + lower+1;
            else higher = (higher-lower)/2 + lower;
        }
        column = higher;

        int seat = row*8 + column;
        if(seat > highestSeat) highestSeat = seat;

    }
    cout << "Highest Seat: " << highestSeat << '\n';
    
    return 0;
}
