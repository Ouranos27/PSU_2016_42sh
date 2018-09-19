/*
** main.c for minishell1 in /home/amaury/delivery/PSU_2016_minishell1
** 
** Made by Amaury Bernard
** Login   <amaury.bernard@epitech.eu>
** 
** Started on  Mon Jan 16 14:57:36 2017 Amaury Bernard
** Last update Sun May 21 09:00:47 2017 Nicolas Marsan
*/

#include <stdlib.h>
#include "sh.h"

void	decla_cmds(t_cmd *cmds)
{
  cmds[0].cmd = my_strdup("env");
  cmds[0].fct = &cmd_env;
  cmds[1].cmd = my_strdup("setenv");
  cmds[1].fct = &cmd_setenv;
  cmds[2].cmd = my_strdup("unsetenv");
  cmds[2].fct = &cmd_unsetenv;
  cmds[3].cmd = my_strdup("cd");
  cmds[3].fct = &cmd_cd;
  cmds[4].cmd = my_strdup("echo");
  cmds[4].fct = &cmd_echo;
  cmds[NB_CMDS].cmd = NULL;
}

/*
** FreeParty
*/
int		main(__attribute__((unused)) int ac,
		     __attribute__((unused)) char **av, char **env)
{
  int		rt;
  t_cmd		shell_cmd[NB_CMDS + 1];
  t_sys_cmd	*sys_cmd;
  t_use_env	*use_env;

  if (!(env = init_env(env))
      || !(use_env = init_use_env(env))
      || !(sys_cmd = get_sys_cmds(env, use_env->home)))
    return (ERR_FATAL);
  decla_cmds(shell_cmd);
  rt = shell(use_env, shell_cmd, sys_cmd);
  return (rt);
}
