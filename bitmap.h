/** 
 * Author: Rafael Lagemann
 * E-mail: rdlagemann@gmail.com
 * Computer Science
 * Federal University of Pelotas - Brazil
 * 06-22-2016 
 * 
 * */
#include <stdio.h>
#include <math.h> //in some OS's, pay attention to -lm flag to build it right

#ifndef BITMAP_H	
#define BITMAP_H

typedef unsigned char bitmap_t;

/**Description		:Change of set to unset and vice versa
 * 
 * @param bitmap	:pointer to a bitmap
 * @param index		:position of the bit in the bitmap (left to right, 0 to 7)
 * @return 		:1 if succeeds, 0 if don't
 *  
 */
 int change_bitmap(bitmap_t *bitmap, int index)
{
	if((index < 0) || (index > 7)) return 0; //fail - index out of range
	*bitmap = *bitmap ^ (1 << (index & 7));
	return 1;
}

/**Description	 :Get bit value from given bitmap
 * 
 * @param bitmap :pointer to a bitmap
 * @param index  :position of the bit in the bitmap (left to right, 0 to 7)
 * @return 	 :the bit you request or -1 if it fails 
 * 
 */
int get_bitmap(bitmap_t *bitmap, int index)
{
	
	if((index < 0) || (index > 7))
		return -1; //fail - index out of range
		 
	int comparator;
	comparator = *bitmap & (1 << (index & 7));
		
	if((int)pow(2,index) == comparator)
		return 1;
	else
		return 0;		
}

#endif
