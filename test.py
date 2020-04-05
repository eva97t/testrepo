
if st[endIndex] == st[startIndex] 
  dp[startIndex][endIndex] = 2 + dp[startIndex + 1][endIndex - 1]
else 
  dp[startIndex][endIndex] = Math.max(dp[startIndex + 1][endIndex], dp[startIndex][endIndex - 1])

  
