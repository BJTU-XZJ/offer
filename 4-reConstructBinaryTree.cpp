#include<stdio.h>
#include<iostream>
#include<stdlib.h>
#include<vector>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
TreeNode* ConstructCore(int* startPreorder, int* endPreorder, int* startInorder, int* endInorder)
{
    //前序遍历的第一个数字是根结点的值
    int rootValue = startPreorder[0];
    TreeNode* root;
    root = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    root->val = rootValue;
    root->left = root->right = NULL;
    if(startPreorder == endPreorder)
    {
        if(startInorder==endInorder &&
                *startPreorder==*startInorder)
            return root;
        else
        {
            //throw std::exception("Invalid input.");.
            printf("Invalid input.");
            return NULL;
        }
    }
    //在中序遍历中找到根结点的值
    int* rootInorder = startInorder;
    while(rootInorder<=endInorder && *rootInorder!=rootValue)
        ++rootInorder;

    if(rootInorder==endInorder && *rootInorder!=rootValue)
    {
        //throw std::exception("Invalid input.");
        printf("Invalid input.\n");
        return NULL;
    }

    int leftLength = rootInorder -startInorder;
    int* leftPreorderEnd = startPreorder + leftLength;
    if(leftLength>0)
    {
        root->left = ConstructCore(startPreorder+1,leftPreorderEnd,startInorder,rootInorder-1);
    }
    if(leftLength<endPreorder-startPreorder)
    {
        root->right = ConstructCore(leftPreorderEnd+1,endPreorder,rootInorder+1,endInorder);
    }
    return root;
}
TreeNode* Construct(int* preorder, int* inorder, int length)
{
    if(preorder==NULL || inorder==NULL || length<=0)
        return NULL;
    return ConstructCore(preorder,preorder+length-1,
                         inorder,inorder+length-1);
}
TreeNode* reConstructBinaryTree(vector<int> pre, vector<int> vin)
{
    int vin_size = vin.size();
    if(vin_size==0)
        return NULL;
    vector<int> pre_left, pre_right, vin_left, vin_right;
    int rootValue = pre[0];
    TreeNode* node = new TreeNode(rootValue);
    int pos = 0;
    for(pos; pos<vin_size; pos++)
    {
        if(vin[pos]==rootValue)
            break;
    }
    for(int i=0; i<vin_size; i++)
    {
        if(i < pos)
        {
            vin_left.push_back(vin[i]);
            pre_left.push_back(pre[i+1]);
        }
        else if(i > pos)
        {
            vin_right.push_back(vin[i]);
            pre_right.push_back(pre[i]);
        }
    }
    node->left = reConstructBinaryTree(pre_left, vin_left);
    node->right = reConstructBinaryTree(pre_right, vin_right);
}
int main()
{
    int pre[8]= {1,2,4,7,3,5,6,8};
    int in[8]= {4,7,2,1,5,3,8,6};
    Construct(pre,in,8);
    return 0;
}
