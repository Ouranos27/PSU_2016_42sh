/*
** cmd_env.c for minishell1 in /home/amaury/delivery/PSU_2016_minishell1
** 
** Made by Amaury Bernard
** Login   <amaury.bernard@epitech.eu>
** 
** Started on  Sat Jan 21 16:10:16 2017 Amaury Bernard
** Last update Sun May 21 09:01:39 2017 Nicolas Marsan
*/

#include <stdlib.h>
#include "sh.h"
#include "msgs.h"

static int	str_begin_equal_eq(char *str, char *str2)
{
  int		i;

  i = 0;
  while (str[i] != '=' && str2[i] != '\0')
    {
      if (str[i] != str2[i])
	return (FALSE);
      ++i;
    }
  if (str[i] == '=' && str2[i] == '\0')
    return (TRUE);
  return (FALSE);
}

static int	nb_member_n_isset(char **tab, char *str)
{
  int		nb;

  nb = 0;
  while (tab[nb] != NULL)
    {
      if (str_begin_equal_eq(tab[nb], str) == TRUE)
	return (-nb);
      ++nb;
    }
  return (nb);
}

static char	*my_2str_in1_setenv(char *str1, char *str2)
{
  char		*new;
  int		i;
  int		len1;
  int		len2;

  if (str2 == NULL)
    str2 = "";
  len1 = my_strlen(str1);
  len2 = my_strlen(str2);
  if (!(new = malloc(sizeof(char) * (len1 + len2 + 2))))
    return (NULL);
  new[len1 + len2 + 1] = 0;
  i = -1;
  while (++i < len1)
    new[i] = str1[i];
  if (new[i - 1] != '=')
    {
      new[i++] = '=';
      ++len1;
    }
  --i;
  while (++i < len1 + len2)
    new[i] = str2[i - len1];
  new[i] = 0;
  return (new);
}

int	cmd_setenv(t_use_env *use_env, char **argv)
{
  char	**new;
  int	i;

  if (argv[1] == NULL)
    return (cmd_env(use_env, argv));
  if (argv[2] != NULL && argv[3] != NULL)
    return (rt_with_msg(ERR_STD, argv[0], MSG_TOO_MANY));
  if (my_str_isalphanum(argv[1]) == FALSE
      && (argv[2] != NULL && my_str_isalphanum(argv[1]) == FALSE))
    return (rt_with_msg(ERR_STD, argv[0], MSG_NOALPHANUM));
  if ((i = nb_member_n_isset(use_env->env, argv[1])) < 0)
    {
      use_env->env[-i] = my_2str_in1_setenv(argv[1], argv[2]);
      return (0);
    }
  if (!(new = malloc(sizeof(char *) * (i + 2))))
    return (ERR_FATAL);
  i = -1;
  while (use_env->env[++i] != NULL)
    new[i] = use_env->env[i];
  new[i] = my_2str_in1_setenv(argv[1], argv[2]);
  new[i + 1] = NULL;
  free(use_env->env);
  use_env->env = new;
  return (0);
}

int	cmd_unsetenv(t_use_env *use_env, char **argv)
{
  int	i;
  int	check;

  if (argv[1] == NULL)
    {
      my_printf("%e%e", argv[0], MSG_TOO_FEW);
      return (ERR_STD);
    }
  i = 0;
  check = FALSE;
  while (use_env->env[i] != NULL)
    {
      if (check == FALSE)
	{
	  check = str_begin_equal_eq(use_env->env[i], argv[1]);
	  if (check == TRUE)
	    free(use_env->env[i]);
	}
      if (check == TRUE)
	use_env->env[i] = use_env->env[i + 1];
      ++i;
    }
  if (argv[2] != NULL)
    return (cmd_unsetenv(use_env, ++argv));
  return (0);
}
