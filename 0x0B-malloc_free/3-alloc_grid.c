#include "main.h"
#include <stdlib.h>
/**
 * alloc_grid - nested loop to make grid
 * @width: width input
 * @height: height input
 * Return: pointer to 2 dim. array
 */
int **alloc_grid(int width, int height)
{
	int **dc;
	int x, y;

	if (width <= 0 || height <= 0)
		return (NULL);

	dc = malloc(sizeof(int *) * height);

	if (dc == NULL)
		return (NULL);

	for (x = 0; x < height; x++)
	{
		dc[x] = malloc(sizeof(int) * width);

		if (dc[x] == NULL)
		{
			for (; x >= 0; x--)
				free(dc[x]);

			free(dc);
			return (NULL);
		}
	}

	for (x = 0; x < height; x++)
	{
		for (y = 0; y < width; y++)
			dc[x][y] = 0;
	}

	return (dc);
}
