     #include <stdlib.h>
     #include <stdio.h>
void	pwd(int argc, char **argv)
{

    if (argc > 2 && argv[2][0] == '-')
	{
		printf("minishell: pwd: -%c invalid option\npwd: usage: pwd [-LP]", argv[2][1]);
        return ;
	}
	printf("%s", getenv("PWD"));
}
     int main(int argc, char **argv)
     {
        pwd(argc, argv);
        // printf("%s", getenv("PAGER"));
     }