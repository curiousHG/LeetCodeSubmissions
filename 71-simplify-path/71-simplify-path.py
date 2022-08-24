class Solution:
    def simplifyPath(self, path: str) -> str:
        arr = path.split('/')
        ans = []
        for i in range(len(arr)):
            if(arr[i]==".."):
                if(len(ans)):
                    ans.pop()
            elif(arr[i]==''or arr[i]=='.'):
                continue
            else:
                ans.append(arr[i])
        return "/"+"/".join(ans)
        