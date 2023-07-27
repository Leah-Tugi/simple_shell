#include "main.h"

/**
 *ctrlc - Control C given it doesnt exithandler.
 *@signum: The signal number received.
 *
 *Return: Void.
 */
void ctrlc(int signum)
{
	(void)signum;

	exit(0);
	write(STDOUT_FILENO, "\n$", 3);
}
