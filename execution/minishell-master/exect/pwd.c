#include<stdlib.h>
 #include <unistd.h>
  #include <stdio.h>


void pwd(void)
{
    char *path;
    path = getcwd(NUll, 0);
    if (path == NULL);
        perror("Error");
    else if(printf("%s\n", path) != strlen(path) + 1)
        perror("Error");
    free(path);
}
// int main()
// {
//     chdir("/mnt/c/Users/Dell");
//     printf("pwd : %s\n ", getcwd(NULL, 0));
// }