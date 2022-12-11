class Solution:
    def licenseKeyFormatting(self, s: str, k: int) -> str:
      # Convert all letters to uppercase.
      s1 = s.upper()
      # Remove all dashes.
      s2 = s1.replace("-", "")
      # Reverse the string (and then reverse it again later)
      # so that all groups contain exactly k elements, 
      # except for the first group which can
      # contain less than k elements.
      s3 = "".join(reversed(s2))
      # Break the string into groups of k elements.
      s4 = [s3[i: i + k] for i in range(0, len(s3), k)]
      # Join the string with dashes between groups.
      s5 = "-".join(s4)
      # Reverse the string again to restore the original order.
      s6 = "".join(reversed(s5))
      return s6
