/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// credit: http://blog.csdn.net/zhiyu27/article/details/8197796
class Comp{
  public:
    bool operator()(ListNode* a,ListNode* b){
      // return true, swap
      // else, keep same
      if(!a)
        return true;
      if(!b)
        return false;
      return a->val > b->val;
    }
};

// O(n logk), n is all elements in all lists
ListNode *mergeKLists(vector<ListNode *> &lists) {
  ListNode *head = NULL, *curr = NULL;
  if(lists.empty())
    return NULL;
  make_heap(lists.begin(),lists.end(),Comp());
  while(lists.front()){
    if(!head){
      head=lists.front();
      curr=head;
    }else{
      curr->next=lists.front();
      curr=curr->next;
    }
    pop_heap(lists.begin(),lists.end(),Comp());
    lists.back()=curr->next;
    curr->next=NULL;
    push_heap(lists.begin(),lists.end(),Comp());
  }
  return head;
}

