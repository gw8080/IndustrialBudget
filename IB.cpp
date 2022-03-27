//George Wagenknecht - 2022
#include <iostream>
#include <sstream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    cout << "IndustrialBudget" << endl;
    string slotCount,slotValue,fulfillmentA,fulfillmentB,fulfillmentC,itemsValue;
    vector<int> tokensA,tokensB,tokensC;
    cout << "Enter slot amount per month: ";
    std::getline (std::cin,slotCount);
    vector<int> slot;
    for(int n = 1; n < 4; n++)
    {
        for(int i = 1; i < (stoi(slotCount)+1); i++)
        {
            cout << "Enter total slot value for slot " << i << " @ month " << n << ":";
            std::getline (std::cin,slotValue);
            slot.push_back(stoi(slotValue));
        }
    }
    cout << "which slots are fulfilled this month?(separated by space):";
    std::getline (std::cin,fulfillmentA);
    cout << "which slots are fulfilled next month?(separated by space):";
    std::getline (std::cin,fulfillmentB);
    cout << "which slots are fulfilled in the 3rd month?(separated by space):";
    std::getline (std::cin,fulfillmentC);
    cout << "enter value of items requested:";
    std::getline (std::cin,itemsValue);
    stringstream check1(fulfillmentA);
    string intermediate;
    while(getline(check1, intermediate, ' '))
    {
        tokensA.push_back(stoi(intermediate));
    }
    stringstream check2(fulfillmentB);
    intermediate = "";
    while(getline(check2, intermediate, ' '))
    {
        tokensB.push_back(stoi(intermediate));
    }
    stringstream check3(fulfillmentC);
    intermediate = "";
    while(getline(check3, intermediate, ' '))
    {
        tokensC.push_back(stoi(intermediate));
    }
    vector<int> freeAvailFunds,freeSlot;
    for(int n = 0; n < slot.size(); n++)
    {
        std::vector<int>::iterator it;
        it = find (tokensA.begin(), tokensA.end(), n);
        if (it == tokensA.end())
        {
            freeAvailFunds.push_back(slot[n]);
            freeSlot.push_back(n);
        }
        it = find (tokensB.begin(), tokensB.end(), n);
        if (it == tokensB.end())
        {
            freeAvailFunds.push_back(slot[n]);
            freeSlot.push_back(n);
        }
        it = find (tokensC.begin(), tokensC.end(), n);
        if (it == tokensC.end())
        {
            freeAvailFunds.push_back(slot[n]);
            freeSlot.push_back(n);
        }
    }
    vector<int> slotsTaken;
    for(int f = 0; f < freeSlot; f++)
    {
        while(freeSlot[f] > 0)
        {
            itemsValue--;
            freeSlot[f]--;
            if(itemsValue == 0)
            {
                break;
            }
        }
        slotsTaken.push_back(f);
        if(itemsValue == 0)
        {
            cout << "the new purchase will require slots ";
            for(int h = 0; h < slotsTaken; h++)
            {
                cout << slotsTaken[h] << " ";
            }
            break;
        }
    }
    return 0;
}
