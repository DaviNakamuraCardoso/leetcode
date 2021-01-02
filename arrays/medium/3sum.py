class Solution:
    def threeSum(self, nums):
        """Gets an array of ints and returns a array of 
        arrays whose sum is zero."""
        n = len(nums)
        # Initially, the results array is empty 
        results = [] 

        # Constraints 
        assert 0 <= n <= 3000
        for num in nums: 
            assert -10**5 <= num <= 10**5 

        # Looping over the given array
        for i in range(n): 

            for j in range(n): 

                for k in range(n): 
                    # Check for the sum 
                    if nums[i] + nums[j] + nums[k] == 0 and i != j and j != k and k != i: 
                        exists = False 
                        array = [nums[i], nums[j], nums[k]]

                        # Checks if this set of numbers already exists
                        if len(results) > 0: 
                            for result in results: 
                                matches = 0
                                indexes = []
                                for element in array: 
                                    for index in range(len(result)): 
                                        if element == result[index] and index not in indexes: 
                                            matches += 1 
                                            indexes.append(index)
                                            break 
                                
                                if matches > 2: 
                                    exists = True
                                

                        # If this set does not exist yet, append to the results array 
                        if not exists: 
                            results.append(array)

        return results  


def main(): 
    s = Solution()
    result0 = s.threeSum([0,3,0,1,1,-1,-5,-5,3,-3,-3,0])
    print(result0)


if __name__ == '__main__': 
    main()