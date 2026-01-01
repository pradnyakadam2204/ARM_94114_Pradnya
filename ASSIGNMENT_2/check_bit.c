#include<stdio.h>
#define bv(n)(1<<n)

void main ()
{ unsigned char status=0x80;
  print_bin(&status, sizeof(status));
  
  if(status&bv(3))
  printf("\nbit is set");
  else
  printf("\n bit is clear");
}
void print_bin(void *vp, int size)
{
    int i;

    // Loop from the most significant byte to the least.
    for(i = size - 1; i >= 0; i--)
    {
        unsigned char mask = 0x80;      // Start checking from MSB (bit-7)

        // Check all 8 bits of the selected byte
        while(mask)
        {
            /*
             * (char *)vp + i :
             *      - Cast vp to a byte pointer
             *      - Move to the i-th byte of the variable
             *
             * *((char *)vp + i) :
             *      - Read that byte value
             *
             * & mask :
             *      - Check whether the current bit is 1 or 0
             */
            if( *((char *)vp + i) & mask )
                printf("1");
            else
                printf("0");

            mask >>= 1;  // Move mask to next lower bit
        }

        printf(" ");     // Space between bytes
    }

    printf("\n");
}
