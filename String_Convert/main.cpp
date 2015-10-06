#include <stdio.h>
#include <Windows.h>
#include <io.h>
#include "list.h"

char *get_path(void)
{
	t_str *c_path = NULL;
	char *buff;
	char *path;
	int ret;
	int i;

	buff = (char *)malloc(sizeof(char *) * 32);
	i = 0;
	do
	{
		ret = _read(0, buff, 32);
		c_path = add_str(c_path, buff, 0);
	} while (ret == 32);
	path = export_str(c_path);
	while (path[i])
		i++;
	while (path[i] != '\n')
		i--;
	path[i - 1] = 0;
	return (path);
}

void print_file(char *path)
{
	unsigned char *buffer;
	int result;
	int back_line;
	FILE *src;
	FILE *dest;
	t_str *c_str = NULL;

	buffer = (unsigned char*)malloc(sizeof(unsigned char));
	back_line = 0;
	src = fopen(path, "rb");
	dest = fopen("Hexa.txt", "w+");
	if (src != NULL)
	{
		do 
		{
			result = fread(buffer, 1, 1, src);
			fprintf(dest, "\t%#x", *buffer);
			printf("\t%#x", *buffer);
			back_line++;
			if (result != 0)
			{
				fprintf(dest, ",");
				printf(",");
			}
			if (back_line > 10)
			{
				printf("\n");
				fprintf(dest, "\n");
				back_line = 0;
			}
		} while (result != 0);
		printf("};");
		fprintf(dest, "};");
		fclose(src);
		fclose(dest);
	}
	else
		printf("Erreur d'ouverture\n");
}

int main()
{
	while (1)
		print_file(get_path());
	return (0);
}

