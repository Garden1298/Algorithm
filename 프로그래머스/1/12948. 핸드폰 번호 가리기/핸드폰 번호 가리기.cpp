#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

string solution(string phone_number) {
    string answer = "";
    int size = phone_number.size();
    
    if(size == 4)
    {
        return phone_number;
    }
    
    return string(size -4, '*') + phone_number.substr(size - 4);
}