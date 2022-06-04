#include <stdio.h>

void strcat(char *s, char *t)
{
	while(*s)
	
		s++;
		
	while((*s++ = *t++))
			
		;
}

int main()
{
	char	s[100] = "concatenated ", t[] = "string";
	
	printf("strcat(\"%s\", \"%s\")", s, t);
	strcat(s, t);
	printf(" = \"%s\"\n", s);
	
	return 0;
}
