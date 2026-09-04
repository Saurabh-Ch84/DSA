#include <iostream>
#include <vector>
using namespace std;

int solve(vector<int> &arr, int n)
{
  long long sum = 0;
  for (int i = 0; i < n; i++)
    sum = sum + arr[i];
  int mod = 1e9 + 7;
  long long ans = 0;
  for (int i = 0; i < n; i++)
  {
    sum = ((sum - arr[i]) % mod + mod) % mod;
    ans = (ans + (sum * arr[i]) % mod) % mod;
  }
  return ans;
}

int main()
{
  int n;
  cin >> n;
  vector<int> arr(n);
  for (int i = 0; i < n; i++)
  {
    cin >> arr[i];
  }
  cout << solve(arr, n);
  return 0;
}