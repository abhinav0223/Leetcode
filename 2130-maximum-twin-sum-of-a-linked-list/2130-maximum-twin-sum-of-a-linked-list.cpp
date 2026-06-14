class Solution {
public:
    int pairSum(ListNode* head) {

        ListNode* slow = head;
        ListNode* fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
    
        ListNode* prev = nullptr;
        ListNode* curr = slow;
        while (curr) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
    
        int maxSum = 0;
        ListNode* left = head;
        ListNode* right = prev;
        while (right) {
            maxSum = max(maxSum, left->val + right->val);
            left = left->next;
            right = right->next;
        }

        return maxSum;
    }
};