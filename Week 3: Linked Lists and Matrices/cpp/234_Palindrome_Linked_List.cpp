class Solution {
    public:
        bool isPalindrome(ListNode* head) {
            if (!head || !head->next) return true; // A single node or empty list is always a palindrome

            // Step 1: Find the middle of the linked list
            ListNode* slow = head;
            ListNode* fast = head;
            while (fast && fast->next) {
                slow = slow->next;
                fast = fast->next->next;
            }
            
            // Step 2: Reverse the second half of the list
            ListNode* prev = nullptr;
            ListNode* current = slow;
            while (current) {
                ListNode* temp = current->next;
                current->next = prev;
                prev = current;
                current = temp;
            }

            // Step 3: Compare the first half and the reversed second half
            ListNode* left = head; // Start of the first half
            ListNode* right = prev; // Start of the reversed second half
            while (right) {
                if (left->val != right->val) {
                    return false; // Values don't match, not a palindrome
                }
                left = left->next;
                right = right->next;                    
            }            
            return true;
        }
    };
