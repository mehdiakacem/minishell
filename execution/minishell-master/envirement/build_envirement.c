# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <stdio.h>
void	refresh_pwd(t_env **env)
{
	t_env	*head;
	head = *env;
	while(head && strcmp(head->name, "PWD"))
		head = head->next;
	if(head && head->value)
		head->value = getcwd(NULL, 0);
}
char	*ft_substr(char const *s, unsigned int start, size_t len)

{
	size_t	firstc;
	char	*newstr;

	firstc = 0;
	if (!s)
		return (NULL);
	if (start > strlen(s))
	{
		newstr = malloc(1);
		if (!newstr)
			return (NULL);
		newstr[0] = '\0';
		return (newstr);
	}
	if (len > strlen(s))
		len = strlen(s);
	newstr = (char *)malloc(sizeof(char) * (len + 1));
	if (!newstr)
		return (NULL);
	while (firstc < len && start < strlen(s))
	{
		newstr[firstc++] = s[start++];
	}
	newstr[firstc] = '\0';
	return (newstr);
}

typedef struct s_env
{
    char *value;
    char *name;
    struct s_env *next;
}   t_env;

char receive_name(char *allstr)// allstr == line . start reading from 0 until len(strchr(=))
{
    return(ft_substr(allstr, 0, strlen(allstr) - strlen(strchr(allstr, '='))));
}

char receive_value(char *allstr)
{
     return(ft_substr(allstr, strlen(allstr) - strlen(strchr(allstr, '=')), "\0"));
}

t_env	*ft_lstnew(char *allstr)
{
	t_env	*newelement;

	newelement = (t_env *)malloc(sizeof(t_env));
	if (newelement == 0)
		return (0);
    newelement->name = receive_name(allstr);
	newelement -> value = receive_value(allstr);
	newelement -> next = NULL;
	return (newelement);
}

void	ft_lstadd_back(t_env *new, t_env **alst)
{
	t_env	*node;

	node = *alst;
	if (alst && *alst)
	{
		while (node-> next)
		{
			node = node->next;
		}
			node->next = new;
	}
	else
		*alst = new;
}

t_env   *build_env(char **env)
{
    int i;
    t_env   *tmp;

    tmp = NULL;
    i = 0;
    while(env[i])
    {
        ft_lstadd_back(ft_lstnew(env[i]), &tmp);
        i++;
    }
    return(tmp);
}
