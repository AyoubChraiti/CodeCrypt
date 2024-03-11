// in this part i will only be creating functions
// that will help the overall code work smoothly.
// and also it will help with making the code well structured and
// readable.

# include "header.h"

void	throw_valid_arg()
{
	printf("Enter A Valid Argument:\n-e For Encrypting\n-d For Decrypting\n");
	exit(EXIT_FAILURE);
}

void remove_newline(char *str)
{
	int length = strlen(str);

	for (int i = 0; i < length; i++)
	{
		if (str[i] == '\n')
		{
			str[i] = '\0';
			break;
		}
	}
}

void    ft_exit()
{
	fprintf(stderr, "\nProblem Occured\nTry Again Later\n");
	exit(EXIT_FAILURE);
}

int	f1_dec(t_list *x, char *file)
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

int f2_dec(t_list *x, char *code)
{
	write(1, "Key Of 3 Numbers: ", 19);
	code = get_next_line(0);
	if (check_key(code))
	{
		printf("\nPlease enter the key Used For Encrypting.\n");
		return 1;
	}
	x->key = code;
	return 0;
}