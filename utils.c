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
	fprintf(stderr, "Problem Occured\nTry Again Later\n");
	exit(EXIT_FAILURE);
}