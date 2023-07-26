#include "main.h"

/**
 * DisplayPrompt - displays my shell prompt
 */

void DisplayPrompt(void)
{
	write(STDOUT_FILENO, "$ ", 2);
}
