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
    ListNode* swapPairs(ListNode* head) {
        if (head == nullptr || head -> next == nullptr) return head;
        ListNode dummy(-1);
        dummy.next = head;
        for (ListNode *prev = &dummy, *cur = head, *next = head -> next;
        cur != nullptr && next != nullptr;
        prev = cur, cur = cur -> next, next = cur != nullptr ? cur -> next : nullptr){
            cur -> next = next -> next;
            prev -> next = next;
            next -> next = cur;
            
        }
        return dummy.next;
    }
};
