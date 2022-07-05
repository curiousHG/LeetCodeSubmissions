class Solution(object):
    def plusOne(self, digits):
        """
        :type digits: List[int]
        :rtype: List[int]
        """
        n = len(digits)
        i = n-1
        carry = False
        while(i>-1):
            if(digits[i]+1<10):
                digits[i]+=1
                return digits
            else:
                digits[i] = 0
                i-=1
                carry = True
        if(carry):
            digits.insert(0,1)
        return digits
        