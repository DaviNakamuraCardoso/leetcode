
class Solution():

    def threeSum(self, nums):
        return n_sum(3, 0, sorted(nums))


def n_sum(n, target, arr):
    if n == 1:
        if target in arr:
            return [[target]]

    s = []

    for i in range(len(arr)):
        if arr[i] == arr[i-1] and i > 0:
            continue

        matches = n_sum(n-1, target-arr[i], arr[i+1:], sum_target)
        for match in matches:
            s.append([arr[i]] + match)

    return s
