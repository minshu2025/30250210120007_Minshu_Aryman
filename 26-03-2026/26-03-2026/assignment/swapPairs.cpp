#include <iostream>
using namespace std;

// Definition of ListNode
struct ListNode {
    int val;
    ListNode* next;

    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

// Solution class
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        ListNode* prev = dummy;

        while (prev->next != nullptr && prev->next->next != nullptr) {
            ListNode* first = prev->next;
            ListNode* second = prev->next->next;

            // Swap
            first->next = second->next;
            second->next = first;
            prev->next = second;

            // Move forward
            prev = first;
        }

        return dummy->next;
    }
};

// Insert node at end
ListNode* insert(ListNode* head, int val) {
    if (head == nullptr) return new ListNode(val);

    ListNode* temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }
    temp->next = new ListNode(val);
    return head;
}

// Print list
void printList(ListNode* head) {
    while (head != nullptr) {
        cout << head->val << " -> ";
        head = head->next;
    }
    cout << "NULL" << endl;
}

// Main function
int main() {
    ListNode* head = nullptr;

    // Example input
    int arr[] = {1, 2, 3, 4};
    int n = 4;

    for (int i = 0; i < n; i++) {
        head = insert(head, arr[i]);
    }

    cout << "Original List: ";
    printList(head);

    Solution obj;
    head = obj.swapPairs(head);

    cout << "After Swapping Pairs: ";
    printList(head);

    return 0;
}