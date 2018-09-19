/*
** cmds.h for  in /home/amaury/delivery/PSU_2016_42sh
** 
** Made by Amaury Bernard
** Login   <amaury.bernard@epitech.eu>
** 
** Started on  Tue May 16 18:41:40 2017 Amaury Bernard
** Last update Wed May 17 15:30:55 2017 Nicolas Marsan
*/

#ifndef CMD_H_
# define CMD_H_

typedef struct	s_def
{
  char		value;
  struct s_def	*next;
}		t_def;

/*
** Exemple of REDIR_* utilisations:
**
**   REDIR_OUT: ls > file.txt
**   REDIR_OUT2: ls >> file.txt
**   REDIR_IN: sh < file.txt
**   REDIR_IN2: 2
*/

# define REDIR_STR_OUT	">"
# define REDIR_STR_OUT2	">>"
# define REDIR_STR_IN	"<"
# define REDIR_STR_IN2	"<<"

# define REDIR_OUT	1
# define REDIR_OUT2	2
# define REDIR_IN	3
# define REDIR_IN2	4

typedef struct	s_instru
{
  char		**av;
  char		redir_type;
  char		*redir_file;
}		t_instru;

/*
** Exemple of SEPARATOR
**   SEP_AND: ls && echo
**   SEP_OR: ls || echo
**   SEP_POINT: ls ; echo
**   SEP_PIPE: ls | echo
*/

# define SEP_STR_AND	"&&"
# define SEP_STR_OR	"||"
# define SEP_STR_POINT	";"
# define SEP_STR_PIPE	"|"

# define SEP_AND	1
# define SEP_OR		2
# define SEP_POINT	3
# define SEP_PIPE	4
# define SEP_END	5

typedef struct	s_in_cmd
{
  t_instru	*instru;
  t_def		*separator;
}		t_in_cmd;

/*
** The return of the input command will be a t_in_cmds type.
** it contain an t_istru tab with the instructions
*/

int		handle_separator(t_in_cmd *cmd, char **argv);
int		get_input_cmd(t_in_cmd *cmd);

#endif /* !CMD_H_ */
