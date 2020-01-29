#include <iostream>
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
    ListNode* ReverseList(ListNode* pHead) {
        // 空链表或只有一个节点
        if(pHead == NULL || pHead->next == NULL){
            return pHead;
        }

        // 临时头结点
        ListNode *newHead = NULL;

        ListNode  *work = pHead;
        ListNode *next = pHead->next;
        while(work){
            next = work->next;
            work->next = newHead;
            newHead = work;
            work  = next;

        }
        return  newHead;
    }
};