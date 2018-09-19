/*
** shell_exec.h for 42sh in /home/amaury/delivery/PSU_2016_42sh
** 
** Made by Amaury Bernard
** Login   <amaury.bernard@epitech.eu>
** 
** Started on  Sun May 21 18:19:28 2017 Amaury Bernard
** Last update Sun May 21 18:19:28 2017 Amaury Bernard
*/

#ifndef SHELL_EXEC_H_
# define SHELL_EXEC_H_

# define CMD_EXIT	0
# define R_OPEN		0
# define R_CLOSE	1

typedef struct		s_s_exec
{
  t_use_env		*use_env;
  t_cmd			*shell_cmd;
  t_sys_cmd		*sys_cmd;
  int			rt;
}			t_s_exec;

#endif /* !SHELL_EXEC_H_ */
