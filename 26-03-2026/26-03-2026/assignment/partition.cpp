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

// Function to insert node at end
ListNode* insert(ListNode* head, int val) {
    if (head == nullptr) return new ListNode(val);

    ListNode* temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }
    temp->next = new ListNode(val);
    return head;
}

// Function to print list
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

    // Example input: 1 4 3 2 5 2
    int arr[] = {1, 4, 3, 2, 5, 2};
    int n = 6;

    for (int i = 0; i < n; i++) {
        head = insert(head, arr[i]);
    }

    cout << "Original List: ";
    printList(head);

    int x = 3;

    Solution obj;
    head = obj.partition(head, x);

    cout << "Partitioned List around " << x << ": ";
    printList(head);

    return 0;
}