void    check_args(t_command *command)
{
    if(command->args[1] == '-')
        back_to_oldpwd();
    else if(command->args)



}
void cd(t_command *command)
{
    if((command->args[1]) == "--" || command->args[1] == "~" || command->nb_args == 1)
        back_to_home();
    else if (command->nb_args > 1)
    {
        check_args(commande->args[1])cd
    }
    
}