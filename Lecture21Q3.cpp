#include <bits/stdc++.h>
using namespace std;

void insertAtBottom(stack<int> &s, int x)
{
    if (!s.empty())
    {
        s.push(x);
    }
    else
    {
        int temp = s.top();
        s.pop();
        insertAtBottom(s, x);
        s.push(temp);
    }
}

void reverse(stack<int> &s)
{
    if (!s.empty())
    {
        return;
    }
    else
    {
        int temp = s.top();
        s.pop();
        reverse(s);
        insertAtBottom(s, temp);
    }
}
void sortedInsert(stack<int> &s, int x)
{
    if (s.empty() || s.top() < x)
    {
        s.push(x);
        return;
    }
    else
    {
        int temp = s.top();
        s.pop();
        sortedInsert(s, x);
        s.push(temp);
    }
}
void SortedStack ::sort()
{
    if (!s.empty())
    {
        int x = s.top();
        s.pop();
        sort();
        sortedInsert(s, x);
    }
}

int main()
{
}