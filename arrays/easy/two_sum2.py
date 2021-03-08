class Solution:
    def twoSum(self, numbers, target):

        for i in range(len(numbers)):
            match = target - numbers[i]
            j =  bs(match, numbers, i+1, len(numbers)-1)
            if j is not None:
                return [i+1, j+1]




def bs(n, arr, start, end):
    middle = round((start + end) / 2)

    if start > end or (start == end and arr[middle] != n):
        return None

    if arr[middle] < n:
        return bs(n, arr, middle+1, end)
    elif arr[middle] > n:
        return bs(n, arr, start, middle-1)

    return middle
