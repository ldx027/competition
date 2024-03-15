#include <iostream>
using namespace std;

class Node
{
public:
    int val;
    Node *previous;
    Node *next;

public:
    Node()
    {
        val = 0;
        previous = nullptr;
        next = nullptr;
    }
    Node(int val)
    {
        this->val = val;
        previous = nullptr;
        next = nullptr;
    }
    void set(int val)
    {
        this->val = val;
    }
    Node *push(int val)
    {
        Node *newNode = new Node(val);
        newNode->previous = this;
        this->next = newNode;
        return newNode;
    }

    Node *del()
    {
        if (previous != nullptr && next != nullptr)
        {
            previous->next = this->next;
            next->previous = this->previous;
            delete this;
        }
    }
};

int main()
{
    int n, val;
    cin >> n;
    cin >> val;
    Node *baseNode = new Node(val);
    Node *now = baseNode;
    for (int i = 0; i < n - 1; i++)
    {
        cin >> val;
        now = now->push(val); 
    }
    now->next = baseNode;
    now = baseNode;

    int maxScore = 0;
    for (int i = 0; i < n; i++)
    {
        now = baseNode;
        for (int j = 0; j < i; j++)
        {
            now = now->next;
        }
        int score = 0;
        int num = 1;
        while(num <= n)
        {
            if (now->val == num)
            {
                score += num;
                num = 1;
                now->del();
            }
            else
            {
                num++;
            }
            now = now->next;
        }
        cout << score << " ";  
        maxScore = maxScore > score ? maxScore : score;
    }

    return 0;
}