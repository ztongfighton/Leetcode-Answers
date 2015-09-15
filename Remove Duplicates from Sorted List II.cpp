/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == nullptr || head -> next == nullptr) return head;
        ListNode dummy(-1);
        dummy.next = head;
        ListNode *prev = &dummy;
        ListNode *cur = head;
        while (cur != nullptr){
            bool duplicate = false;
            while (cur -> next != nullptr && cur -> next -> val == cur -> val){
                duplicate = true;
                ListNode *tmp = cur;
                cur = cur -> next;
                delete tmp;
            }
            if (duplicate){
                ListNode *tmp = cur;
                cur = cur -> next;
                delete tmp;
                continue;
            }
            
            prev -> next = cur;
            prev = cur;
            cur = cur -> next;
        }
        prev -> next = cur; 
        return dummy.next;
    }
};
