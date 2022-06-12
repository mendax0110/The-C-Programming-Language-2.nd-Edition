/*include the libraries*/
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

/*using direct system-calls instead of the standard library,
 *this program should be somewhat faster
 */

 /*define the BUFSIZE*/
 #define BUFSIZE 4096

void filecopy(int ifd, int ofd);

/*main part of the program*/
int main(int argc, char *argv[])
{
	int	fd;

	if(argc == 1)
		filecopy(0, 1);
	else
		while(--argc > 0)
			if((fd = open(*++argv, O_RDONLY, 0)) == -1)
			{
				printf("Error: Cannot open %s!\n", *argv);
			}
			else
			{
				filecopy(fd, 1);
				close(fd);
			}
	return 0;
}

void filecopy(int ifd, int ofd)
{
	char	buf[BUFSIZE];
	int		n;

	while((n = read(ifd, buf, BUFSIZE)) > 0)
		write(ofd, buf, n);
}
