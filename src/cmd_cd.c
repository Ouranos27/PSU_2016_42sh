/*
** cmd_cd.c for minishell1 in /home/amaury/delivery/PSU_2016_minishell1
** 
** Made by Amaury Bernard
** Login   <amaury.bernard@epitech.eu>
** 
** Started on  Sat Jan 21 16:10:16 2017 Amaury Bernard
** Last update Sun May 21 09:01:30 2017 Nicolas Marsan
*/

#include <unistd.h>
#include <stdlib.h>
#include <limits.h>
#include "sh.h"
#include "msgs.h"

int	error(char *str, char *str2)
{
  my_printf("%e%e", str, str2);
  return (1);
}

void	update_pwd_old(t_use_env *use_env)
{
  char	*av[4];

  av[0] = NULL;
  av[1] = "OLDPWD";
  av[2] = use_env->oldpwd;
  av[3] = NULL;
  cmd_setenv(use_env, av);
  av[1] = "PWD";
  av[2] = use_env->pwd;
  cmd_setenv(use_env, av);
}

int	cmd_cd_av1_null(t_use_env *use_env, char **argv)
{
  if (use_env->home != NULL)
    {
      if (use_env->oldpwd != NULL)
	free(use_env->oldpwd);
      use_env->oldpwd = use_env->pwd;
      use_env->pwd = my_strdup(use_env->home);
      update_pwd_old(use_env);
      return (chdir(use_env->pwd));
    }
  my_printf("%e%e", argv[0], MSG_NO_HOME);
  return (1);
}

int	cmd_cd_swap_oldnew(t_use_env *use_env)
{
  char	*swap;

  if (use_env->oldpwd == NULL)
    {
      my_printf("%e", MSG_NODIRFILE);
      return (1);
    }
  swap = use_env->oldpwd;
  use_env->oldpwd = use_env->pwd;
  use_env->pwd = swap;
  update_pwd_old(use_env);
  return (chdir(use_env->pwd));
}

int	cmd_cd(t_use_env *use_env, char **argv)
{
  char	*buf;

  if (argv[1] == NULL)
    return (cmd_cd_av1_null(use_env, argv));
  if (argv[2] != NULL)
    return (error(argv[0], MSG_TOO_MANY));
  if (argv[1][0] == '-' && argv[1][1] == '\0')
    return (cmd_cd_swap_oldnew(use_env));
  if (chdir(argv[1]) == 0)
    {
      if (!(buf = malloc(sizeof(char) * PATH_MAX)))
	return (ERR_STD);
      if (use_env->oldpwd != NULL)
	free(use_env->oldpwd);
      use_env->oldpwd = use_env->pwd;
      if (!(use_env->pwd = getcwd(buf, PATH_MAX)))
	return (ERR_STD);
      update_pwd_old(use_env);
      return (0);
    }
  else
    return (error(argv[1], MSG_NODIRFILE));
  return (0);
}
