class Solution {
    public int minimumLength(String s) {
        int n  = s.length();

        int[] freq = new int[26];
        for(char ch : s.toCharArray()){
            freq[ch-'a'] += 1;
        }
        int result = 0;
        for(int i=0;i<26;i++){
            if(freq[i]==0) continue;
            if(freq[i]%2==0) result+=2;
            else result += 1;
        }
        return result;
    }
}