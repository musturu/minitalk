#include "libft/libft.h"
#include <signal.h>
#include <unistd.h>

void	handle_signal(int signal)
{
	static unsigned char	c;
	static int				biti;

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
}

int	main(void)
{
	write(1, "PID ->\t", 7);
	ft_putnbr_fd(getpid(), 1);
	write(1, "\n[LISTENING]\n", 13);
	signal(SIGUSR1, handle_signal);
	signal(SIGUSR2, handle_signal);
	while (1)
		pause();
	return (0);
}
