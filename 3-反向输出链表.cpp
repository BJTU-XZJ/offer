#include<stdio.h>
#include<stdlib.h>
#include<vector>
struct ListNode
{
    int val;
    struct ListNode *Next;
};
int main()
{
    struct ListNode *head, *p, *q;
    int n, i, num, stack[1000];
    int base=0, top=0;
    scanf("%d", &n);
    head = NULL;
    q = head;
    for(i=0; i<n; i++)
    {
        scanf("%d", &num);
        p = (struct ListNode *)malloc(sizeof(struct ListNode));
        p->val = num;
        p->Next = NULL;
        if(head==NULL)
            head = p;
        else
            q->Next = p;
        q = p;
    }
    p = head;
    while(p!=NULL)
    {
        stack[top] = p->val;
        top++;
        p = p->Next;
    }
    for(i=top-1; i>=0; i--)
        printf("%d ", stack[i]);
    return 0;
}

/*
struct ListNode
{
    int val;
    struct ListNode *next;
    ListNode(int x) :
        val(x), next(NULL)
    {
    }
};
class Solution
{
public:
    vector<int> printListFromTailToHead(ListNode* head)
    {
        vector<int> result;
        std::stack<int> nodes;
        if(head==NULL)
            return result;
        struct ListNode *p;
        p = head;
        while(p!=NULL)
        {
            nodes.push(p->val);
            p = p->next;
        }
        while(!nodes.empty())
        {
            result.push_back(nodes.top());
            nodes.pop();
        }
        return result;
    }
};
*/
