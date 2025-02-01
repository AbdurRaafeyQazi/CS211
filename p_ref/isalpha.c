#include <stdio.h>
#include <ctype.h>

int main(void)
{
  // The alphabetic characters are the characters: A-Z a-z
  //
  // All other characters are not alphabetic characters.
  
  // Try modifying what char c is set to and see the result!
  char c = 'T';
  
  if (isalpha(c))
  {
    printf("%c is an alphabetic character\n", c);
  }
  else
  {
    printf("%c is not an alphabetic character\n", c);
  }
  
  return 0;
}