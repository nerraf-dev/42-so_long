// filepath: /home/simon/so_long/src/game/test_game_init.c
#include "../inc/so_long.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// Mocking MLX functions
void	*mlx_init(void)
{
	static int	call_count = 0;
	call_count++;
	if (call_count == 1) // Simulate success on first call
		return (malloc(1)); // Return a dummy pointer
	return (NULL); // Simulate failure on subsequent calls
}

void	*mlx_new_window(void *mlx, int width, int height, char *title)
{
	(void)mlx;
	(void)width;
	(void)height;
	(void)title;
	static int	call_count = 0;
	call_count++;
	if (call_count == 1) // Simulate success on first call
		return (malloc(1)); // Return a dummy pointer
	return (NULL); // Simulate failure on subsequent calls
}

void	mlx_destroy_window(void *mlx, void *win)
{
	(void)mlx;
	free(win);
}

void	mlx_destroy_display(void *mlx)
{
	(void)mlx;
}

void	free_mock(void *ptr)
{
	free(ptr);
}

// Test helper function
void	ft_assert(int condition, const char *message)
{
	if (condition)
		printf("PASS: %s\n", message);
	else
		printf("FAIL: %s\n", message);
}

// Test cases
void	test_run_game_success()
{
	t_context	context;
	t_game		game;

	memset(&context, 0, sizeof(context));
	memset(&game, 0, sizeof(game));
	context.game = &game;

	int result = run_game(&context);
	ft_assert(result == 0, "run_game initializes successfully");
	ft_assert(game.mlx != NULL, "mlx initialized");
	ft_assert(game.mlx_win != NULL, "mlx window created");

	// Cleanup
	close_window(&game);
}

void	test_run_game_mlx_init_fail()
{
	t_context	context;
	t_game		game;

	memset(&context, 0, sizeof(context));
	memset(&game, 0, sizeof(game));
	context.game = &game;

	// Simulate mlx_init failure
	mlx_init(); // First call succeeds
	int result = run_game(&context);
	ft_assert(result == 1, "run_game fails when mlx_init fails");
	ft_assert(game.mlx == NULL, "mlx is NULL on failure");
}

void	test_run_game_mlx_new_window_fail()
{
	t_context	context;
	t_game		game;

	memset(&context, 0, sizeof(context));
	memset(&game, 0, sizeof(game));
	context.game = &game;

	// Simulate mlx_new_window failure
	mlx_init(); // First call succeeds
	mlx_new_window(NULL, 0, 0, NULL); // First call succeeds
	int result = run_game(&context);
	ft_assert(result == 1, "run_game fails when mlx_new_window fails");
	ft_assert(game.mlx_win == NULL, "mlx window is NULL on failure");

	// Cleanup
	if (game.mlx)
		free_mock(game.mlx);
}

int	main(void)
{
	printf("Running tests for game_init.c...\n");
	test_run_game_success();
	test_run_game_mlx_init_fail();
	test_run_game_mlx_new_window_fail();
	return (0);
}// filepath: /home/simon/so_long/src/game/test_game_init.c
#include "../inc/so_long.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Mock functions for MiniLibX
void	*mlx_init(void)
{
	ft_printf("Mock: mlx_init called.\n");
	return (malloc(1)); // Simulate successful initialization
}

void	*mlx_new_window(void *mlx, int width, int height, char *title)
{
	(void)mlx;
	(void)width;
	(void)height;
	(void)title;
	ft_printf("Mock: mlx_new_window called.\n");
	return (malloc(1)); // Simulate successful window creation
}

void	mlx_destroy_window(void *mlx, void *win)
{
	(void)mlx;
	ft_printf("Mock: mlx_destroy_window called.\n");
	free(win);
}

void	mlx_destroy_display(void *mlx)
{
	ft_printf("Mock: mlx_destroy_display called.\n");
}

void	mlx_hook(void *win, int x_event, int x_mask, int (*funct)(), void *param)
{
	(void)win;
	(void)x_event;
	(void)x_mask;
	(void)funct;
	(void)param;
	ft_printf("Mock: mlx_hook called.\n");
}

// Test function
int	main(void)
{
	t_context	context;
	t_game		game;
	char		*map[] = {"1111", "1001", "1111", NULL};

	// Initialize mock context and game
	memset(&context, 0, sizeof(t_context));
	memset(&game, 0, sizeof(t_game));
	context.game = &game;
	game.map = map;

	// Run the game initialization
	ft_printf("Running run_game...\n");
	if (run_game(&context) != 0)
	{
		ft_printf("run_game failed.\n");
		return (1);
	}

	// Simulate closing the window
	ft_printf("Simulating close_window...\n");
	close_window(&game);

	ft_printf("All tests passed.\n");
	return (0);
}
