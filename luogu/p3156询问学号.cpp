// #include <iostream>
// using namespace std;

// class Node
// {
// public:
//     int id;
//     Node *next;

// public:
//     Node(){}
//     Node(int _id) : id(_id) {}
// };

// Node *generate(Node *base, int id)
// {
//     Node *newNode = new Node(id);
//     if (base != nullptr)
//     {
//         base->next = newNode;
//     }
//     newNode->next = nullptr;
// }

// int main()
// {
//     int n, m;
//     cin >> n >> m;
//     int id;
//     cin >> id;
//     Node *baseNode = generate(nullptr, id);
//     Node *now = baseNode;
//     for (int i = 0; i < n - 1; i++)
//     {
//         cin >> id;
//         now = generate(now, id);
//     }

//     int idx;
//     for (int i = 0; i < m; i++)
//     {
//         cin >> idx;
//         now = baseNode;
//         for (int i = 0; i < idx - 1; i++)
//         {
//             now = now->next;
//         }
//         cout << now->id << endl;
//     }
    
//     return 0;
// }

#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n, m, x;
    cin >> n >> m;
    vector<int> vec;

    for (int i = 0; i < n; i++)
    {
        cin >> x;
        vec.push_back(x);
    }

    for (int i = 0; i < m; i++)
    {
        cin >> x;
        cout << vec[x - 1] << endl;
    }

    return 0;
}