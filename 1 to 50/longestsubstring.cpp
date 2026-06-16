/*   to find the longest substring without repeating the approaches are:
1.hum ye kar sakte hai ki hum ek set banaye aur usme characters ko push kre jab tak koi character repeat na ho jaye. Jab koi character repeat ho jaye to hum set se characters ko pop krte jaye jab tak wo character set me na aa jaye. Is approach ka time complexity O(n^2) hoga kyunki worst case me hum har character ke liye set me se characters ko pop krna padega.
2. best approach-- hum ek map banaye aur usme characters ko push kre jab tak koi character repeat na ho jaye. Jab koi character repeat ho jaye to hum map me se us character ke index ko le kar uske baad ke characters ko map me se delete krte jaye jab tak wo character map me na aa jaye. Is approach ka time complexity O(n) hoga kyunki hum har character ke liye map me se characters ko delete krna padega.
3. approach 3-- hum ek sliding window technique ka use kr sakte hai jisme hum do pointers banaye aur unhe start me 0 pe rakhe. Hum right pointer ko move krte jaye jab tak koi character repeat na ho jaye. Jab koi character repeat ho jaye to hum left pointer ko move krte jaye jab tak wo character repeat na ho jaye. Is approach ka time complexity O(n) hoga kyunki hum har character ke liye pointers ko move krna padega.

*/
//sliding window approach
Class Solution{
    public:
    int lengthofLongestSubstring(string s){
        int n=s.size();
        int ans=0;
        unordered_map<char,int> mp;
        for(int i=0,j=0;i<n;i++){
            if(mp.find(s[i])!=mp.end()){
                j=max(mp[s[i]]+1,j); //soch ye kyu kiya hoga? kyunki hum j pointer ko us character ke index ke baad pe le ja rahe hai taki wo character repeat na ho jaye
            }
            mp[s[i]]=i;
            ans=max(ans,i-j+1);
        }
        return ans; //soch ye kyu kiya hoga? kyunki hum ans me longest substring ka length store kar rahe hai aur i-j+1 se hum current substring ka length nikal rahe hai
    }
}