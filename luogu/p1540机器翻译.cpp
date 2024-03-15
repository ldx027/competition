#include <iostream>
#include <list>
using namespace std;

bool haveInList(unsigned int word, list<unsigned int> *mem)
{
    auto it = mem->begin();
    for (; it != mem->end(); it++)
    {
        if (*it == word)
            return true;
    }
    return false;
}

int main()
{
    int M, N;
    cin >> M >> N;

    list<unsigned int> mem;
    int ans = 0;

    unsigned int word;
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &word);
        if (haveInList(word, &mem))
            continue;
        else
        {
            ans++;        
            if (mem.size() == M)
            {
                mem.pop_front();
            }
                mem.push_back(word);
        }
    }

    cout << ans << endl;
    
    return 0;
}