// 相遇时:
// 快指针路程=a+(b+c)k+b ，k>=1  其中b+c为环的长度，k为绕环的圈数（k>=1,即最少一圈，不能是0圈，不然和慢指针走的一样长，矛盾）。
// 慢指针路程=a+b
// 快指针走的路程是慢指针的两倍，所以：
// (a+b）*2=a+(b+c)k+b
// 化简可得：
// a=(k-1)(b+c)+c
// 这个式子的意思是:链表头到环入口的距离=相遇点到环入口的距离+（k-1）圈环长度。其中k>=1,所以k-1>=0圈。
// 所以两个指针分别从链表头和相遇点出发，最后一定相遇于环入口。
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
    ListNode* EntryNodeOfLoop(ListNode* pHead)
    {
        // 链表为空或只有一个节点
        if(pHead == NULL || pHead->next == NULL){
            return NULL;
        }
        // 快慢指针
        ListNode *fast = pHead,*slow = pHead;
        ListNode *cutIn = NULL;
        
        
        while(fast != NULL && fast->next != NULL){
            fast = fast->next->next;
            slow = slow->next;
            if(fast == slow){
                // 交汇点
                cutIn = fast;
                slow = pHead;
                while(slow!=fast){
                    slow = slow->next;
                    fast = fast->next;
                }
                return slow;
            }
        }

        return NULL;
    }
};