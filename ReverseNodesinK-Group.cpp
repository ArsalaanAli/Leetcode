/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* phead = new ListNode();
        ListNode* mhead = new ListNode();
        ListNode* cur = head;
        while(true){
            ListNode* curHead = cur;
            //grab tail
            for(int i = 0; i<k; i++){
                if(!cur){
                    if(!mhead->next){
                        return head;
                    }
                    return mhead->next;
                }
                cur = cur->next;
            }
            ListNode* tail = cur;
            ListNode* prev = NULL;
            ListNode* next = NULL;
            cur = curHead;
            for(int i = 0; i<k; i++){
                next = cur->next;
                cur->next = prev;
                prev = cur;
                cur = next;
            }
            if(!mhead->next){
                mhead->next = prev;
            }
            phead->next = prev;
            phead = curHead;
            phead->next = cur;
        }
        return mhead->next;
        
    }
};