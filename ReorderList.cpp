class Solution {
public:
    void reorderList(ListNode* head) {
        
        //getting length
        ListNode* cur = head;
        int length = 0;
        while(cur!=NULL){
            cur = cur->next;
            length++;
        }
        if(length <=2){
            return;
        }

        //finding halfway
        cur = head;
        int half = ceil(length/2.0);
        for(int i = 0; i<half-1; i++){
            cur = cur->next;
        }

        ListNode* temp = cur->next;
        cur->next = NULL;
        cur = temp;
        //cur = first node in second half
        //reversing second half
        ListNode* prev = NULL;
        ListNode* next;
        while(cur!=NULL){
            next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }
        ListNode* second = prev;
        ListNode* first = head;
        cur = head;
        while(cur!=NULL){
            first = first->next;
            cur->next = second;
            cur = cur->next;
            if(cur == NULL){
                return;
            }
            second = second->next;
            cur->next = first;
            cur = cur->next;
        }

    }
};