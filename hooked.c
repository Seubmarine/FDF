#include "fdf.h"

void	mlx_context_free(t_mlx_info *context)
{
	mlx_destroy_image(context->mlx_ptr, context->img.ptr);
	mlx_destroy_window(context->mlx_ptr, context->win_ptr);
	mlx_destroy_display(context->mlx_ptr);
	free(context->mlx_ptr);
}

int	key_exit(int keycode, t_mlx_info *mlx_info)
{
	printf("keycode : %d as been released\n", keycode);
	if (keycode == 114)
		mlx_clear_window(mlx_info->mlx_ptr, mlx_info->win_ptr);
	else if (keycode == 65307 || keycode == 113 || keycode == 65477)
	{
		mlx_context_free(mlx_info);
		exit(0);
	}
	return (0);
}
