/*
** my_str_isnum.c for mysh in /home/amaury/delivery/PSU_2016_minishell2
** 
** Made by Amaury Bernard
** Login   <amaury.bernard@epitech.eu>
** 
** Started on  Fri Apr  7 19:34:29 2017 Amaury Bernard
** Last update Sun May 21 09:02:12 2017 Nicolas Marsan
*/

#include "sh.h"

int	my_str_isnum(char *str)
{
  while (*str != 0)
    {
      if (*str < '0' || *str > '9')
	return (FALSE);
	++str;
    }
  return (TRUE);
}
