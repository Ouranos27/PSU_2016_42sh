/*
** cmd_env.c for minishell1 in /home/amaury/delivery/PSU_2016_minishell1
** 
** Made by Amaury Bernard
** Login   <amaury.bernard@epitech.eu>
** 
** Started on  Sat Jan 21 16:10:16 2017 Amaury Bernard
** Last update Sun May 21 09:01:18 2017 Nicolas Marsan
*/

#include <stdlib.h>
#include "sh.h"

int	cmd_exit(__attribute__((unused)) char **env, char **argv, int *rt)
{
  if (str_are_equal(argv[0], "exit") == TRUE)
    {
      if (argv[1] == NULL)
	return (TRUE);
      else if (argv[2] != NULL)
	{
	  my_printf("%e", "exit: Expression Syntax.\n");
	  *rt = 1;
	  return (FALSE);
	}
      else
	{
	  if (my_str_isnum(argv[1]) == FALSE)
	    {
	      my_printf("%e", "exit: Expression Syntax.\n");
	      *rt = 1;
	      return (FALSE);
	    }
	   *rt = my_get_nbr(argv[1]);
	  return (TRUE);
	}
    }
  return (FALSE);
}
