#include "cube.h"

#define D 2
#define A 0
#define W 13
#define S 1
#define esc 53

int             wasd_2(int keycode, t_struct_m *main)
{
	double moveSpeed = 0.1;
	double rotSpeed = 0.1;
    printf("keycode == %d\n", keycode);
    if (keycode > 0)
        background(main);
    if (keycode == 99)//C
    {
        main->place.crouch == 1;
        printf("C pressed\n");
    }
    if (keycode == W || keycode == 119)
    {
        if(main->place.cubemap[(int)(main->Ray.posY)][(int)(main->Ray.posX + main->Ray.dirX * moveSpeed)] != '1')
            main->Ray.posX += main->Ray.dirX * moveSpeed;
        if(main->place.cubemap[(int)(main->Ray.posY + main->Ray.dirY * moveSpeed)][(int)(main->Ray.posX)] != '1')
            main->Ray.posY += main->Ray.dirY * moveSpeed;
    }
    else if (keycode == S || keycode == 115)
    {
        if(main->place.cubemap[(int)(main->Ray.posY)][(int)(main->Ray.posX - main->Ray.dirX * moveSpeed)] != '1')
            main->Ray.posX -= main->Ray.dirX * moveSpeed;
        if(main->place.cubemap[(int)(main->Ray.posY - main->Ray.dirY * moveSpeed)][(int)(main->Ray.posX)] != '1')
            main->Ray.posY -= main->Ray.dirY * moveSpeed;        
    }
    else if (keycode == D || keycode == 100)
    {
        double oldDirX = main->Ray.dirX;

        main->Ray.dirX = main->Ray.dirX * cos(rotSpeed) - main->Ray.dirY * sin(rotSpeed);
        main->Ray.dirY = oldDirX * sin(rotSpeed) + main->Ray.dirY * cos(rotSpeed);

        double oldplanex = main->Ray.planeX;
                            
        main->Ray.planeX = main->Ray.planeX * cos(rotSpeed) - main->Ray.planeY * sin(rotSpeed);
        main->Ray.planeY = oldplanex * sin(rotSpeed) + main->Ray.planeY * cos(rotSpeed);        
    }
    else if (keycode == A || keycode == 97)
    {
        //both camera direction and camera plane must be rotated
        double olddirx = main->Ray.dirX;

        main->Ray.dirX = main->Ray.dirX * cos(-rotSpeed) - main->Ray.dirY * sin(-rotSpeed);
        main->Ray.dirY = olddirx * sin(-rotSpeed) + main->Ray.dirY * cos(-rotSpeed);

        double oldplanex = main->Ray.planeX;
                            
        main->Ray.planeX = main->Ray.planeX * cos(-rotSpeed) - main->Ray.planeY * sin(-rotSpeed);
        main->Ray.planeY = oldplanex * sin(-rotSpeed) + main->Ray.planeY * cos(-rotSpeed);        
    }
    if (keycode == esc || keycode == 65307)
    {
        mlx_destroy_window(main->vars.mlx, main->vars.win);
        exit(0);
    }
    return (0);
}