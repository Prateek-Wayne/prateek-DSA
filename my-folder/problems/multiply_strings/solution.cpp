class Solution {
public:
   string multiply(string num1, string num2) {
        if(num1 == "0" or num2 == "0"){
            return "0";
        }
        int l1 = num1.size();
        int l2 = num2.size();
        vector<int> ans(l1+l2);
        int i = l2 - 1;
        int pf = 0;
        while(i >= 0){
            int j = l1-1;
            int carry = 0;
            int product = 1;
            int k = ans.size()-1-pf;
            while(j >= 0){
                product = ((num2[i] -'0')*(num1[j]-'0') + carry +ans[k])%10;
                carry = ((num2[i] -'0')*(num1[j]-'0') + carry +ans[k]) / 10;
                ans[k--] = product;
                j--;
            }
            ans[k--] = carry;
            pf++;
            i--;
        }
        string anss = "";
        int x = 0;
        while(ans[x] == 0){
            x++;
        }
        for(;x<ans.size();x++){
            anss += (ans[x] + '0');
        }
        return anss;
    }  
};