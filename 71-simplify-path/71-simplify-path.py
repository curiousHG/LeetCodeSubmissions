class Solution:
    def simplifyPath(self, path: str) -> str:
        ans = []
        for i in path.split('/'):
            if(i==".."):
                if(len(ans)):
                    ans.pop()
            elif(i==''or i=='.'):
                continue
            else:
                ans.append(i)
        return "/"+"/".join(ans)
        