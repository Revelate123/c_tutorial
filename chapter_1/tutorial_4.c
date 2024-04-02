#include <stdio.h>

int main(void)
{
	double nc;
	int c;

	while ((c = getchar()) != EOF)
	{
		if (c != '\n')
		{
			++nc;
		}
	}
	printf("%.0f\n",nc);
}
