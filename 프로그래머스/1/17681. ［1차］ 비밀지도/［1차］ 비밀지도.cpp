#include <string>
#include <vector>
#include <string>
#include <bitset>
#include <algorithm>
#include <iostream>

using namespace std;

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) 
{
    vector<string> result;
    for(int i = 0; i<n; i++)
    {
        int combined = arr1[i] | arr2[i];
        string binary = bitset<32>(combined).to_string();
        binary = binary.substr(32-n);
        
        for(char &c : binary)
        {
            c = (c=='1') ? '#' : ' ';
        }
        
        result.push_back(binary);
    }
    
    return result;
}