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
    ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
    {
        if(!pHead1 ||!pHead2){
            return pHead1?pHead1:pHead2;
        }
        ListNode *pos1 = pHead1;
        ListNode *pos2 = pHead2;
        // 头结点
        ListNode *head = new ListNode(0);
        // 合并链表的工作指针
        ListNode *pos3 = head;
        while(pos1 && pos2){
            if(pos1->val < pos2->val){
                pos3->next = pos1;
                pos1 = pos1->next;
                pos3 = pos3->next;
                pos3->next = NULL;
            }else{
                pos3->next = pos2;
                pos2 = pos2->next;
                pos3 = pos3->next;
                pos3->next = NULL;
            }
        }

        if(pos1){
            pos3->next = pos1;
        }
        if(pos2){
            pos3->next = pos2;
        }
        return head->next;
        
    }
};