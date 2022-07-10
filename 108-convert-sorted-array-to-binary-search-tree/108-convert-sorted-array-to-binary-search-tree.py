# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def sortedArrayToBST(self, nums: List[int]) -> Optional[TreeNode]:
        n = len(nums)
        if(n==0):
            return None
        mid = n//2
        tnode = TreeNode(nums[mid])
        left = nums[0:mid]
        right = nums[mid+1:]
        left_t = self.sortedArrayToBST(left)
        right_t = self.sortedArrayToBST(right)
        tnode.left = left_t
        tnode.right = right_t
        return tnode
        
        
    
        