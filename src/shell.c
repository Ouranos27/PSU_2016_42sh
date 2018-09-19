/*
** shell.c for minishell1 in /home/amaury/delivery/PSU_2016_minishell1
** 
** Made by Amaury Bernard
** Login   <amaury.bernard@epitech.eu>
** 
** Started on  Tue Jan 17 15:07:55 2017 Amaury Bernard
** Last update Sun May 21 09:02:21 2017 Nicolas Marsan
*/

#include <stdlib.h>
#include "sh.h"
#include "msgs.h"
#include "cmd.h"
#include "shell_exec.h"

static void	prompt(char **env)
{
  int		i;
  char		*host;
  char		*pwd;

  host = NULL;
  pwd = NULL;
  i = 0;
  while (env[i] != NULL)
    {
      if (str_begin_equal(env[i], "HOST=") == TRUE)
	host = env[i] + 5;
      else if (str_begin_equal(env[i], "PWD=") == TRUE)
	pwd = env[i] + 4;
      ++i;
    }
  if (host)
    my_printf("%s", host);
  if (pwd)
    my_printf(":%s", pwd);
  my_printf("> ");
}

static int	shell_exec(t_s_exec *exe, char **av)
{
  int		check;

  if (((check = exec_shell_cmds(exe->shell_cmd,
				av, exe->use_env, &exe->rt)) == ERR_FATAL)
      || (check == FALSE && (check = exec_sys_cmds(exe->sys_cmd, av,
						   exe->use_env->env,
						   &exe->rt)) == ERR_FATAL)
      || (check == FALSE && (check = exec_file(av, exe->use_env->env,
					       &exe->rt)) == ERR_FATAL))
    {
      exe->rt = ERR_FATAL;
      return (ERR_FATAL);
    }
  if (cmd_exit(exe->use_env->env, av, &exe->rt) == TRUE)
    return (CMD_EXIT);
  if (check == FALSE)
    exe->rt = rt_with_msg(ERR_STD, av[0], MSG_NOTFOUND);
  return (TRUE);
}

static void	decla(t_use_env *use_env, t_cmd *shell_cmd,
		      t_s_exec *exe, t_sys_cmd *sys_cmd)
{
  exe->use_env = use_env;
  exe->shell_cmd = shell_cmd;
  exe->sys_cmd = sys_cmd;
}

static int	redir(t_instru *instru, t_s_exec *exe, const char type)
{
  if (type == R_CLOSE)
    instru->redir_file = NULL;
  if ((instru->redir_file || type == R_CLOSE)
      && handle_redir(instru->redir_type,
		      instru->redir_file) == ERR_STD)
    {
      exe->rt = ERR_STD;
      return (ERR_STD);
    }
  return (0);
}

int			shell(t_use_env *use_env,
			      t_cmd *shell_cmd, t_sys_cmd *sys_cmd)
{
  static t_s_exec	exe;
  t_in_cmd		in_cmd;
  t_def			*temp;
  int			i;

  decla(use_env, shell_cmd, &exe, sys_cmd);
  prompt(use_env->env);
  if (handler() == FALSE || get_input_cmd(&in_cmd) == ERR_FATAL)
    return (ERR_FATAL);
  i = 0;
  temp = in_cmd.separator;
  while (temp != NULL && in_cmd.instru != NULL)
    {
      if (redir(&in_cmd.instru[i], &exe, R_OPEN) == ERR_STD)
	break ;
      if (shell_exec(&exe, in_cmd.instru[i].av) != TRUE)
	return (exe.rt);
      if (redir(&in_cmd.instru[i++], &exe, R_CLOSE) == ERR_STD)
	break ;
      if ((temp->value == SEP_AND && exe.rt != 0)
	  || (temp->value == SEP_OR && exe.rt == 0))
	break ;
      temp = temp->next;
    }
  return (shell(use_env, shell_cmd, sys_cmd));
}
