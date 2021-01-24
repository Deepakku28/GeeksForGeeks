class Solution{
	public:
	int minDiffernce(int arr[], int n) {
	    int totalSum=0;
	    for(int i=0;i<n;i++){
	        totalSum+=arr[i];
	    }
	    int target=totalSum/2;
	    vector<vector<bool>> dp(n+1,vector<bool>(target+1,false));
	    for(int i=0;i<=n;i++){
	        for(int j=0;j<=target;j++){
	            if(i==0 && j==0){
	                dp[i][j]=true;
	            }
	            else if(i==0){
	                dp[i][j]=false;
	            }
	            else if(j==0){
	                dp[i][j]=true;
	            }
	            else if(arr[i-1]<=j){
	                dp[i][j]=dp[i-1][j]||dp[i-1][j-arr[i-1]];
	            }
	            else{
	                dp[i][j]=dp[i-1][j];
	            }
	        }
	    }
	    int firstSum=0;
	    for(int j=target;j>=0;j--){
            if(dp[n][j]==true){
                firstSum=j;
                break;
            }
        }
        int secondSum=totalSum-firstSum;
        return abs(secondSum-firstSum);
	}
};
