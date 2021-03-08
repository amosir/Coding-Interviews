#include<iostream>
using namespace std;
struct ListNode {
        int val;
        struct ListNode *next;
        ListNode(int x) :
              val(x), next(NULL) {
        }
};
class Solution {
public:
    ListNode* deleteDuplication(ListNode* pHead){
        // 空链表或只有一个节点
        if(pHead == NULL || pHead->next == NULL){
            return pHead;
        }
        // 防止头结点也是重复节点，需要新建一个头结点
        ListNode *newHead = new ListNode(0);
        newHead->next = pHead;
        // 指向上一个不重复的节点
        ListNode *pre = newHead;
        // 当前工作指针
        ListNode *work = newHead->next;
        while(work != NULL){
            // 当前节点不是最后一个节点且是重复节点
            if(work->next != NULL && work->val == work->next->val){
                //找到重复的最后一个节点
                while(work->next != NULL && work->val == work->next->val){
                    work = work->next;
                }
                pre->next = work->next;
                work = work->next;
            }
            // 不是重复节点则向后继续处理其他节点
            else{
                pre = pre->next;
                work =  work->next;
            }
        }
        return newHead->next;
    }
};