/*
** shell.c for minishell1 in /home/amaury/delivery/PSU_2016_minishell1
** 
** Made by Amaury Bernard
** Login   <amaury.bernard@epitech.eu>
** 
** Started on  Tue Jan 17 15:07:55 2017 Amaury Bernard
** Last update Sun May 21 09:01:03 2017 Nicolas Marsan
*/

#include <stdlib.h>
#include "sh.h"
#include "get_input_argv.h"

static char	is_delim(char c)
{
  return (char_allowed(c, ARG_DELIM));
}

static void	arg_is_ended(char *status, char *input_i,
			     char ***argv, int *n_argv)
{
  if (*status == ARG_LOAD)
    {
      *input_i = 0;
      (*argv)[*n_argv] = my_strdup((*argv)[*n_argv]);
      ++(*n_argv);
    }
  *status = ARG_END;
}

static void	arg_is_started(char *status, char *input_i,
			       char ***argv, int *n_argv)
{
  (*argv)[*n_argv] = input_i;
  *status = ARG_LOAD;
}

static int	nb_argv(char *input)
{
  int		nb;
  int		i;
  int		status;

  i = 0;
  nb = 0;
  status = ARG_END;
  while (input[i] != 0)
    {
      if (is_delim(input[i]) == TRUE)
	status = ARG_END;
      else if (status != ARG_LOAD)
	status = ARG_START;
      if (status == ARG_START)
	{
	  status = ARG_LOAD;
	  ++nb;
	}
      ++i;
    }
  return (nb);
}

int		get_input_argv(char ***argv)
{
  char		*input;
  int		i;
  int		n_argv;
  char		status;

  if ((input = get_next_line(0)) == NULL
      && my_printf("exit\n") > 0)
    input = my_strdup("exit");
  if (!(*argv = malloc(sizeof(char *) * (nb_argv(input) + 1))))
    return (ERR_FATAL);
  n_argv = 0;
  i = 0;
  status = ARG_END;
  while (input[i] != 0)
    {
      if (is_delim(input[i]) == TRUE)
	arg_is_ended(&status, &input[i], argv, &n_argv);
      else if (status != ARG_LOAD)
	arg_is_started(&status, &input[i], argv, &n_argv);
      ++i;
    }
  arg_is_ended(&status, &input[i], argv, &n_argv);
  (*argv)[n_argv] = NULL;
  free(input);
  return (0);
}
