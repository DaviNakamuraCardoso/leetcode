from math import floor 

class Solution: 
    def reverse(self, x): 
        """Given and integer x, returns the reverse number"""
        # Constraints
        if x < -2**31 or x > 2**31 - 1: 
            return 0 
        
        integer_string = str(x)
        integer_len = len(integer_string)

        reversed_integer = [a for a in integer_string]

        max = floor(integer_len / 2)
        for n in range(max): 
            tmp = reversed_integer[n]
            reversed_integer[n] = reversed_integer[integer_len-n-1]
            reversed_integer[integer_len-n-1] = tmp 

        
        return int("".join(reversed_integer))


def main(): 
    s = Solution()

    print(s.reverse(120))
    

if __name__ == '__main__': 
    main()
