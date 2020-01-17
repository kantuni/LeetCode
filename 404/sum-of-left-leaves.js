/**
 * Definition for a binary tree node.
 * function TreeNode(val) {
 *   this.val = val;
 *   this.left = this.right = null;
 * }
 */

/**
 * @param {TreeNode} root
 * @return {number}
 */
const sumOfLeftLeaves = root => {
  if (root === null) {
    return 0
  }
  const left = isLeaf(root.left) ? root.left.val : sumOfLeftLeaves(root.left)
  const right = sumOfLeftLeaves(root.right)
  return left + right
}

const isLeaf = node => (
  node !== null && 
  node.left === null && 
  node.right === null
)
