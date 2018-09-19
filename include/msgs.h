/*
** msgs.h for  in /home/amaury/delivery/PSU_2016_minishell2
** 
** Made by Amaury Bernard
** Login   <amaury.bernard@epitech.eu>
** 
** Started on  Fri Apr  7 21:20:45 2017 Amaury Bernard
** Last update Sun May 21 11:43:21 2017 Nicolas Marsan
*/

#ifndef MSGS_H_
# define MSGS_H_

# define MSG_NOTFOUND		": Command not found.\n"
# define MSG_TOO_MANY		": Too many arguments.\n"
# define MSG_TOO_FEW		": Too few arguments.\n"
# define MSG_NO_HOME		": No home directory.\n"
# define MSG_NODIRFILE		": Not a directory.\n"
# define MSG_NO_PERM		": Permission denied.\n"

# define MSG_NOALPHANUM_1	": Variable name must contain"
# define MSG_NOALPHANUM_2	" alphanumeric characters.\n"
# define MSG_NOALPHANUM		MSG_NOALPHANUM_1 MSG_NOALPHANUM_2

# define SEGFAULT		"Segmentation fault\n"
# define ABORT			"Abort\n"
# define FPE			"Floating exception\n"
# define SEGFAULT_CD		"Segmentation fault (core dumped)\n"
# define ABORT_CD		"Abort (core dumped)\n"
# define FPE_CD			"Floating exception (core dumped)\n"

# define FILE_NOT_EXEC		"Binary file not executable.\n"

#endif /* !MSGS_H_ */
