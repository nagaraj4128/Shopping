#include <bits/stdc++.h>
#include "mingw.thread.h"
#include <unistd.h>
#define _WIN32_WINNT 0x0501
using namespace std;

void func1()
{
    for (int i = 0; i < 100; i++)
    {
        sleep(1);
        cout << "func 1 " << i << "\n";
    }
}
void func2()
{
    for (int i = 0; i < 100; i++)
    {
        sleep(1);
        cout << "func 2 " << i << "\n";
    }
}

int main()
{
    std::thread t1(func1);
    std::thread t2(func2);

    t1.join();
    t2.join();

    return 0;
}