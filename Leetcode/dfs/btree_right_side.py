from collections import deque


class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def rightSideView(self, root: Optional[TreeNode]) -> List[int]:
        res = []
        queue = deque()
        queue.append(root)
        if root is None:
            return []

        while queue:
            child_q = deque()
            prev = -1
            while queue:
                cur = queue.popleft()
                if cur.left is not None:
                    child_q.append(cur.left)
                if cur.right is not None:
                    child_q.append(cur.right)
                prev = cur

            res.append(prev.val)
            queue = child_q

        return res
