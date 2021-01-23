//https://practice.geeksforgeeks.org/problems/binary-representation5003/1#
class Solution{
public:
    string getBinaryRep(int N){
        string ans="";
        for(int i=29;i>=0;i--){
            ans+=to_string((N>>i)&1);
        }
        return ans;
    }
};
