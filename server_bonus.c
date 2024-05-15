#include "libft/libft.h"
#include <bits/types/siginfo_t.h>
#include <signal.h>
#include <stdio.h>
#include <unistd.h>

void	signal_decoder(int signal, siginfo_t *info, void *context)
{
	static unsigned char	c;
	static int				biti;

	(void)context;
	c |= (signal == SIGUSR1);
	biti++;
	if (biti == 8)
	{
		if (c == '\0')
			c = '\n';
		write(1, &c, 1);
		biti = 0;
		c = 0;
	}
	else
		c <<= 1;
	kill(info->si_pid, signal);
}

int	main(void)
{
	struct sigaction	sa;

	sa.sa_sigaction = &signal_decoder;
	sa.sa_flags = SA_SIGINFO;
	sigemptyset(&sa.sa_mask);
	write(1, "PID ->\t", 7);
	ft_putnbr_fd(getpid(), 1);
	write(1, "\n[LISTENING]\n", 13);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
	return (0);
}
