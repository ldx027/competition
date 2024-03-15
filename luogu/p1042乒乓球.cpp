#include <iostream>
#include <string>
using namespace std;

int abs(int x)
{
    return x > 0 ? x : -x;
}

void game(string input, int res);

int main()
{
    char c;
    string input = "";
    cin >> c;
    while (c != 'E')
    {
        input+= c;
        cin >> c;
    }
    game(input, 11);
    printf("\n");
    game(input, 21);

    return 0;
}

void game(string input, int rst)
{
    int score[2] = {0, 0};
    for (int i = 0; i < input.length(); i++)
    {
        if (input[i] == 'W')
        {
            score[0]++;
        }
        else if (input[i] == 'L')
        {
            score[1]++;
        }

        if ((score[0] >= rst || score[1] >= rst) && abs(score[0] - score[1]) >= 2)
        {
            printf("%d:%d\n", score[0], score[1]);
            score[0] = 0;
            score[1] = 0;
        }
    }
    printf("%d:%d\n", score[0], score[1]);
}