class Solution:
    def subsets(self, nums: List[int]) -> List[List[int]]:
        if len(nums) == 1:
          return [[], nums]
        
        head, *tail = nums
        subtail = self.subsets(tail)
        subhead = [[head, *val] for val in subtail]
        return [*subtail, *subhead]
