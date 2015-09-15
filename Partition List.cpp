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
    ListNode* partition(ListNode* head, int x) {
        ListNode left(-1);
        ListNode right(-1);
        ListNode *left_cur = &left;
        ListNode *right_cur = &right;
        while (head != nullptr){
            if (head -> val < x) {
                left_cur -> next = head;
                left_cur = left_cur -> next;
            }
            else{
                right_cur -> next = head;
                right_cur = right_cur -> next;
            }
            head = head -> next;
        }
        right_cur -> next = nullptr;
        left_cur -> next = right.next;
        return left.next;
    }
};
