#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <bits/stdc++.h>
using namespace std;

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wc++20-extensions"
int main()
{
    int ans = 0;
    ifstream testCase;
    testCase.open("F:\\Cplusplus\\input.txt", ifstream::in);
    if(!testCase.is_open())
    {
        cout << "invalid file" << endl;
        return 0;
    }
    string line;
    vector<int> data;
    int currElf = 1;
    int currElfCal = 0;
    int topElf = 0;
    int topElfCal = 0;
    bool wasLastEmpty = false;

    while (getline(testCase, line))
    {
        if(!line.empty())
        {
            wasLastEmpty = false;
            currElfCal += stoi(line);
        }
        else
        {
            if(!wasLastEmpty)
            {
                wasLastEmpty = true;
                cout << "elf "<< currElf <<" has: " << currElfCal << endl;
                if (currElfCal > topElfCal)
                {
                    topElf = currElf;
                    topElfCal = currElfCal;
                }
                currElfCal = 0;
                currElf++;
            }
        }
    }
    sort(data.begin(),data.end());

    testCase.close();

    //finally, display heart and return our answer
    char c = 3;
    cout << "the elf with the most calories is: " << topElf << endl;
    cout << "they had " << topElfCal << " calories";
    cout << endl << c;
    return ans;
}




#pragma clang diagnostic pop
