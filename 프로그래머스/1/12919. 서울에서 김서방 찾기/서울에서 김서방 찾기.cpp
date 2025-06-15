#include <string>
#include <vector>

using namespace std;

string solution(vector<string> seoul) {
    int count = seoul.size();
    for(int i = 0; i<count; i++)
    {
        if(seoul[i] == "Kim")
        {
            return "김서방은 " + to_string(i) + "에 있다";
        }
    }
}