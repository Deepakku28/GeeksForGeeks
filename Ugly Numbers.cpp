class Solution{
public:	
	// #define ull unsigned long long
	/* Function to get the nth ugly number*/
	ull getNthUglyNo(int n) {
	    ull dp[10001];
	    dp[0]=1;
	    int index2=0,index3=0,index5=0;
	    ull val2=2,val3=3,val5=5;
	    for(int i=1;i<n;i++){
	        ull val=min({val2,val3,val5});
	        dp[i]=val;
	        if(val2==val){
	            index2++;
	            val2=2*dp[index2];
	        }
	        if(val3==val){
	            index3++;
	            val3=3*dp[index3];
	        }
	        if(val5==val){
	            index5++;
	            val5=5*dp[index5];
	        }
	    }
	    return dp[n-1];
	}
};
