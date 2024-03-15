#include <iostream>
using namespace std;

#define Digit 12

int pow(int x, int n)
{
    int rst = 1;
    for (int i = 0; i < n; i++) rst *= x;
    return rst;
}

class Node
{
private:
    int val;
    Node *child[Digit];

public:
    Node()
    {
        for (int i = 0; i < Digit; i++) this->child[i] = nullptr;
    }
    Node(int _val) : val(_val) 
    {
        for (int i = 0; i < Digit; i++) this->child[i] = nullptr;
    }
    void gain()
    {
        for (int i = Digit - 1; i >= 0; i--)
        {
            if (val >= pow(2, i))
            {
                val -= pow(2, i);
                child[i] = new Node(i);
                if (i > 1) child[i]->gain();
            }
        }
    }
    void show()
    {
        bool plus = false;
        bool many = false;
        cout << "2";
        for (int i = Digit -1; i >= 0; i--)
        {
            if (child[i] != nullptr)
            {
                if (plus) cout << "+";
                plus = true;
                if (child[i]->val > 1)
                {
                    if (!many) cout << "(";
                    child[i]->show();
                }
                else if (child[i]->val == 1)
                {
                }
                else if (child[i]->val == 0)
                {
                    cout << "(0)";
                }
                plus = true;
            }
        }
    }
};



int main()
{
    int x;
    cin >> x;
    Node *base = new Node(x);
    base->gain();
    base->show();
    return 0;
}