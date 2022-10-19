class Solution {
public:
    //[Scan & Update]: maintain/update even/odd list and merge at end.
    //(time, space) = O(N) O(1)
    ListNode* oddEvenList(ListNode* head) {
        if(head) {
            auto odd = head, evenhead = head->next;
            for(auto even = evenhead; even && even->next; ) {
                odd = odd->next = even->next;
                even = even->next = odd->next;
            }
            odd->next = evenhead;
        }
        return head;
    }
};
