// in this part i will be focused on getting the input
// from the file as a string and implement an algorithme
// that will make the strings non readble (encrypted) 

#include "header.h"

int	check_file(char *file)
{
	remove_newline(file);
	if (access(file, F_OK) != 0 || strlen(file) < 2)
		return 1;
	return 0;
}

int	check_key(char *key)
{
	int f = 0;
	if (strlen(key) - 1 != 3)
		return 1;
	for (int i = 0; i < strlen(key); i++)
	{
		if (ft_isdigit(key[i]))
			f++;
	}
	if (f == strlen(key) - 1 && f > 0)
		return 0;
	return 1;
}

char *incrypt_line(t_list *x, char *line, int code)
{
	for (int i = 0; i < strlen(line) - 1; i++)
	{
		line[i] = line[i] + code;
	}
	return line;
}

char *decrypt_line(t_list *x, char *line, int code)
{
	for (int i = 0; i < strlen(line) - 1; i++)
	{
		line[i] = line[i] - code;
	}
	return line;
}

void    getting_input(t_list *x, int flag)
{
	char *line = NULL;
	if (flag == 1)
	{
		x->fd_input = open(x->file_str, O_RDONLY);
		x->fd_out = open("???", O_CREAT | O_RDWR | O_TRUNC, 0644);
		if (x->fd_input == -1 || x->fd_out == -1)
			ft_exit();
		line = get_next_line(x->fd_input);
		while (line != NULL)
		{
			char *ecode = incrypt_line(x, line, atoi(x->key));
			write(x->fd_out, ecode, strlen(ecode));
			line = get_next_line(x->fd_input);
		}
		printf("\nEncryption Successful.\nRESULT STORED IN THE ??? FILE\n");
	}
	else if (flag == 2)
	{
		x->fd_input = open(x->file_str, O_RDONLY);
		x->fd_out = open("!!!", O_CREAT | O_RDWR | O_TRUNC, 0644);
		if (x->fd_input == -1 || x->fd_out == -1)
			ft_exit();
		line = get_next_line(x->fd_input);
		while (line != NULL)
		{
			char *ecode = decrypt_line(x, line, atoi(x->key));
			write(x->fd_out, ecode, strlen(ecode));
			line = get_next_line(x->fd_input);
		}
		printf("\nDecryption Successful.\nRESULT STORED IN THE !!! FILE\n");
	}
}
