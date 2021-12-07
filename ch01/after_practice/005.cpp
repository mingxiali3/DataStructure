#include <iostream>
using namespace std;
void dif1(int);
void dif2(int);
int main()
{
    dif1(21);
    cout << endl;
    return 0;
}
void dif1 (int y)
{
    if(y>0) dif2(y-3);
    cout << y << " ";
}
void dif2(int x)
{
    if(x) dif1(x);
}