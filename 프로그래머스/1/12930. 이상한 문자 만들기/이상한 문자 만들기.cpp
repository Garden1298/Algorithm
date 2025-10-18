#include <string>
#include <vector>
#include <iostream>
#include <cctype>

using namespace std;

string solution(string s) {
    string answer = "";
    int idx = 0;
    
    for(char c : s)
    {
        if(c == ' ')
        {
            idx = 0;
            answer += c;
        }
        else
        {
            if(idx % 2 == 0)
            {
                answer += toupper(c);
            }
            else
            {
                answer += tolower(c);
            }
            idx++;
        }
    }
    
    return answer;
}