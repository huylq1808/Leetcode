## Problem: Find Closest Palindrome

Given a string `n` representing a positive integer, the goal is to find the closest palindrome number to `n`. If there are two palindrome numbers equally close, return the smaller one.

### Example

- **Input:** `n = "123"`
- **Output:** `"121"`

### Explanation

A palindrome number is a number that remains the same when its digits are reversed. For the given input, the closest palindrome to `123` is `121`.

## Solution Approach

The solution involves the following steps:

1. **Handling Edge Cases:** 
   - If the length of `n` is 1 (i.e., single-digit numbers), the closest palindrome is `n-1`.
   - Handle special cases like the smallest and largest possible palindrome numbers for the given length.

2. **Generating Palindrome Candidates:**
   - Generate potential palindrome candidates by manipulating the prefix of the number. 
   - Consider the prefixes `(prefix, prefix + 1, prefix - 1)` and create palindromes from these prefixes.

3. **Compare Candidates:**
   - Calculate the absolute difference between `n` and each palindrome candidate.
   - Track the candidate with the smallest difference.
   - If two candidates have the same difference, choose the smaller numerical value.

4. **Return the Result:**
   - Return the closest palindrome as a string.

## Pseudocode

> 1. Initialize a list to store palindrome candidates.  
> 2. Calculate the length of n and identify the middle point.  
> 3. Add edge cases for palindromes of different lengths to the candidates list.  
> 4. Extract the prefix of n and generate palindromes using (prefix, prefix + 1, prefix - 1).   
> 5. Iterate over each candidate: a. Calculate the difference with n. b. Update the closest palindrome if the difference is smaller. c. If the difference is the same, select the smaller palindrome.  
> 6. Return the closest palindrome as a string.  

## Time and Space complexity 
- Time: O(len(n))
- Space: O(1)