#include <stdio.h>
#define MAXLINE 1000 /* maximum input line */

int get_line(char line[], int maxline);
void copy(char to[], char from[]);
void reverse(char to[], char from[], int len);

/*print the longest input line */
int main()
{
	int len; 		/* current line length */
	int max;		/* maximum length seen so far */
	char line[MAXLINE];	/* current input line */
	char longest[MAXLINE];	/* longest line saved here */
	char output[MAXLINE];

	max = 0;
	while ((len = get_line(line, MAXLINE)) > 0)
		if (len > max) {
			max = len;
			copy(longest, line);
		}
	if (max > 0)		/* there was a line */
		reverse(output, longest, max);
		printf("%s", output);
	return 0;
}

/* getline: read a line into s, return length */
int get_line(char s[], int lim)
{
	int c, i;

	for (i=0; i < lim - 1 && (c=getchar()) != EOF && c != '\n'; ++i)
		s[i] = c;
	if (c == '\n') {
		s[i] = c;
		++i;
	}
	s[i] = '\0';
	return i;
}

/* copy: copy 'from' into 'to'; assume to is big enough */
void copy(char to[], char from[])
{
	int i;

	i = 0;
	while ((to[i] = from[i]) != '\0')
		++i;
}

/* reverse: reverse the input string */
void reverse(char to[], char from[], int len)
{
	int i, j;
	
	j = len - 1;
	for (i = 0; i < len; ++i){
		to[i] = from[j];
		--j;
	}	
	to[len] = '\0';
}
