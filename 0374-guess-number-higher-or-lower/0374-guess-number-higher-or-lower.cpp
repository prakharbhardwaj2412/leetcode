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
        unsigned int low=0, high=n;
        unsigned int mid=(low+high)/2;
        while(guess(mid)!=0) {
            if(guess(mid) == 1) {
                low=mid+1;
                mid=(low+high)/2;
            } else if(guess(mid) == -1) {
                high=mid-1;
                mid=(low+high)/2;
            }
        }
        return mid;
        
    }
};