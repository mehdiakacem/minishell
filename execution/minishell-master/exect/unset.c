 typedef struct s_env
{
    char *value;
    char *name;
    struct s_env *next;
}   t_env;


void  ft_remove_fron_env(t_env **begin_list, t_env *data_ref)
{
	if (begin_list == NULL || *begin_list == NULL)
		return;

	t_env *tmp = *begin_list;
    data_ref = tmp->

	if (cmp(tmp->value, data_ref) == 0)
	{
		*begin_list = tmp->next;
		free(tmp);
		ft_list_remove_if(begin_list, data_ref);
	}
	tmp = *begin_list;
	ft_list_remove_if(&tmp->next, data_ref);
}

int check_is_digit(int x)
{
    if (x >= '0' && x <= '9')
		return (!0);
	return (0);

}

int check_special_caract(char *arg)
{
    int i;
    i = 0;
    while(arg[i])
    {
        if(arg[0] != '#' && arg[i] != check_is_digit(arg[i]) && /
            ((arg[i] >= 'A' && arg[i] <= 'Z') ||(arg[i] >= 'a' && arg[i] <= 'z')) && arg[i] != '_')
            {
                printf("-minishell: unset: -%s: not a valid identifier\n", command->args[1]);
                return(1);
            }
        i++;
    }
    return(0);
}
t_env *identique_var(char  *arg, t_env **variable)
{
    t_env *tmp;

    while(tmp)
    {
        if(strcmp((*variable)->name, arg) == 0)
        {
            tmp = *variable;
            return(tmp);
        }
        variable = (*variable)->next;
    }
    return(NULL);
}
void    unset(t_env **variable ,t_command *command)
{
    int i;

    i = 1;
    if(!variable)
        return ;
    if(command->nb_args >= 2)
    {
        if(command->args[1] && command->args[1][0] == '-')
        {
            printf("-minishell: unset: -%s: invalid option\n", command->args[1]);
            printf("unset: usage: unset [-f] [-v] [-n] [-name ...]");
        }
        while (command->args[i])
        {
            if(!check_is_digit(command->args[i][0]) && !check_special_caract(command->args[i]) && identique_var(command->arg[i], variable))
            {
               remove_from_env((*variable)->name, (*variable)->value);//i should do a function that get the envirement information and give it as param to this function also to do : function that compares variable with env content 
            }
            i++;
        }
    }      
}