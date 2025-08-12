#include <vector>
#include <iostream>
#include <set>
using namespace std;

int solution(vector<int> nums)
{
    set<int> numset(nums.begin(), nums.end());
    int uniqueCount = numset.size();
    int maxCount = nums.size()/2;
    return min(uniqueCount, maxCount);
}