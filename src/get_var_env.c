/*
** get_var_env.c for mysh in /home/amaury/delivery/PSU_2016_minishell2
** 
** Made by Amaury Bernard
** Login   <amaury.bernard@epitech.eu>
** 
** Started on  Thu Apr  6 19:05:00 2017 Amaury Bernard
** Last update Sun May 21 09:01:54 2017 Nicolas Marsan
*/

#include <stdlib.h>
#include "sh.h"

char	*get_var_env(char *var_finder, char **env)
{
  char	*var_data;

  var_data = NULL;
  while (*env != NULL)
    {
      if (str_begin_equal(*env, var_finder) == TRUE)
	{
	  var_data = *env + my_strlen(var_finder);
	  break ;
	}
      ++env;
    }
  return (var_data);
}
