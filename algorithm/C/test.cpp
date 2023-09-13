#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

const int maxn = 150;
int cnt = 0;
vector<int> primes;
bool judge[maxn];

int main()
{
    int i, j;
    memset(judge, 1, sizeof(judge));
    judge[0] = judge[1] = 0;
    for (i = 2; i < maxn; i++)
    {
        if (judge[i])
        {
            primes.push_back(i);
            cnt++;
        }
        for(j = 0; j < cnt && i * primes[j] <= maxn; j++)
        {
            judge[i * primes[j]] = 0;
            if (i % primes[j] == 0)
                break;
        }
    }
    vector<int>::iterator it;
    for (it = primes.begin(); it != primes.end(); it++)
        cout << *it <<" ";
    return 0;
}