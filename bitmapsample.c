/** 
 * Author: Rafael Lagemann
 * E-mail: rdlagemann@gmail.com
 * Computer Science
 * Federal University of Pelotas - Brazil
 * 06-22-2016 
 * 
 * */
#include <stdio.h>
#include "bitmap.h"

/**
 * printBits() writen by Stack Overflow user "user295190" 
 * here: stackoverflow.com/questions/111928/is-there-a-printf-converter-to-print-in-binary-format
 * 
 * We'll use it for bitmap better visualization
 * 
 * */
void printBits(size_t const size, void const * const ptr); 

int main (void)
{
	bitmap_t myBitmap = {0}; //bitmap all setted in 0
	int bitmap_bit;
	
	puts("Initial Bitmap:"); 
	printBits(sizeof(myBitmap), &myBitmap);
	
	toggle_bitmap(&myBitmap, 0); //set index 0
	puts("First Bitmap config:");
	printBits(sizeof(myBitmap), &myBitmap);
	
	toggle_bitmap(&myBitmap, 7); //set index 7
	puts("Second Bitmap config:");
	printBits(sizeof(myBitmap), &myBitmap);
	
	toggle_bitmap(&myBitmap, 7); //unset index 7
	puts("Third Bitmap config:");
	printBits(sizeof(myBitmap), &myBitmap);
	
	/**
	 * Remember toggle_bitmap(...) will return 0(FAIL) if a index is out of range
	 * So, you can go like this:
	 * */
	
	if(!toggle_bitmap(&myBitmap, 4)) //success
	{
		puts("Index out of range");
		return 1;
	}
	puts("Fourth Bitmap config:");
	printBits(sizeof(myBitmap), &myBitmap);
	
	if(!toggle_bitmap(&myBitmap, 23))//fail
		puts("Bit 23 = Index out of range");
	
	bitmap_bit = get_bitmap(&myBitmap, 0);
	printf("Bit 0 = %i\n", bitmap_bit);
	
	bitmap_bit = get_bitmap(&myBitmap, 1);
	printf("Bit 1 = %i\n", bitmap_bit);
	
	bitmap_bit = get_bitmap(&myBitmap, 4);
	printf("Bit 4 = %i\n", bitmap_bit);
	
	bitmap_bit = get_bitmap(&myBitmap, 7);
	printf("Bit 7 = %i\n", bitmap_bit);
	
	//now for a invalid index
	bitmap_bit = get_bitmap(&myBitmap, 23);
	printf("Bit 23 = %i //so you can verify if bitmap_bit > 0\n", bitmap_bit);
	
	//correctly
	if((bitmap_bit = get_bitmap(&myBitmap, 23)) < 0) 
		puts("Bit 23 = Index out of range"); //this is kinda ugly
		
	
	return 0;
}

void printBits(size_t const size, void const * const ptr)
{
    unsigned char *b = (unsigned char*) ptr;
    unsigned char byte;
    int i, j;

    for (i=size-1;i>=0;i--)
    {
        for (j=7;j>=0;j--)
        {
            byte = (b[i] >> j) & 1;
            printf("%u", byte);
        }
    }
    puts("");
}
