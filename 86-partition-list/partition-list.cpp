class Solution {
 public:
 ListNode* partition(ListNode* head, int x) {
    ListNode* temp = head  ; 

    //Creating 2 LinkedLists 
    ListNode* left = new ListNode(0);
    ListNode* right = new ListNode(0) ; 

    //using 2 nodes to point head
    ListNode* dummy1 = left  ;
    ListNode* dummy2 = right ; 

    while(temp!=NULL){
        //if the value at temp is less than x, we've stored the value in dummy 1, and stored in dummy2 if temp is greater than x;
        if(temp->val < x){
            dummy1->next = temp ; 
            dummy1 = dummy1->next ;     
         }
        else {
            dummy2->next = temp ; 
            dummy2 = dummy2->next ; 
            
        }
        temp = temp->next ; 
    }
    dummy1->next = right->next ; 
    dummy2->next = NULL;
    
    return left->next ; 
}
};