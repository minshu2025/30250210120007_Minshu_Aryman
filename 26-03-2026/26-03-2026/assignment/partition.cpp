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
    ListNode* partition(ListNode* head, int x) {
        ListNode* small = new ListNode(0);
        ListNode* higher = new ListNode(0);

        ListNode* smallHead = small;
        ListNode* higherHead = higher;

        while (head != nullptr) {
            if (head->val < x) {
                smallHead->next = head;
                smallHead = smallHead->next;
            } else {
                higherHead->next = head;
                higherHead = higherHead->next;
            }
            head = head->next;
        }

        higherHead->next = nullptr;
        smallHead->next = higher->next;

        return small->next;
    }
};
