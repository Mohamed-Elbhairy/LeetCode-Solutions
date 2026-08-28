/*
 * Problem Name: Delete The Middle Node Of A Linked List
 * Problem Link: https://leetcode.com/problems/delete-the-middle-node-of-a-linked-list/
 */

class Solution {
public:
    ListNode* deleteMiddle(ListNode* head){
        if (!head||!head->next) return nullptr;
        vector<ListNode*>nodes;
        ListNode* temp=head;
        while(temp){
            nodes.push_back(temp);
            temp=temp->next;
        }
        int mid=nodes.size()/2;
        nodes[mid-1]->next=nodes[mid]->next;
        delete nodes[mid];
        return head;
    }
};
