class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        length = len(nums)
        answer = [1] * length

        left_product = 1
        for i in range(length):
            answer[i] = left_product
            left_product *= nums[i]

        right_product = 1
        for i in range(length - 1, -1, -1):
            answer[i] *= right_product
            right_product *= nums[i]

        return answer
