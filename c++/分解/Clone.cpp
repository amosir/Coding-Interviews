#include<iostream>
using namespace std;
struct RandomListNode {
    int label;
    struct RandomListNode *next, *random;
    RandomListNode(int x) :
            label(x), next(NULL), random(NULL) {
    }
};
/**
 * 1.遍历链表，复制链表中的每个结点，并将复制的结点插入到该结点的后面
 * 2.如果原结点的random指针指向的是结点B，那么将复制结点的random指针指向结点B的复制结点B'。
 * 3.将结点和复制结点分为两个链表
 */
class Solution {
public:
    RandomListNode* Clone(RandomListNode* pHead)
    {

        if(!pHead){
            return NULL;
        }
        // 将复制节点接在原始节点的后面
        RandomListNode *work = pHead;
        while(work){
            RandomListNode *copyNode = new RandomListNode(work->label);
            copyNode->next = work->next;
            work->next = copyNode;
            work = copyNode->next;
        }

        // 为 random指针赋值
        work = pHead;
        // 指向赋值节点
        RandomListNode *copyWork = NULL;
        while(work){
            copyWork = work->next;
            if(work->random){
                copyWork->random  = work->random->next;
            }
            work = copyWork->next;
        } 

        // 分离原始链表和复制链表
        work = pHead;
        copyWork  = work->next;
        // 复制链表的头部
        RandomListNode *copyHead = pHead->next;
        while(work){
            work->next = copyWork->next;
            work = work->next;
            if(work){
                copyWork->next = work->next;
            }else{
                copyWork->next = NULL;
            }
            copyWork = copyWork->next;
        }
        return copyHead;
    }
};