void    display_env(t_env **envt)
{
	t_env *tmp = *env;
    while (tmp != 0)
    {
        printf("%s\n", tmp->data);
        tmp= tmp->next;
    }
}

void export(t_command *command, t_env **env)
{
    if((command->nb_args < 2)&& (command->args[1][0] == '#' || command == ';'))
    {
        display_sorted_env(env)
    }
    else
        added_display_env(env, commande-)
}