#include <iostream>
#include <vector>
using namespace std;

int main(){
    int highestSeat = 0;
    vector<int> seatID;
    string s;
    bool seatTaken[128*8];
    for(int i = 0; i < 128*8; i++){
        seatTaken[i] = false;
    }


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
        seatTaken[seat] = true;
        if(seat > highestSeat) highestSeat = seat;
    }

    for(int i = 0; i < 128*8; i++){
        if(i%8 == 0) cout << '\n';
        int debug;
        if(seatTaken[i]) debug = 0;
        else debug = i;
        cout << "[ " << debug << " ]";
    }

    return 0;
}
