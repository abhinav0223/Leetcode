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
struct compare {
    bool operator()(ListNode* a, ListNode* b) {
        return a->val > b->val; // min-heap
    }
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, compare> minHeap;

        // Push the head of each list into the heap
        for (auto l : lists) {
            if (l) minHeap.push(l);
        }

        ListNode dummy(0);
        ListNode* tail = &dummy;

        while (!minHeap.empty()) {
            ListNode* curr = minHeap.top();
            minHeap.pop();

            tail->next = curr;
            tail = tail->next;

            if (curr->next) {
                minHeap.push(curr->next);
            }
        }

        return dummy.next;
    }
};
