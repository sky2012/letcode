/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; next = null; }
 * }
 */
/**
 * Definition for binary tree
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
public class Solution {
    public TreeNode sortedListToBST(ListNode head) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        int len = getListLength(head);
        
        return sortedListToBSTHelper(head, 0, len - 1);
    }
    
    private TreeNode sortedListToBSTHelper(ListNode head, int begin, int end)
    {
        if (begin > end)
	    {
		return null;
	    }
        
        int mid = (end - begin) / 2 + begin;
        
        TreeNode left = sortedListToBSTHelper(head, begin, mid - 1);
        TreeNode root = new TreeNode(head.val);
        root.left = left;
        head = head.next;
        root.right = sortedListToBSTHelper(head, mid + 1, end);
        
        return root;
    }  
    
    private int getListLength(ListNode head)
    {
        if (head == null)
	    {
		return 0;
	    }
        
        int len = 0;
        ListNode current = head;
        while (current != null)
	    {
		current = current.next;
		len++;
	    }
        
        return len;
    }
}