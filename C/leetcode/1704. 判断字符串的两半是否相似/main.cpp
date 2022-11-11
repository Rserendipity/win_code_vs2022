#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool halvesAreAlike(string s) {
        //                      a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,q,r,s,t,u,v,w,x,y,z
        const char leter[26] = { 1,0,0,0,1,0,0,0,1,0,0,0,0,0,1,0,0,0,0,0,1,0,0,0,0,0 };
        int sz = s.size() / 2;
        int count_left = 0;
        int count_right = 0;

        for (int i = 0; i < sz; i++) {
            if (leter[tolower(s[i]) - 'a'] == 1) {
                count_left++;
            }
        }
        for (int i = sz; i < sz * 2; i++) {
            if (leter[tolower(s[i]) - 'a'] == 1) {
                count_right++;
            }
        }
        return count_right == count_left;
    }
};
int main()
{
	return 0;
}