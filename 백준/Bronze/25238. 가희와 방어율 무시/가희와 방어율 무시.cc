#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int def, ignoreDef;

    cin>> def >> ignoreDef;

    if(def * (100-ignoreDef) / 100 >= 100)
    {
        cout<<0;
    }
    else{
        cout <<1;
    }

    return 0;
}
