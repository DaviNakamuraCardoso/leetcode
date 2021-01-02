class Solution: 
    def reverse(self, x): 
        """Given and integer x, returns the reverse number"""
        # Constraints
        if x < -2**31 or x > 2**31 - 1: 
            return 0 
        
        integer_string = str(x)
        integer_len = len(x)
         
        for n in range(integer_len / 2): 
            tmp = integer_string[n]
            integer_string[n] = integer_string[integer_len-n-1]
            integer_string[integer_len-n-1] = tmp
        
        return int(integer_string)



def main(): 
    s = Solution()

    print(s.reverse(123))
    

if __name__ == '__main__': 
    main()
