#include <string>
#include <vector>

using namespace std;

int solution(vector<int> common) {

    int next;
    
    if(common[1] - common[0] == common[2] - common[1])
    {
        int diff = common[1] - common[0];
        next = common.back() + diff;
    }
    else
    {
        int ratio = common[1] / common[0];
        next = common.back() * ratio;
    }
    
    return next;
}