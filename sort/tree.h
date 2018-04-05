#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <utility>
#include <climits>

using namespace std;

/*���Ľṹ*/
struct BinaryTreeNode{
    bool from; //�ж���Դ, ��true, ��false
    int m_nValue;
    BinaryTreeNode* m_pLeft;
    BinaryTreeNode* m_pRight;
};

/*����Ҷ�ӽڵ�*/
BinaryTreeNode* buildList (const std::vector<int>& L);
/*����ż��ʱ, �貹��ڵ�*/
BinaryTreeNode* addMaxNode (BinaryTreeNode* list, int n);
/*��������������С, ������*/
BinaryTreeNode* buildTree (BinaryTreeNode* childNodes, int n);
/*��������, ���¼�����*/
int rebuildTree (BinaryTreeNode* tree);
/*���ϵ��´�ӡ��*/
void printTree (BinaryTreeNode* tree);
