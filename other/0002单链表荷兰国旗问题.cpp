#include <iostream>
using namespace std;

class Node
{
public:
    int val;
    Node *next;
public:
    Node(int _val) : val(_val)
    {
        next = nullptr;
    }

    Node *create(int val)
    {
        Node *newNode = new Node(val);
        this->next = newNode;

        return newNode;
    }
};

Node *func1(Node *base, int x)
{
    Node *SH = nullptr;
    Node *ST = nullptr;
    Node *EH = nullptr;
    Node *ET = nullptr;
    Node *BH = nullptr;
    Node *BT = nullptr;
    Node *now = base;
    while (now != nullptr)
    {
        if (now->val < x)
        {
            if (SH == nullptr)
                SH = now;
            if (ST != nullptr)
                ST->next = now;
            ST = now;
        }
        else if (now->val == x)
        {
            if (EH == nullptr)
                EH = now;
            if (ET != nullptr)
                ET->next = now;
            ET = now;
        }
        else if (now->val > x)
        {
            if (BH == nullptr)
                BH = now;
            if (BT != nullptr)
                BT->next = now;
            BT = now;
        }
        now = now->next;
    }
    if (ST != nullptr) ST->next = (EH == nullptr ? BH : EH);
    if (ET != nullptr) ET->next = BH;
    if (BT != nullptr) BT->next = nullptr;

    return (SH == nullptr ? (EH == nullptr ? BH : EH) : SH);
}

void show(Node *node)
{
    while (node != nullptr)
    {
        cout << node->val << " ";
        node = node->next;
    }
    cout << endl;
}

int main()
{
    int n;
    cin >> n;
    int val;
    cin >> val;
    Node *base = new Node(val);
    Node *now = base;
    for (int i = 0; i < n - 1; i++)
    {
        cin >> val;
        now = now->create(val);
    }
    show(base);
    int x;
    cin >> x;
    base = func1(base, x);
    show(base);

    return 0;
}