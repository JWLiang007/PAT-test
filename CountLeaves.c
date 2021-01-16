#include <stdio.h>

typedef struct node
{
    char nNo[2];
    struct node *child;
    int numOfChild;
    int level;
} node;

int main()
{
    int numOfNodes, numOfNonLeafNodes = 0;
    node *root;
    scanf("%d %d\n", &numOfNodes, &numOfNonLeafNodes);
    // 读取到非叶子节点为0，直接返回
    if (numOfNonLeafNodes == 0)
        return 0;

    for (int i = 0; i < numOfNonLeafNodes; i++)
    {
        // 初始化非叶节点
        node* nonLeafNode=(node*)malloc(sizeof(node));
        // char pNo[2];
        // fgets 读入时末尾带空字符
        // fgets(a,3,stdin);
        int numOfChild;
        scanf("%c%c %d",nonLeafNode->nNo,nonLeafNode->nNo+1,&nonLeafNode->numOfChild);
        // nonLeafNode->nNo[0]=pNo[0];
        // nonLeafNode->nNo[1]=pNo[1];
        // nonLeafNode->numOfChild=numOfChild;
        if(nonLeafNode->nNo[0]=='0' && nonLeafNode->nNo[1]=='1')
            root=nonLeafNode;

        // 初始化孩子节点
        for(int j = 0; j < numOfChild; j++){
            // char cNo[2];
            node* cNode=(node*)malloc(sizeof(node));
            scanf(" %c%c",cNode->nNo,cNode->nNo+1);
            cNode->child=NULL;
        }

    }
    return 0;
}
