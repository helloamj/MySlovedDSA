class Solution {
  ListNode * cnt(ListNode * head, int & count) {
    ListNode * temp = head;
    while (temp -> next != NULL) {
      temp = temp -> next;
      count++;
    }
    return temp;
  }
  pair < ListNode * , ListNode * > rell(ListNode * head, ListNode * end) {
    end -> next = NULL;
    ListNode * curr = head;
    ListNode * temp = NULL;
    ListNode * prev = NULL;
    while (curr != NULL) {
      temp = curr -> next;
      curr -> next = prev;
      prev = curr;
      curr = temp;
    }
    return {
      prev,
      head
    };
  }
  public:
    ListNode * reverseKGroup(ListNode * head, int k) {
      if (k == 1) return head;
      int count = 0;
      ListNode * temp = cnt(head, count);
      if (k == count + 1) return rell(head, temp).first;
      temp = head;
      ListNode * past = NULL;
      ListNode * end = head;
      ListNode * hd = head;
      while (temp != NULL) {
        int n = k;
        while (n--) {
          temp = temp -> next;
          if (temp == NULL) break;
          if (n > 0) end = temp;
        }
        if (temp == NULL && n != 0) {
          past -> next = head;
          break;
        }

        if (!past)
          hd = rell(head, end).first;
        else
          past -> next = rell(head, end).first;
        past = head;
        head = temp;
      }
      return hd;
    }
};
