#include "libft/libft.h"
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>

void	signal_throw(int pid, unsigned char character)
{
	int				i;
	unsigned char	tmp;
	int				killret;

	i = 8;
	tmp = character;
	while (i > 0)
	{
		i--;
		tmp = character >> i;
		if (tmp % 2 == 0)
			killret = kill(pid, SIGUSR2);
		else
			killret = kill(pid, SIGUSR1);
		usleep(500);
	}
	if (killret == -1)
	{
		write(2, "Error\n", 6);
		exit(1);
	}
}

void	read_signal(int signal)
{
	if (signal == SIGUSR1)
		write(1, "delivered bit;\t1\n", 17);
	else if (signal == SIGUSR2)
		write(1, "delivered bit;\t0\n", 17);
}

int	main(int argc, char *argv[])
{
	pid_t		server_pid;
	int			i;

	if (argc != 3)
		exit(0);
	signal(SIGUSR2, read_signal);
	signal(SIGUSR1, read_signal);
	server_pid = ft_atoi(argv[1]);
	i = 0;
	while (argv[2][i])
		signal_throw(server_pid, argv[2][i++]);
	signal_throw(server_pid, 0);
	return (0);
}
