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
    ListNode* FindFirstCommonNode( ListNode* pHead1, ListNode* pHead2) {
        if(!pHead1 || !pHead2){
            return NULL;
        }
        int len1 = 0,len2 = 0,distance = 0;
        ListNode *work1 = pHead1;
        ListNode *work2 = pHead2;
        // 两个链表的长度
        while(work1){
            len1++;
            work1 = work1->next;
        }
        while(work2){
            len2++;
            work2 = work2->next;
        }
        // work1始终指向较长链表
        if(len1 > len2){
            work1 = pHead1;
            work2 = pHead2;
            distance = len1 - len2;
        }else{
            work1 = pHead2;
            work2 = pHead1;
            distance = len2 - len1;
        }

        // 较长的链表往后移动若干节点使得两个链表剩余长度相等
        for(int i = 0;i < distance;i++){
            work1 = work1->next;
        }

        while(work1 && work2){
            // 公共节点
            if(work1 == work2){
                return work1;
            }else{
                work1 = work1->next;
                work2 = work2->next;
            }
        }
        return NULL;
    }
};