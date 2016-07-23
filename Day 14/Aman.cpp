package codingNinjas;

public class AssignmentDP {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		longestPalindromic("ABADAB");
	}

	//minimum ways to reach one
	public static int minWaysToReachOne(int num){
		if(num==1)
			return 0;
		if(num%3==0 && num%2==0)
			return 1+Math.min(minWaysToReachOne(num-1), Math.min((minWaysToReachOne(num/2)), minWaysToReachOne(num/2)));
		else if(num%2==0)
			return 1+Math.min(minWaysToReachOne(num-1), minWaysToReachOne(num/2));
		else if(num%3==0)
			return 1+Math.min(minWaysToReachOne(num-1), minWaysToReachOne(num/3));
		else 
			return 1+minWaysToReachOne(num-1);
	}
	//dp solution
	public static int minWaysToReachOneDP(int num){
		int[] arr = new int[num+1];
		arr[0] = 0;
		arr[1] = 0;
		for(int i=2; i<=num; i++){
			if(i%3==0 && i%2==0){
				arr[i]  = 1+Math.min(arr[i-1], Math.min(arr[i/3], arr[i/2]));
			}
			else if(i%2==0){
				arr[i] = 1+Math.min(arr[i-1], arr[i/2]);
			}
			else if(i%3==0){
				arr[i] = 1+ Math.min(arr[i-1], arr[i/3]);
			}
			else
				arr[i] = 1+ arr[i-1];
		}
		return arr[num];
	}

	//longest substring that is a palindrome
	public static String longestPalindromicSubstring(String str){
		int len = str.length();
		int start = 0;
		int end = 0;
		int[][] table = new int[len][len];
		//all single letters are palindromes
		for(int i=0; i<len; i++){
			table[i][i] = 1;
			start = i;
			end = i;
		}
		//fill for two letters
		for(int i=0; i<len-1; i++){
			for(int j=i+1; j<len; j++){
				if(str.charAt(i)==str.charAt(j)){
					table[i][j] = 1;
					start = i;
					end = j;
				}
				else
					table[i][j] = 0;
				break;
				
			}
			
		}
		int index = 2;
		while(index<len){
			for(int i=0; i<len-index; i++){
				for(int j = i+index; j<len; j++){
					if(str.charAt(i)==str.charAt(j)){
						if(table[i+1][j-1]==1){
							table[i][j] = 1;
							start = i;
							end = j;
						}
						else{
							table[i][j] = 0;
						}
					}else{
						table[i][j] = 0;
					}
					break;
				}
			}
			index++;
		}

		String ans = str.substring(start, end+1);
		return ans;
	}
	
	
	//coin change
	//recursion 
	public static int coinChange(int[] coins, int value, int n){
		if(value==0)
			return 0;
		if(n<=0 && value>0)
			return 0;
		if(coins[n-1]>value)
			return coinChange(coins, value, n-1);
		else
			return 1+Math.min(coinChange(coins, value-coins[n-1], n), coinChange(coins, value, n-1));
		
	}
	
	//01knapsack recursive
	public static int knapsackRecursive(int[] val, int[] wt, int W, int n){
		if(n==0||W==0)
			return 0;
		if(wt[n-1]>W)
			return knapsackRecursive(val, wt, W, n-1);
		else{
			return Math.max(val[n-1]+knapsackRecursive(val, wt, W-wt[n-1], n-1), knapsackRecursive(val, wt, W, n-1));
		}
	}
	
	//DP
	
	public static int knapsack(int[] val, int[] wt, int W, int n){
		int[][] table=  new int[W+1][n+1];
		for(int i=0; i<=W; i++){
			for(int j=0; j<=n; j++){
				if(i==0||j==0)
					table[i][j]=0;
				else if(wt[j-1]>i)
					table[i][j] = table[i][j-1];
				else
					table[i][j] = Math.max(val[j-1]+table[i-wt[j-1]][j-1], table[i][j-1]);
			}
		}
		return table[W][n];
	}
	
	//find largest square with all zeros
	public static int largestSquare(int[][] arr){
		int[][] temp = new int[arr.length][arr[0].length];
		int max = Integer.MIN_VALUE;
		for(int i=0; i<temp[0].length; i++){
			if(arr[0][i]==1)
				temp[0][i] = 0;
			else 
				temp[0][i] = 1;
		}
		for(int j=1; j<temp.length; j++){
			temp[j][0] = arr[j][0];
			if(arr[j][0]==1)
				temp[j][0] = 0;
			else
				temp[j][0] = 1;
			
		}
		for(int i=1; i<temp[0].length; i++){
			for(int j=1; j<temp.length; j++){
				if(arr[i][j]==0){
					temp[i][j] =1+ Math.min(temp[i][j-1], Math.min(temp[i-1][j], temp[i-1][j-1]));
					if(temp[i][j]>max)
						max = temp[i][j];
				}else{
					arr[i][j] = 0;
				}
			}
		}
		return max;
		
	}
	
	//subset that can be divided into two
	public static boolean checkSubset(int[] arr){
		int sum=0;
		for(int i=0; i<arr.length; i++){
			sum+=arr[i];
		}
		int half = sum/2;
		if(sum%2!=0)
			return false;
		else
			return subsetDP(arr, arr.length, half);
	}
	
	public static boolean subset(int[] arr, int n, int sum){
		if(sum==0 && n>=0)
			return true;
		if(sum>0&&n<=0)
			return false;
		if(arr[n-1]>sum)
			return subset(arr, n-1, sum);
		else
			return subset(arr, n-1, sum-arr[n-1]) || subset(arr, n-1, sum);
	}
	
	
	//dp
	
	public static boolean subsetDP(int[] arr, int n, int sum){
		boolean[][] table = new boolean[sum+1][n+1];
		for(int i=0; i<=n; i++){
			table[0][i] = true;
		}
		for(int j=1; j<=sum; j++){
			table[j][0] = false;
		}
		
		for(int i=1; i<=sum; i++){
			for(int j=1; j<=n; j++){
				if(arr[j-1]>i)
					table[i][j] =  table[i][j-1];
				else{
					table[i][j] =  table[i-arr[j-1]][j-1] || table[i][j-1];
				}
			}
		}
		if(table[sum][n]){
			printSubset(table, arr, sum,n);
			System.out.println();
		}
		return table[sum][n];
	}
	
	public static void printSubset(boolean[][] table, int[] arr, int i, int j){
		if(table[i][j]==false || i==0)
			return;
		if(table[i][j-1]==true)
			printSubset(table, arr, i, j-1);
		else{
			printSubset(table, arr, i-arr[j-1], j-1);
			System.out.print(arr[j-1]+ " ");
		}
	}
	
	//longest palindromic subsequence
	//find lcs of reverse
	
	public static void longestPalindromic(String str){
		String revStr = "";
		for(int i=str.length()-1; i>=0; i--){
			revStr = revStr+str.charAt(i);
		}
		int[][] table  = new int[str.length()+1][str.length()+1];
		for(int i=0; i<=str.length(); i++){
			for(int j=0; j<=str.length(); j++){
				if(i==0 || j==0){
					table[i][j] = 0;
				}
				else if(str.charAt(i-1)==revStr.charAt(j-1)){
						table[i][j] = 1+table[i-1][j-1];
					}
				else
					table[i][j] = Math.max(table[i][j-1], table[i-1][j]);
					
				}
			}
		int i=str.length();
		int j = str.length();
		String ans = "";
		while(i>0 && j>0){
			if(str.charAt(i-1)==revStr.charAt(j-1)){
				ans = str.charAt(i-1)+ans;
				i--;
				j--;
			}
			else if(table[i-1][j]>table[i][j-1])
				i--;
			else
				j--;
		}
		System.out.println(ans);
	}
	
	
	



}
