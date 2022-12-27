#include <stdio.h>

char	*ft_strchr(const char *s, int c)
{
	char	*ps;
	char	cc;

	cc = (char)c;
	ps = (char *)s;
	while (*ps != '\0')
	{
		if (*ps == cc)
			return (ps);
		ps++;
	}
	if (*ps == cc)
		return (ps);
	return (NULL);
}

char	*ft_strrchr(const char *s, int c)
{
	char	*pc;
	int		str_len;
	char	cc;

	cc = (char)c;
	str_len = ft_strlen(s);
	if (!s)
		return (NULL);
	if (s == (void *)0)
		return ((char *)s);
	s = s + str_len;
	while (str_len + 1 > 0)
	{
		if (*s == cc)
		{
			pc = (char *)s;
			return (pc);
		}
		str_len--;
		s--;
	}
	return (NULL);
}

int main()
{
    
}