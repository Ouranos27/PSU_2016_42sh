/*
** my_2str_in1.c for mysh in /home/amaury/delivery/PSU_2016_minishell2
** 
** Made by Amaury Bernard
** Login   <amaury.bernard@epitech.eu>
** 
** Started on  Thu Apr  6 12:42:23 2017 Amaury Bernard
** Last update Sun May 21 09:02:03 2017 Nicolas Marsan
*/

#include <stdlib.h>
#include "sh.h"

char	*my_2str_in1(char *str1, char *str2)
{
  char	*new;
  int	i;
  int	len1;
  int	len2;

  len1 = my_strlen(str1);
  len2 = my_strlen(str2);
  if (!(new = malloc(sizeof(char) * (len1 + len2 + 2))))
    return (NULL);
  new[len1 + len2 + 1] = 0;
  i = -1;
  while (++i < len1)
    new[i] = str1[i];
  if (new[i - 1] != '/')
    {
      new[i++] = '/';
      ++len1;
    }
  i--;
  while (++i < len1 + len2)
    new[i] = str2[i - len1];
  new[i] = 0;
  return (new);
}
