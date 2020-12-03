#include <iostream>
#include <vector>
#include <string>
#include <climits>
using namespace std;

int main()
{
    vector<vector<char>> inputs;

    string temp;
    while (getline(cin, temp))
    {
        vector<char> tempVec;
        for (int i = 0; i < temp.length(); i++)
        {
            tempVec.push_back(temp[i]);
        }
        inputs.push_back(tempVec);
        tempVec.clear();
    }

    int width = inputs[0].size();
    long long mult = 1;
    int treeCount;
    int xSlopes[5] = {1, 3, 5, 7, 1};
    int ySlopes[5] = {1, 1, 1, 1, 2};
    
    for (int slope = 0; slope < 5; slope++)
    {
        treeCount = 0;
        int xSlope = xSlopes[slope];
        int ySlope = ySlopes[slope];
        int xPos = 0, yPos = 0;       
        // navigate the current line
        for (int yPos = 0; yPos < inputs.size(); yPos += ySlope)
        {
            char thisSquare = inputs[yPos][xPos];
            if (thisSquare == '#')
                treeCount++;
            xPos += xSlope;
            // wrap if x goes too far right
            xPos = xPos % (width - 1);
        }
        mult *= treeCount;
    }
    cout << mult << '\n';
    return 0;
}
