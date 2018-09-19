/*
** get_sys_cmds.c for mysh in /home/amaury/delivery/PSU_2016_minishell2
** 
** Made by Amaury Bernard
** Login   <amaury.bernard@epitech.eu>
** 
** Started on  Wed Apr  5 17:19:49 2017 Amaury Bernard
** Last update Sun May 21 09:00:58 2017 Nicolas Marsan
*/

#include <sys/types.h>
#include <dirent.h>
#include <stdlib.h>
#include "sh.h"

static char	*nb_path_n_dup(char *path, int *nb)
{
  char		*dup;
  int		i;

  i = 0;
  *nb = 1;
  if (!(dup = malloc(sizeof(char) * (my_strlen(path) + 1))))
    return (NULL);
  while (path[i] != 0)
    {
      if (path[i] == ':')
	*nb += 1;
      dup[i] = path[i];
      ++i;
    }
  dup[i] = 0;
  return (dup);
}

/*
** Gerer la ~
*/
static char	**get_path(char **env)
{
  char		*path;
  char		**cuted_path;
  int		n;
  int		i;
  int		j;

  if ((path = get_var_env("PATH=", env)) == NULL
      || (*path == 0)
      || (!(path = nb_path_n_dup(path, &n)))
      || ((cuted_path = malloc(sizeof(char *) * (n + 1))) == NULL))
    return (NULL);
  j = 0;
  cuted_path[0] = path;
  i = 1;
  while (path[j] != '\0')
    {
      if (path[j] == ':' && path[j + 1] != 0)
	{
	  path[j] = 0;
	  cuted_path[i++] = &path[j + 1];
	}
      ++j;
    }
  cuted_path[i] = NULL;
  return (cuted_path);
}

static int	get_nb_sys_cmd(char **path)
{
  int		n;
  DIR		*bin_dir;
  struct dirent	*bin_file;

  n = 0;
  while (*path != NULL)
    {
      if ((bin_dir = opendir(*path)) != NULL)
	{
	  while ((bin_file = readdir(bin_dir)) != NULL)
	    {
	      if (bin_file->d_name[0] != '.')
		++n;
	    }
	  if (closedir(bin_dir) == -1)
	    return (-1);
	}
      ++path;
    }
  return (n);
}

static void	set_sys_cmd_per_path(char *path, t_sys_cmd *sys_cmd, int *n)
{
  DIR		*bin_dir;
  struct dirent	*bin_file;

  if ((bin_dir = opendir(path)) != NULL)
    {
      while ((bin_file = readdir(bin_dir)) != NULL)
	{
	  if (bin_file->d_name[0] != '.')
	    {
	      sys_cmd[*n].cmd = my_strdup(bin_file->d_name);
	      sys_cmd[*n].filename = my_2str_in1(path, bin_file->d_name);
	      *n += 1;
	    }
	}
      if (closedir(bin_dir) == -1)
	exit(ERR_FATAL);
    }
}

t_sys_cmd	*get_sys_cmds(char **env, char *home)
{
  char		**path;
  t_sys_cmd	*sys_cmd;
  int		n;
  int		i;

  if (!(path = get_path(env)))
    path = path_failure();
  if ((n = get_nb_sys_cmd(path)) == -1
      || !(sys_cmd = malloc(sizeof(t_sys_cmd) * (n + 1))))
    return (NULL);
  n = 0;
  i = -1;
  while (path[++i] != NULL)
    {
      path[i] = replace_home_char(path[i], home);
      set_sys_cmd_per_path(path[i], sys_cmd, &n);
    }
  sys_cmd[n].cmd = NULL;
  free(*path);
  free(path);
  return (sys_cmd);
}
