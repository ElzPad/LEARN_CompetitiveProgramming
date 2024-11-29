/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 */
int guess(int num);

int guessNumber(int n){
    int min = 0, max = n;
    int num = min+(max-min)/2;
    int ans = 0;

	  while (ans = guess(num)) {
        if (ans==1) {
            min = num+1;
        } else {
            max = num-1;
        }
        num = min+(max-min)/2;
    }
    return num;
}