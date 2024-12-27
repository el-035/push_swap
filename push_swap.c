//check input
	//no duplicates
	//int
//add data to the node
//rules
//

#include"push_swap.h"
void	check_duplicates(char **input)
{
	int	i;
	int	j;

	i = 0;
	while(input[i])
	{
		j = i + 1;
		while (input[j])
		{
			if (atoi_ps(input[i]) == atoi_ps(input[j]))
			{
				printf("Error\n");
				exit(1);
			}
			j++;
		}
		i++;
	}
}

int main(int argc, char **argv)
{
	if (argc <= 1)
		return (0);		//must not display anything and give the prompt back.

	check_duplicates(argv);
}