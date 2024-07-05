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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        ListNode* prev = head;
        ListNode* cur = head->next;
        vector<int> crits;
        int pos = 2;
        while(cur && cur->next){
            //crit
            if((cur->val<prev->val && cur->val<cur->next->val) || (cur->val>prev->val && cur->val>cur->next->val)){
                crits.push_back(pos);
            }
            prev = cur;
            cur = cur->next;
            pos++;
        }
        if(crits.size()<2){
            return {-1, -1};
        }
        int minDist = INT_MAX;
        for(int i = 1; i<crits.size(); i++){
            minDist = min(minDist, crits[i]-crits[i-1]);
        }
        return {minDist, crits.back()-crits[0]};

    }
};

