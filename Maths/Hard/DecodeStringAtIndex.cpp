#include<bits/stdc++.h>
using namespace std;

/*
    Here's a walkthrough of how this solution works.

**Problem recap:** You have an encoded string `s` where letters mean "append this letter" and digits `d` mean 
"repeat everything built so far, `d` times total." You need to find the character at position `k` (1-indexed) in 
the fully decoded string, *without* actually building it 
(since it can get astronomically long).

### Pass 1: Compute total decoded length

```cpp
long long len=0;
for(int i=0;i<n;i++){
    if(isdigit(s[i])) len=len*(s[i]-'0');
    else len++;
}
```

This simulates building the string, but tracking only its **length**, not its content:
- A letter → length grows by 1.
- A digit `d` → whatever has been built so far gets repeated `d` times, so length gets multiplied by `d`.

By the end, `len` = total length of the fully decoded string. `long long` is needed because this can overflow a 
normal `int` fast (e.g. `"a100100100"` type inputs).

### Pass 2: Walk backwards to find position `k`

This is the clever part — instead of decoding forward, it "undoes" the string from the end, shrinking the 
search space until it lands exactly on the target index.

```cpp
for(int i=n-1;i>=0;i--){
    if(isdigit(s[i])){
        len=len/(s[i]-'0');
        k=k%len;
        if(!k) k=len;
    }
    else{
        if(len==k){
            res.push_back(s[i]);
            break;
        }
        len--;
    }
}
```

Think of `len` as "the length of the string *up through* the current point in the scan," and `k` as "which position (1-indexed) 
we're still hunting for within that shrinking string."

- **If `s[i]` is a digit `d`:** The string at this point was formed by repeating a shorter string (of length `len/d`) `d` times. So:
  - `len = len/d` shrinks back to that shorter base length.
  - `k = k % len` finds the equivalent position within *one copy* of that shorter string (since the repeats are identical copies).
  - The `if(!k) k=len;` handles the edge case where `k` lands exactly on a multiple — e.g., if `k` was the very last character of a 
    repeated block, `k % len` would give 0, but position 0 doesn't exist (1-indexed), so it should really mean 
    "the last character," i.e., `len`.

- **If `s[i]` is a letter:** This letter is the *last* character of the string as it stood at this point (length `len`). So:
  - If `len == k`, this letter *is* the answer — record it and stop.
  - Otherwise, this letter wasn't the one we wanted, so conceptually "remove" it: `len--` (the string one step earlier, 
  before this letter was appended, had length `len-1`).

### Why scan backwards?

Because undoing a repeat operation (`digit`) or an append operation (`letter`) 
is only meaningful in reverse — you're peeling off the most recent construction step each time, narrowing down where index `k` "really" 
points to, until you hit a letter that's directly sitting at position `k`.

### Complexity
- Time: O(n) for both passes.
- Space: O(1) extra (excluding output).

One thing worth double-checking: this assumes the input is well-formed (starts appropriately, no leading digit issues, etc.), 
which is guaranteed by the problem's constraints — so no extra validation is needed here.

*/

class Solution {
public:
    string decodeAtIndex(string s, int k) {
        long long len=0;
        int n=s.size();
        string res;
        for(int i=0;i<n;i++){
            if(isdigit(s[i])) len=len*(s[i]-'0');
            else len++;
        }
        for(int i=n-1;i>=0;i--){
            if(isdigit(s[i])){
                len=len/(s[i]-'0');
                k=k%len;
                if(!k) k=len;
            }
            else{
                if(len==k){
                    res.push_back(s[i]);
                    break;
                }
                len--;
            }
        }
        return res;
    }
};

int main(){

return 0;
}