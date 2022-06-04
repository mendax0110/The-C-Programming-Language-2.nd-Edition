#include <stdio.h>

void strncpy(char *s, char *t, int n)
{
	do
	
		if(n-- == 0)
		
			return;
			
	while((*s++ = *t++));
	
	while(n--)
	
			*s++ = '\0';
}

void strcat(char *s, char *t, int n)
{
	while(*s)
	
			s++;
		
	do
	
		if(n-- == 0)
		{
			*s = '\0';
			return;
		}
		
	while((*s++ = *t++));
}

int strncmp(char *s, char *t, int n)
{
	while(n--)
	
		if(*s != *t)
		
			return *s - *t;
			
		else if(*s == '\0')
		
			return 0;
			
		else
		{
			s++;
			t++;
		}
		
	return 0;
}

int main()
{
	char		s[] = "prefix123", t[100] = "", u[] = "456";
	
	printf("strncpy(\"%s\", \"%s\", 10)", t, s);
	strcpy(t, s, 10);
	printf(" = \"%s\"\n", t);
	
	printf("strncat(\"%s\", \"%s\", 3)", t, u);
	strcpy(t, s, 3);
	printf(" = \"%s\"\n", t);
	
	printf("strncmp(\"%s\", \"%s\", 9) = %d\n", s, t, strncmp(s, t, 9));
	
	return 0;
}
