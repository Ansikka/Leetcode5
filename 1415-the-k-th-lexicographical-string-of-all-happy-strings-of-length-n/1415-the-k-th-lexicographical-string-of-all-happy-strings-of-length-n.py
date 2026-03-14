class Solution:
    def getHappyString(self, n: int, k: int) -> str:
        """
        Generate the k-th lexicographically smallest happy string of length n.
        A happy string is a string where no two adjacent characters are the same.
      
        Args:
            n: Length of the happy string
            k: The k-th smallest happy string to return
          
        Returns:
            The k-th happy string, or empty string if less than k happy strings exist
        """
        def backtrack(current_string: list[str], result_list: list[str]) -> None:
            """
            Use backtracking to generate all valid happy strings in lexicographical order.
          
            Args:
                current_string: Current string being built
                result_list: List to store all valid happy strings
            """
            # Base case: if we've built a string of length n, add it to results
            if len(current_string) == n:
                result_list.append("".join(current_string))
                return
          
            # Optimization: stop early if we already have k strings
            if len(result_list) >= k:
                return
          
            # Try each character 'a', 'b', 'c' in lexicographical order
            for char in "abc":
                # Only add the character if it's different from the last character
                # (or if the string is empty)
                if not current_string or current_string[-1] != char:
                    # Add character and explore
                    current_string.append(char)
                    backtrack(current_string, result_list)
                    # Backtrack: remove the character to try other options
                    current_string.pop()
      
        # Initialize empty lists for building strings and storing results
        all_happy_strings = []
        current_build = []
      
        # Generate happy strings using backtracking
        backtrack(current_build, all_happy_strings)
      
        # Return the k-th string (1-indexed) or empty string if not enough strings exist
        return "" if len(all_happy_strings) < k else all_happy_strings[k - 1]