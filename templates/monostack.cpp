#include <bits/stdc++.h>
using namespace std;
class monotype
{
public:
    int con;
    bool mono(monotype other)
    {
        return other.con <= con ? true : false;
    }
};
template <typename MONOTYPE>
class monostack
{
private:
    stack<MONOTYPE> sk;

public:
    void __preparePush(MONOTYPE k)
    {
        while (!sk.empty() && !sk.top().mono(k))
            sk.pop();
    }
    void push(MONOTYPE k)
    {
        __preparePush(k);
        sk.push(k);
    }
    bool empty() { return sk.empty(); }
    int size() { return sk.size(); }
    void pop() { sk.pop(); }
    MONOTYPE top() { return sk.top(); }
};

int main()
{
    return 0;
}