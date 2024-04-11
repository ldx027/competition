#include <fstream>
using namespace std;

int main()
{
    ofstream fout;

    fout.open("test.text", ios::out | ios::app);
    fout << 123 << endl;

    fout.close();
}