/*
** 42.h for 42sh in /home/nicolas/PSU_2016/PSU_2016_42sh/include
** 
** Made by Nicolas Marsan
** Login   <nicolas.marsan@epitech.eu>
** 
** Started on  Sun May 21 08:52:58 2017 Nicolas Marsan
** Last update Sun May 21 11:44:39 2017 Nicolas Marsan
*/

#ifndef SH_H_
# define SH_H_

# define TRUE		1
# define FALSE		0
# define NB_CMDS	5
# define ERR_FATAL	84
# define ERR_STD	1
# define ERR_NOTFOUND	1
# define ERR_EXEC	2
# define CTRLD		4
# define START_SIGNALS	128
# define CHAR_ALLOWED_1	"abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPKRSTUVW"
# define CHAR_ALLOWED_2	"XYZ0123456789-_/@#: "
# define CHAR_META	"\\()|[];&<>{}^$*+?\"\'"
# define CHAR_ALLOWED	CHAR_ALLOWED_1 CHAR_ALLOWED_2 CHAR_META
# define DEFAULT_PATH	"/bin"

# define EXEC_FORMAT_ERR	8
# define PERMISSION_DENIED	13

typedef struct		s_use_env
{
  char			**env;
  char			*pwd;
  char			*oldpwd;
  char			*host;
  char			*home;
}			t_use_env;

typedef struct		s_sys_cmd
{
  char			*cmd;
  char			*filename;
}			t_sys_cmd;

typedef struct	s_cmd
{
  char		*cmd;
  int		(*fct)(t_use_env *env, char **params);
}		t_cmd;

int		shell(t_use_env *use_env, t_cmd *shell_cmd, t_sys_cmd *sys_cmd);
int		handler();
void		control_c();

/*
**              (Builtins / Shell commands)
**                cmd_cd.c
**                cmd_env.c
**                cmd_echo.c
**                cmd_exit.c
**
**                cmd_setenv.c
*/

int		cmd_cd(t_use_env *use_env, char **argv);
int		cmd_env(t_use_env *env, char **argv);
int		cmd_echo(t_use_env *env, char **argv);
int		cmd_exit(char **env, char **argv, int *rt);

int		cmd_setenv(t_use_env *env, char **argv);
int		cmd_unsetenv(t_use_env *env, char **argv);

/*
**              !(Builtins / Shell commands)
*/

t_sys_cmd	*get_sys_cmds(char **env, char *home);
char		**path_failure();
t_use_env	*init_use_env(char **env);
char		*get_var_env(char *var_finder, char **env);
int		get_input_argv(char ***argv);
int		exec_shell_cmds(t_cmd *cmds, char **argv,
				t_use_env *env, int *rt);
int		exec_sys_cmds(t_sys_cmd *sys_cmd,
			      char **argv, char **env, int *rt);
int		exec_file(char **argv, char **env, int *rt);
char		**init_env(char **env);
int		nb_member_dble_tab(char **tab);
int		father(void);

/*
**              (Useful tools)
*/

char		*replace_home_char(char *str, char *home);
int		rt_with_msg(int to_rt, char *to_show1, char *to_show2);
int		my_get_nbr(char *str);
int		my_str_isnum(char *str);
int		my_str_isalphanum(char *check);
int		my_printf(char *str, ...);
char		*get_next_line(int fd);

/*
**              (Strings tools)
*/

int		my_strlen(char *str);
int		str_equal(char *str, char *str2);
int		str_begin_equal(char *str, char *str2);
int		str_are_equal(char *str, char *str2);
char		*my_2str_in1(char *str1, char *str2);
char		*my_strdup(char *str);

#endif /* !SH_H_ */
