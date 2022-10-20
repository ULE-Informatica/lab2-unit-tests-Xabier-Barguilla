#include <math.h>
#include <limits.h>
#include <stdio.h>
#include <stdint.h> 

unsigned int wrapFunctionAdd(unsigned int ui_a, unsigned int ui_b) {
  unsigned int usum = -1;
  /*INT30-C. Ensure that unsigned integer operations do not wrap*/
  if (UINT_MAX - ui_a < ui_b) {
    printf("Error: Function overflow");
  } else {
    usum = ui_a + ui_b;
  }
  return usum;
}

unsigned int wrapFunctionMul(unsigned int ui_a, unsigned int ui_b) {
  unsigned umul = -1;
  /*INT30-C. Ensure that unsigned integer operations do not wrap*/
  if(ui_a > UINT_MAX / ui_b) {
    printf("Error: Function overflow");
  }
  else {
    umul = ui_a*ui_b;
  }
  return umul;
  
}


unsigned int wrapFunctionShift(unsigned int ui_a, unsigned int ui_b) {
  /*INT34-C. Do not shift an expression by a negative number of bits or
   by greater than or equal to the number of bits that exist in the operand*/
  unsigned int uShift = 0;
  if (ui_b >= __builtin_popcount(UINT_MAX)) {
    /*Error in: Left Shift, Unsigned Type*/
    printf("Error: Function overflow, Left Shift");
  } else if ((32 - ui_b) >= __builtin_popcount(UINT_MAX)) {
    /*Error in: Right Shift*/
    printf("Error: Function overflow, Right Shift");
  }
   else {
    uShift = ui_a << ui_b | ui_a >> (32 - ui_b);
  }
  return uShift;

}