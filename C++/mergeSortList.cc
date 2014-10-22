/**
 * Definition for singly-linked list.
 * class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) {
 *         val = x;
 *         next = null;
 *     }
 * }
 */
public class Solution {
    public ListNode sortList(ListNode head) {
        if (head == null || head.next == null)
        {
            return head;
        }
        
        ListNode slow = head;
        ListNode fast = head;
        
        while (fast.next != null && fast.next.next != null)
        {
            slow = slow.next;
            fast = fast.next.next;
        }
        
        fast = slow.next;
        slow.next = null;
        
        slow = sortList(head);
        fast = sortList(fast);
        
        return mergeList(slow, fast);
    }
    
    public ListNode mergeList(ListNode l1, ListNode l2)
    {
        if (l1 == null)
        {
            return l2;
        }
        
        if (l2 == null)
        {
            return l1;
        }
        
        ListNode dummy = new ListNode(-1);
        ListNode tail = dummy;
        while (l1 != null && l2 != null)
        {
            if (l1.val < l2.val)
            {
                tail.next = l1;
                l1 = l1.next;
            }
            else
            {
                tail.next = l2;
                l2 = l2.next;
            }
            tail = tail.next;
        }
        
        tail.next = (l1 != null ? l1 : l2);
        return dummy.next;
    }
}
