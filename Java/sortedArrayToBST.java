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
    public TreeNode sortedArrayToBST(int[] num) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        return sortedArrayToBSTHelper(num, 0, num.length - 1);
    }
    
    private TreeNode sortedArrayToBSTHelper(int[] num, int begin, int end)
    {
        if (begin > end)
	    {
		return null;
	    }
        
        int mid = (end - begin) / 2 + begin;
        TreeNode root = new TreeNode(num[mid]);
        root.left = sortedArrayToBSTHelper(num, begin, mid - 1);
        root.right = sortedArrayToBSTHelper(num, mid + 1, end);
        return root;
    }
}