#include <stdio.h>
#include <stdlib.h>

// 이진 트리 노드 정의
typedef struct TreeNode
{
    int data;
    struct TreeNode* left, * right;
} TreeNode;

TreeNode n1 = { 4, NULL, NULL };
TreeNode n2 = { 5, NULL, NULL };
TreeNode n3 = { '*', &n1, &n2 };
TreeNode n4 = { 3, NULL, NULL };
TreeNode n5 = { '+', &n3, &n4 } ;
TreeNode n6 = { 2, NULL, NULL };
TreeNode n7 = { '+', &n5, &n6 };

TreeNode n8 = { 6, NULL, NULL };
TreeNode n9 = { 7, NULL, NULL };
TreeNode n10 = { '/', &n8, &n9 };
TreeNode n11 = { 9, NULL, NULL };
TreeNode n12 = { '-', &n7, &n10 };
TreeNode n13 = { '+', &n12, &n11 };

TreeNode* exp = &n13;

// 이진 트리 노드 수 계산 함수 (반복적 방법)
int countNodes(TreeNode* root)
{
    if (root == NULL)
        return 0;

    int count = 1;
    count += countNodes(root->left);  // 왼쪽 서브트리 노드 수
    count += countNodes(root->right); // 오른쪽 서브트리 노드 수

    return count;
}

double evaluate(TreeNode* root)
{
    if (root == NULL)
    { 
        return 0.0;
    }

    if (root->left == NULL && root->right == NULL)
    { 
        return (double)root->data;
    }

    else
    {
        double op1 = evaluate(root->left);
        double op2 = evaluate(root->right);
       
        switch (root->data)
        {
        case '+': 
            printf("%.2lf %c %.2lf = %.2lf\n", op1, root->data, op2, op1 + op2);
            return op1 + op2;
        case '-': 
            printf("%.2lf %c %.2lf = %.2lf\n", op1, root->data, op2, op1 - op2);
            return op1 - op2;
        case '*': 
            printf("%.2lf %c %.2lf = %.2lf\n", op1, root->data, op2, op1 * op2);
            return op1 * op2;
        case '/': 
            printf("%.2lf %c %.2lf = %.2lf\n", op1, root->data, op2, op1 / op2);
            return op1 / op2;
        }
    }
    return 0.0;
}

int main()
{
    printf("수식의 값은 %.2lf입니다. \n\n", evaluate(exp));
    printf("총 노드의 수 : %d\n", countNodes(exp));
    return 0;
}