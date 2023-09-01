class Solution {
public:
    int NextNum(int n)
    {
        int num = 0;
        while(n!=0)
        {
            int curNum = n%10;
            num += curNum*curNum;
            n = n/10;
        }
        return num;
    }

    bool isHappy(int n) {
        int a = n;
        int b = NextNum(n);
        while(b !=1 && b != a)
        {
            a = NextNum(a);
            b = NextNum(NextNum(b));
        }
        return b == 1;
    }
};