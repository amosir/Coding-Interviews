#include <iostream>
#include <vector>
using namespace std;
/**
*  struct ListNode {
*        int val;
*        struct ListNode *next;
*        ListNode(int x) :
*              val(x), next(NULL) {
*        }
*  };
*/
struct ListNode {
        int val;
        struct ListNode *next;
        ListNode(int x) :
              val(x), next(NULL) {
        }
};
class Solution {
public:
    vector<int> printListFromTailToHead(ListNode* head) {
        vector<int> ret;
        if(head != NULL){
            ret = printListFromTailToHead(head->next);
            ret.push_back(head->val);
        }
        return ret;
    }
};