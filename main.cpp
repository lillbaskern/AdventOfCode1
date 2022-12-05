#include <iostream>
#include <fstream>
#include <string>
#include <bits/stdc++.h>
#include <list>
using namespace std;

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wc++20-extensions"


int main()
{
    //creating new ifstream and opening file
    ifstream testCase;
    testCase.open("F:\\Cplusplus\\input.txt", ifstream::in);
    if(!testCase.is_open())
    {//if file is not open
        cout << "invalid file" << endl;
        return 0;
    }
    //memory for the line currently being read
    string line;
    //id for the curr elf. which number elf it is in ascending order
    int currElf = 1;
    //how many calories it is holding
    int currElfCal = 0;
    //pairs which we will use to pair the elf id with their calories
    //first is cals, second is elf id
    typedef pair<int,int> Elf;
    //list for these pairs. list allows us to sort them
    list<Elf> elves;



    //bool which keeps track of whether the last line read from testCase was empty
    bool wasLastEmpty = false;

    while (getline(testCase, line))
    {
        if(!line.empty())
        {//if line was not empty it contains an int, so:
            wasLastEmpty = false;
            //string to int current line and add it to currElfCal
            currElfCal += stoi(line);
        }
        else
        {
            if(!wasLastEmpty)
            {
                wasLastEmpty = true;
                //make elf, assign numbers, push to list
                Elf elf;
                elf.first = currElfCal;
                elf.second = currElf;
                elves.push_back(elf);

                currElfCal = 0;
                currElf++;
            }
        }
    }
    //sort list of elves using lambda
    elves.sort([](const Elf & a, const Elf & b){return a.first > b.first;});
    auto it = elves.begin();
    int top3Elves = 0;
    for (int i = 0; i < 3; i++)
    {
        top3Elves += it->first;
        cout << "elf at rank " << i << " (elf " << it->second << ") had " << it->first<< " calories" << endl;
        advance(it,1);
    }
    cout << "top 3 elves had this many cals combined: " << top3Elves << endl;

    testCase.close();

    //finally, display heart and return our answer
    char c = 3;
    cout << endl << c;
    return 0;
}




#pragma clang diagnostic pop
