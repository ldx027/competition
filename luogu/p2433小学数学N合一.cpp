#include <iostream>
#include <cmath>
using namespace std;

void func1()
{
    cout << "I love Luogu!" << endl;
}

void func2()
{
    cout << 6 << " " <<  4 << endl;
}

void func3()
{
    cout << int(14 / 4) << endl << 12 << endl << 2 << endl;
}

void func4()
{
    cout << "166.667" << endl;
}

void func5()
{
    cout << int(480 / 32) << endl;
}

void func6()
{
    cout << sqrt(36 + 81) << endl;
}

void func7()
{
    cout << 110 << endl << 90 << endl << 0 << endl;
}

void func8()
{
    double pi = 3.141593;
    cout << 10 * pi << endl << 25 * pi << endl << 4.0 / 3 * pi * 125 << endl;
}

void func9()
{
    cout << 22 << endl;
}

void func10()
{
    cout << 9 << endl;
}

void func11()
{
    cout << 100 / 3.0 << endl;
}

void func12()
{
    cout << 13 << endl << "R" << endl;
}

void func13()
{
    double v = 4.0 / 3.0 * 3.141593 * (64.0 + 1000); 
    cout << int(pow(v, 1.0 / 3)) << endl;
}

void func14()
{
    cout << 50 << endl;
}

int main()
{
    int idx;
    cin >> idx;
    switch(idx)
    {
        case 1: func1(); break;
        case 2: func2(); break;
        case 3: func3(); break;
        case 4: func4(); break;
        case 5: func5(); break;
        case 6: func6(); break;
        case 7: func7(); break;
        case 8: func8(); break;
        case 9: func9(); break;
        case 10: func10(); break;
        case 11: func11(); break;
        case 12: func12(); break;
        case 13: func13(); break;
        case 14: func14(); break;
    }

    return 0;
}