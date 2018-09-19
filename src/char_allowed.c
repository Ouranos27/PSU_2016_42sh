/*
** char_allowed.c for  in /home/amaury/delivery/PSU_2016_42sh
** 
** Made by Amaury Bernard
** Login   <amaury.bernard@epitech.eu>
** 
** Started on  Thu May 18 10:53:45 2017 Amaury Bernard
** Last update Thu May 18 10:53:45 2017 Amaury Bernard
*/

#include "sh.h"

int	char_allowed(char c, char *allowed)
{
  int	i;

  i = 0;
  while (allowed[i] != 0)
    {
      if (c == allowed[i])
	  return (TRUE);
      ++i;
    }
  return (FALSE);
}
