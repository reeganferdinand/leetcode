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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int size=0;

        ListNode *temp=head;

        while(temp!=nullptr)
        {
            size++;
            temp=temp->next;
        }
        temp=head;

        if(size-n==0) return head->next;
        for(int i=1;i<size-n;i++)
        {
            temp=temp->next;
        }

        if(temp->next!=nullptr)temp->next=temp->next->next;
        else temp->next=nullptr;

        return head;


    }
};