#include <iostream>
#include <vector>
#include <cmath>

using namespace std;


class Solution {
public:
    int totalVowels = 5;
    int n;
    int memo[20001][5];



    /*
     * a = 0;
     * e = 1;
     * i = 2;
     * o = 3;
     * u = 4;
     */
    int dp(int currentLetter, int lastLetter) {
        if(currentLetter == n) return 1;
        if(memo[currentLetter][lastLetter] != 0) return memo[currentLetter][lastLetter];

        if(lastLetter == 0) {
            memo[currentLetter][lastLetter] = dp(currentLetter+1, 1);
        } else if (lastLetter == 1) {
            memo[currentLetter][lastLetter] = dp(currentLetter+1, 0)+dp(currentLetter+1, 2);
        } else if (lastLetter == 2) {
            int permutations = 0;

            for(int x = 0; x < totalVowels; x++) {
                if(x == 2) continue;
                permutations += dp(currentLetter+1, x);
            }

            memo[currentLetter][lastLetter] = permutations;
        } else if(lastLetter == 3) {
            memo[currentLetter][lastLetter] = dp(currentLetter+1, 2)+dp(currentLetter+1, 4);
        } else if( lastLetter == 4) {
            memo[currentLetter][lastLetter] = dp(currentLetter+1, 0);
        }

        return memo[currentLetter][lastLetter];
    }

    int countVowelPermutation(int n) {
        this->n = n;
        int permutations = 0;

        for(int x = 0; x < totalVowels; x++) {
            permutations += dp(1, x);
        }

        return permutations;
    }
};