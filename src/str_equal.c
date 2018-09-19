/*
** str_equal.c for minishell1 in /home/amaury/delivery/PSU_2016_minishell1
** 
** Made by Amaury Bernard
** Login   <amaury.bernard@epitech.eu@epitech.net>
** 
** Started on  Wed Jan 18 15:39:56 2017 Amaury Bernard
** Last update Sun May 21 09:00:26 2017 Nicolas Marsan
*/

#include "sh.h"

int	str_begin_equal(char *str, char *str2)
{
  int	i;

  i = 0;
  while (str[i] != '\0' && str2[i] != '\0')
    {
      if (str[i] != str2[i])
	return (FALSE);
      ++i;
    }
  if (str2[i] == '\0')
    return (TRUE);
  return (FALSE);
}

int	str_are_equal(char *str, char *str2)
{
  int	i;

  i = 0;
  while (str[i] != '\0' && str2[i] != '\0')
    {
      if (str[i] != str2[i])
	return (FALSE);
      ++i;
    }
  if (str2[i] == '\0' && str[i] == '\0')
    return (TRUE);
  return (FALSE);
}
