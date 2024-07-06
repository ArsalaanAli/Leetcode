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
    ListNode* mergeNodes(ListNode* head) {
        ListNode* ans = new ListNode();
        ListNode* cur = ans;
        head = head->next;
        int sum = 0;
        while(head){
            if(!head->val){
                cur->next = new ListNode(sum);
                cur = cur->next;
                sum = 0;
            }
            sum+= head->val;
            head = head->next;
        }
        return ans->next;
    }
};

