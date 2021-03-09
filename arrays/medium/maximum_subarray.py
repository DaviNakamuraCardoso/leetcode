class Solution():
    def maxProduct(self, nums):

        if len(nums) == 1:
            return nums[0]
            
        subs = split(nums)
        max = -9999999999
        for sub in subs:
            c = count(sub)
            r = 0
            if c % 2 == 0:
                r = mult(sub)

            else:
                r = shuffle(sub, c)

            max = max if max > r else r
        return max



def shuffle(arr, c):
    l = 0
    first = 0
    second = 0
    index = 0

    while l < c:
        if arr[index] < 0:
            l += 1
        if l < c:
            first = plus_equal(first, arr[index])

        index += 1

    index = 0
    for i in range(len(arr)):
        if index > 0:
            second = plus_equal(second, arr[i])

        elif arr[i] < 0:
            index = 1
    r = first if first > second else second

    return r


def count(arr):
    c = 0
    for n in arr:
        if n < 0:
            c += 1
    return c

def mult(arr):
    r = 0
    for a in arr:
        r = plus_equal(r, a)
    return r


def split(nums):
    r = []
    a = []
    for n in nums:
        if n == 0:
            r.append(a)
            a = [0]
        else:
            a.append(n)

    r.append(a)
    return r

def plus_equal(a, b):
    if a == 0:
        return b

    return a*b
