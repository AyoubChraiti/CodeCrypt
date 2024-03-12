// in this part i will only be creating functions
// that will help the overall code work smoothly.
// and also it will help with making the code well structured and
// readable.

# include "header.h"

void	throw_valid_arg()
{
	printf("%sEnter A Valid Argument:\n-e For Encrypting\n-d For Decrypting\n", WHITE);
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
	fprintf(stderr, "\n%sProblem Occured\nTry Again Later\n", YELLOW);
	exit(EXIT_FAILURE);
}

int	f1_dec(t_list *x, char *file)
{
	ft_printf("%sEnter The Name of The File: ", WHITE);
	file = get_next_line(0);
	if (check_file(file))
	{
		printf("\n%sPlease Make Sure That The File Exist\nAnd Have The Permissions Needed\n\n", RED);
		return 1;
	}
	x->file_str = file;
	return 0;
}

int f2_dec(t_list *x, char *code)
{
	ft_printf("%sKey Of 3 Numbers: ", WHITE);
	code = get_next_line(0);
	if (check_key(code))
	{
		printf("\n%sPlease enter the key Used For Encrypting.\n", RED);
		return 1;
	}
	x->key = code;
	return 0;
}