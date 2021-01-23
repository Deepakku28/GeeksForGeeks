//https://practice.geeksforgeeks.org/problems/palindromic-array-1587115620/1
/*Complete the function below*/
int helper(int a[],int &n){
    int ans=1;
    for(int i=0;i<n;i++){
        string str=to_string(a[i]);
        int start=0;
        int end=str.size()-1;
        while(start<=end){
            if(str[start]!=str[end]){
                return 0;
            }
            start++;
            end--;
        }
    }
    return ans;
}

int PalinArray(int a[], int n){
    return helper(a,n);
}
