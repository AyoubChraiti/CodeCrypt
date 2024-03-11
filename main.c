// implement a simple incripting algorithme
// the input will be as follow:
// -> a file = "content you will be encrypting"
// -> code key = "key you will use to dycrept the content with"
// -> you will have to create a file wich will have the encrypted content.

#include "header.h"

int f1_enc(t_list *x, char *file)
{
	write(1, "Enter The Name of The File: ", 29);
	file = get_next_line(0);
	if (check_file(file))
	{
		printf("\nPlease Make Sure That The File Exist\nAnd Have The Permissions Needed\n\n");
		return 1;
	}
	x->file_str = file;
	return 0;
}

int f2_enc(t_list *x, char *code)
{
	write(1, "Key Of 3 Numbers: ", 19);
	code = get_next_line(0);
	if (check_key(code))
	{
		printf("\nPlease enter a valid key number.\n");
		return 1;
	}
	x->key = code;
	return 0;
}

void	encrypting_handler(t_list *x, char *file, char *code)
{
	while(1)
	{
		while (f1_enc(x, file) == 1)
			f1_enc(x, file);
		while (f2_enc(x, code) == 1)
			f2_enc(x, code);
		break;
	}
}

void	decrypting_handler(t_list *x, char *file, char *code)
{
	while(1)
	{
		while (f1_dec(x, file) == 1)
			f1_dec(x, file);
		while (f2_dec(x, code) == 1)
			f2_dec(x, code);
		break;
	}
}

int main(int argc, char **argv)
{
	t_list	x;

	if (argc != 2)
		throw_valid_arg();
	else if (strncmp(argv[1], "-e", 2) == 0)
	{
		char *code = NULL;
		char *file = NULL;
	
		encrypting_handler(&x, file, code);
		getting_input(&x, 1);
		close(x.fd_input);
		close(x.fd_out);
	}
	else if(strncmp(argv[1], "-d", 2) == 0)
	{
		char *code = NULL;
		char *file = NULL;

		decrypting_handler(&x, file, code);
		getting_input(&x, 2);
		close(x.fd_input);
		close(x.fd_out);
	}
	else
	{
		throw_valid_arg();
	}
}