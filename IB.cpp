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
    string slotCount,slotValue,fulfillment, itemsValueS;
    vector<int> tokens;
    int itemsValue = 0;
    cout << "Enter slot amount: ";
    std::getline (std::cin,slotCount);
    vector<int> slot;
    for(int i = 0; i < (stoi(slotCount)); i++)
    {
        cout << "Enter total slot value for slot " << i << ":";
        std::getline (std::cin,slotValue);
        slot.push_back(stoi(slotValue));
    }
    cout << "which slots are fulfilled?(separated by space):";
    std::getline (std::cin,fulfillment);
    while(true)
    {
        cout << "enter value of items requested:";
        std::getline (std::cin,itemsValueS);
        itemsValue = stoi(itemsValueS);
        stringstream check1(fulfillment);
        string intermediate;
        while(getline(check1, intermediate, ' '))
        {
            tokens.push_back(stoi(intermediate));
        }
        vector<int> freeAvailFunds,freeSlot;
        for(int n = 0; n < slot.size(); n++)
        {
            std::vector<int>::iterator it;
            it = find (tokens.begin(), tokens.end(), n);
            if (it == tokens.end())
            {
                freeAvailFunds.push_back(slot[n]);
                freeSlot.push_back(n);
            }
        }
        vector<int> slotsTaken;
        for(int f = 0; f < freeAvailFunds.size(); f++)
        {
            while(freeAvailFunds[f] > 0)
            {
                itemsValue--;
                freeAvailFunds[f]--;
                if(itemsValue == 0 || freeAvailFunds[f] == 0)
                {
                    slotsTaken.push_back(freeSlot[f]);
                    break;
                }
            }
            if(itemsValue == 0)
            {
                cout << "the new purchase will require slot(s) ";
                for(int h = 0; h < slotsTaken.size(); h++)
                {
                    cout << slotsTaken[h] << " ";
                }
                cout << endl;
                cout << "Update Slots? [y/n]:";
                string update;
                std::getline (std::cin,update);
                if(update == "Y" || update == "y")
                {
                    for(int h = 0; h < slotsTaken.size(); h++)
                    {
                        fulfillment += slotsTaken[h] + " ";
                    }
                    break;
                }
                break;
            }
        }
        if(itemsValue > 0)
        {
            cout << "not enough funds" << endl;
        }
    }
    return 0;
}
