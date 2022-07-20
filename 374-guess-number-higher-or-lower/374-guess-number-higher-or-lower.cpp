/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        long l = 1,r = n,mid,k;
        while(l<r){
            mid = (l+r)/2;
            k =guess(mid);
            if(k==0)return mid;
            else if(k<0)r = mid;
            else l = mid;
            if(l+1==r)break;
        }
        return guess(l)==0?l:r;
    }
};