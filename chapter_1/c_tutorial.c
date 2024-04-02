#include <stdio.h>

#define LOWER 0 /* lower limit of table */
#define UPPER 300 /*upper limit */
#define step 20 /* step size */

int main()
{
	for (float fahr = LOWER; fahr <= UPPER; fahr += step)
	{
		printf("%3.0f\t%6.1f\n", fahr, (fahr-32)*5/9);
	}
}

