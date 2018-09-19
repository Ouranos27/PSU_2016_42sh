/*
** my_strdup.c for minishell.c in /home/amaury/delivery/PSU_2016_minishell1
** 
** Made by Amaury Bernard
** Login   <amaury.bernard@epitech.eu>
** 
** Started on  Sat Jan 21 16:20:02 2017 Amaury Bernard
** Last update Sun May 21 09:02:07 2017 Nicolas Marsan
*/

#include <stdlib.h>
#include <sh.h>

char	*my_strdup(char *str)
{
  int	i;
  char	*new;
  char	c;

  if (str == NULL)
    return (NULL);
  i = 0;
  if ((new = malloc(sizeof(char) * my_strlen(str) + 1)) == NULL)
    return (NULL);
  while (str[i] != '\0')
    {
      c = str[i];
      new[i] = c;
      ++i;
    }
  new[i] = '\0';
  return (new);
}
