#include <iostream>

#include "TimeSheet.h"
using namespace std;
using namespace lab3;
int main()
{
    TimeSheet hulk("HULK", 10);
    TimeSheet copyHulk(hulk);
    hulk.AddTime(1);
    hulk.AddTime(2);
    cout << hulk.GetTotalTime() << endl;
    cout << copyHulk.GetTotalTime() << endl;
    copyHulk = hulk;
    cout << copyHulk.GetTotalTime() << endl;



    return 0;
}