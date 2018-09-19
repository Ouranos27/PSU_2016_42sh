/*
** use_env.c for mysh in /home/amaury/delivery/PSU_2016_minishell2
** 
** Made by Amaury Bernard
** Login   <amaury.bernard@epitech.eu>
** 
** Started on  Sun Apr  9 15:19:29 2017 Amaury Bernard
** Last update Sun May 21 09:00:20 2017 Nicolas Marsan
*/

#include <stdlib.h>
#include "sh.h"

t_use_env	*init_use_env(char **env)
{
  t_use_env	*use_env;

  if (!(use_env = malloc(sizeof(t_use_env))))
    return (NULL);
  use_env->env = env;
  use_env->pwd = my_strdup(get_var_env("PWD=", env));
  use_env->oldpwd = my_strdup(get_var_env("OLDPWD=", env));
  use_env->host = my_strdup(get_var_env("HOST=", env));
  use_env->home = my_strdup(get_var_env("HOME=", env));
  return (use_env);
}
