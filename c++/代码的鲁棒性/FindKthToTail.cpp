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
    ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
        if(pListHead == NULL || k == 0){
            return NULL;
        }

        // slow指针指向当前节点，fast指针指向当前节点后的第k个节点
        // 当fast指向链表尾部的下一个时，slow指向目标节点
        ListNode *fast = pListHead;
        ListNode *slow = pListHead;
        for(int count = 0;count < k;count++){
            if(fast == NULL){
                return  NULL;
            }else{
                fast = fast->next;
            }
        }
        while(fast == NULL){
            fast = fast->next;
            slow = slow->next;
        }
        return slow;
    }
};