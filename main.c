// implement a simple incripting algorithme
// the input will be as follow:
// -> a file = "content you will be encrypting"
// -> code key = "key you will use to dycrept the content with"
// -> you will have to create a file wich will have the encrypted content.

#include "header.h"

void	encrypting_handler(t_list *x, char *file, char *code)
{
	while(1)
	{
		write(1, "Enter The Name of The File: ", 29);
		file = get_next_line(0);
		if (check_file(file))
		{
			printf("\nPlease Make Sure That The File Exist\nAnd Have The Permissions Needed\n");
			exit(1);
		}
		x->file_str = file;
		write(1, "Key Of 5 Numbers: ", 19);
		code = get_next_line(0);
		if (check_key(code))
		{
			printf("\nPlease enter a valid key number.\n");
			exit(1);
		}
		x->key = code;
		break;
	}
}

void	decrypting_handler(t_list *x, char *file, char *code)
{
	while(1)
	{
		write(1, "Enter The Name of The File: ", 29);
		file = get_next_line(0);
		if (check_file(file))
		{
			printf("\nPlease Make Sure That The File Exist\nAnd Have The Permissions Needed\n");
			exit(1);
		}
		x->file_str = file;
		write(1, "Key Of 5 Numbers: ", 19);
		code = get_next_line(0);
		if (check_key(code))
		{
			printf("\nPlease enter the key Used For Encrypting.\n");
			exit(1);
		}
		x->key = code;
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
	}
	else if(strncmp(argv[1], "-d", 2) == 0)
	{
		char *code = NULL;
		char *file = NULL;

		decrypting_handler(&x, file, code);
		getting_input(&x, 2);
	}
	else
	{
		throw_valid_arg();
	}
}