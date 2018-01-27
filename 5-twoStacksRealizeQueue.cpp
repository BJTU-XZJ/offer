#include<stdio.h>
#include<iostream>
#include<vector>
#include<stack>
using namespace std;
class Solution
{
public:
    void push(int element)
    {
        stack1.push(element);
    }
    int pop()
    {
        int ele;
        if(stack2.size()==0)
        {
            while(stack1.size() > 0)
            {
                int temp = stack1.top();
                stack1.pop();
                stack2.push(temp);
            }
        }
        if(stack2.size()==0)
        {
            printf("error\n");
            return -1;
        }
        ele = stack2.top();
        stack2.pop();
        return ele;
    }
private:
    stack<int> stack1;
    stack<int> stack2;
};
int main()
{
    class Solution s;
    for(int i=1; i<6; i++)
        s.push(i);
    for(int i=1; i<6; i++)
        printf("%d ",s.pop());
    return 0;
}
