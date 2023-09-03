

#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
        unordered_map<string, long long> memo;
        unordered_map<char, long long> cnt;
        map<int, int> maxcul;
        int modi = 1e9+7;
        int findMax(string& s,string& sub ,int k, int ind, long long sum, unordered_map<char,int>& mp) {
            if (memo.find(sub) != memo.end()) {
                    maxcul[memo[sub]%modi]++;
                    return memo[sub]%modi;
            }
            if (k == 0) {
                maxcul[sum%modi]++;
                return memo[sub]=sum%modi;
            }
            if (ind == s.size()) {
                return INT_MIN; 
            }
            int includeCurrent = 0;
            if(!mp[s[ind]]){
                mp[s[ind]]++;
                sub+=s[ind];
                int tsum = (sum+cnt[s[ind]])%modi;
                includeCurrent = findMax(s,sub, k - 1, ind + 1, tsum,mp);
                mp[s[ind]]--;
                sub.pop_back();
            }

            int excludeCurrent = findMax(s,sub, k, ind + 1, sum, mp);
            return max(includeCurrent, excludeCurrent);
        }
        int countKSubsequencesWithMaxBeauty(string s, int k) {
            for(auto x:s){
                cnt[x]++;
            }
            unordered_map<char, int> mp;
            string as="";
            int c =  findMax(s,as,k,0,0ll,mp);
            if(c==INT_MIN)return 0;
            auto it = maxcul.rbegin();
            if(it->first==0)return 0;
            return it->second;
        }
};
int main() {
    #ifndef ONLINE_JUDGE
 
    // For getting input from input.txt file
    freopen("input.txt", "r", stdin);
 
    // Printing the Output to output.txt file
    freopen("output.txt", "w", stdout);
 
    #endif
    string s;
    cin>>s;
    int n;
    cin>>n;
    Solution sol ;
    cout<<sol.countKSubsequencesWithMaxBeauty(s,n);
    return 0;
}
