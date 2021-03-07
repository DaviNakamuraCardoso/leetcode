class Solution:
    def twoSum(self, nums, target):
        for i in range(len(nums)):
            second = target - nums[i]
            in_list = bs(second, sorted(nums[i:]), i, len(nums)-1)
            if in_list:
                j = len(arr[:i+1]) + index(second, arr[i:])

                return [i, j]

        return None


def bs(n, arr, start, end):

    middle = (start + end) / 2

    if start > end or (start == end and arr[middle] != n):
        return False

    if arr[middle] < n:
        return bs(n, arr, middle+1, end)
    elif arr[middle] > n:
        return bs(n, arr, start, middle-1)

    return middle

def index(n, arr):
    for i in range(len(arr)):
        if arr[i] == n:
            return i




def main():
    s = Solution()
    print(s.twoSum([3, 2, 4], 6))

if __name__ == '__main__':
    main()
