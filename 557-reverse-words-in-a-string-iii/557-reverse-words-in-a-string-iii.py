class Solution:
    def reverse(self,string):
        string = "".join(reversed(string))
        return string
    def reverseWords(self, s: str) -> str:
        arr = s.split(' ')
        for i in range(len(arr)):
            arr[i] = self.reverse(arr[i])
        return " ".join(arr)