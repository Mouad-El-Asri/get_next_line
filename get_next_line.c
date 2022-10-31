ft_read(int fd, char *result)
{
     char *str;
     int  i;

     //if (!result)
     //      result = malloc (sizeof(char));
     str = malloc(sizeof(char) * BUFFER_SIZE + 1);
     i = 1;
     while (i > 0)
     {
          i = read(fd, str, BUFFER_SIZE);
          if (i == -1)
          {
               free(str);
               return (NULL);
          }
          str[i] = '\0';
          result = ft_free(ft_strjoin(result, str), result);
          //print the str to check
          if (ft_strchr(str, '\n'))
               break ;
     }
     free(str);
     return (result);
}

char *ft_get_line(char *str)
{
     char *line;
     int  i;

     i = 0;
     if (str[0] == '\0')
          return (NULL);
     while (str[i] != '\0' && str[i] != '\n')
          i++;
     if (str[i] == '\0')
          line = malloc(sizeof(char) * i + 1);
     else
          line = malloc(sizeof(char) * i + 2);
     i = 0;
     while (str[i] != '\0' && str[i] != '\n')
     {
          line[i] = str[i];
          i++;
     }
     if (str[i] == '\0')
          line[i] == '\0';
     else
     {
          line[i] == '\n';
          line[i + 1] == '\0';
     }
     return (line);
}

char *ft_get_next_line(char *str)
{
     char *line;
     int  i;
     int  j;

     i = 0;
     j = 0;
     while (str[i] != '\0' && str[i] != '\n')
          i++;
     if (str[i] == '\0')
     {
          free(str);
          return (NULL);
     }
     line = malloc(sizeof(char) * (ft_strlen(str) - i + 1));
     i++;
     while (str[i] != '\0')
     {
          line[j] == str[i];
          i++;
          j++;
     }
     free(str);
     return (line);
}

char *ft_free(char *s1, char *s2)
{
     free(s2);
     return (s1);
}

char *get_next_line(int fd)
{
     static char    *str;
     char           *line;

     if (fd < 0 || BUFFER_SIZE <= 0)
          return (NULL);
     str = ft_file(fd, str);
     if (!str)
          return (NULL);
     line = ft_get_line(str);
     str = ft_next(str);
     return (line);
}
