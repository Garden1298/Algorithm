#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(vector<int> food) {
    string temp = "";
    for(int i = 1; i<food.size(); i++)
    {
        temp.append(food[i]/2,'0'+i);
    }
    
    string result = temp + '0';
    string rev = temp;
    reverse(rev.begin(),rev.end());
    result+= rev;
    
    return result;
}