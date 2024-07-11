struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *result;
        result = head;
        while(head && head->next != NULL){
            if(head->val == head->next->val){
                int data = head->val;
                ListNode* temp;
                temp = head->next;
                while(temp && temp->val == head->val){
                    temp = temp->next;
                }
                head->next = temp;
                head = temp;
            }else{
                head = head->next;
            }
        }
        return result;
    }
};