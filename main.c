#include <stdio.h>      /* printf */
#include <string.h>     /* strcat */
#include <stdlib.h>
#include "hexlib.h"


// the point of this challenge is not to produce perfectly safe code, so
// I'm not going to test that the strings are actually of equal length OR
// extend the scope of what this could do to left-align unequal lenth strings for xor.

int main(void) {
  char hexstring1[] = "1c0111001f010100061a024b53535009181c";
  char hexstring2[] = "686974207468652062756c6c277320657965";

  int num_chars = strlen(hexstring1);
  int num_bytes = num_chars/2;
  int byte_arr1[num_bytes];
  int byte_arr2[num_bytes];
  int result[num_bytes];
  char result_string[num_chars];


  if (num_bytes != convert_hex_string_to_byte_array(hexstring1, num_chars, byte_arr1)) {
  	return -1;
  }
  if (num_bytes != convert_hex_string_to_byte_array(hexstring2, num_chars, byte_arr2)) {
  	return -1;
  }

  for (int i = 0; i < num_bytes; i++) {
  	result[i] = byte_arr1[i] ^ byte_arr2[i];
  }

  // need to deal with strcat here I think.
  char hexcharstr[3] = "";
  for (int i = 0; i < num_bytes; i++) {

    convert_int_to_hex_charstr(result[i],hexcharstr);
    strcat(result_string,hexcharstr);
  }

  printf("num_chars = %d, num_bytes = %d , result = %s\n", num_chars, num_bytes, result_string);

}
