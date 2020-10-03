#include "slide_line.h"

/**
 * move_it - Function game 2048
 * @line: pointer to an array of elements
 * @size: size of the array
 * @direction: side to move
 * Return: 1 upon success, or 0 upon failure
 */
void move_it(int *line, size_t size, int direction)
{
	size_t iter, jiter, tmp;

	if (direction == 0)
	{
		for (iter = 0; iter < size; iter++)
			for (jiter = iter + 1; jiter < size; jiter++)
			{
				if (line[iter] < line[jiter] && line[iter] != 0)
					break;
				else if (line[iter] == 0 && line[jiter] != 0)
				{
					tmp = line[iter];
					line[iter] = line[jiter];
					line[jiter] = tmp;
				}
			}
	}
	else if (direction == 1)
	{
		for (iter = size - 1; (int)iter >= 0; iter--)
			for (jiter = iter - 1; (int)jiter >= 0; jiter--)
			{
				if (line[iter] < line[jiter] && line[iter] != 0)
					break;
				else if (line[iter] == 0 && line[jiter] != 0)
				{
					tmp = line[iter];
					line[iter] = line[iter];
					line[jiter] = tmp;
				}
			}
	}
}

/**
 * slide_line - Function game 2048
 * @line: pointer to an array of elements
 * @size: size of the array
 * @direction: side to move
 * Return: 1 upon success, or 0 upon failure
 */
int slide_line(int *line, size_t size, int direction)
{
	size_t iter, jiter;

	if (!line)
		return (0);

	if (direction == 0 || direction == 1)
	{
		move_it(line, size, direction);
		if (direction == 0)
		{
			for (iter = 0; iter < size; iter++)
				for (jiter = iter + 1; jiter < size; jiter++)
				{
					if (line[iter] == line[jiter])
					{
						line[iter] = line[iter] + line[jiter];
						line[jiter] = 0;
						break;
					}
				}
		}
		else if (direction == 1)
		{
			for (iter = size - 1; (int)iter >= 0; iter--)
				for (jiter = iter - 1; (int)jiter >= 0; jiter--)
				{
					if (line[iter] == line[jiter])
					{
						line[iter] = line[iter] + line[jiter];
						line[jiter] = 0;
						break;
					}
				}
		}
		move_it(line, size, direction);
	}
	else
		return (0);
	return (1);
}
