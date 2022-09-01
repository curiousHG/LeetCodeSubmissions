class Solution:
    def reverseWords(self, s: str) -> str:
        arr = s.strip().split(" ");
        arr.reverse()
        final = []
        for c in arr:
            if c!='':
                final.append(c)
                
        return " ".join(final)
        