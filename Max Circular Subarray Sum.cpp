int circularSubarraySum(int arr[], int n){
    int maxSum=arr[0];
    int currMaxSum=0;
    int totalSum=0;
    for(int i=0;i<n;i++){
        currMaxSum+=arr[i];
        maxSum=max(maxSum,currMaxSum);
        currMaxSum=max(currMaxSum,0);
        totalSum+=arr[i];
    }
    if(maxSum<0){
        return maxSum;
    }
    int minSum=arr[0];
    int currMinSum=0;
    for(int i=0;i<n;i++){
        currMinSum+=arr[i];
        minSum=min(minSum,currMinSum);
        currMinSum=min(currMinSum,0);
    }
    return max(maxSum,totalSum-minSum);
}
