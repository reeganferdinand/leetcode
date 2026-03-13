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


    ListNode* func(ListNode *root)
    {
        ListNode* temp=nullptr;
        ListNode *prev=nullptr;
        ListNode *curr=root;

        while(curr!=nullptr)
        {
            temp=curr->next;
            curr->next=prev;
            prev=curr;
            curr=temp;
        }

        return prev;
    }

public:
    bool isPalindrome(ListNode* head) {
        ListNode* slow=head,*fast=head;


        while(fast!=nullptr && fast->next!=nullptr)
        {
            slow=slow->next;
            fast=fast->next->next;
        }

        ListNode *newhead=func(slow);

        slow=head;
        fast=newhead;

        while(slow!=nullptr && fast!=nullptr)
        {
            if(slow->val!=fast->val) return false;
            slow=slow->next;
            fast=fast->next;
        }

        return true;
    }
};