#include "cube.h"

int             wasd_2(t_struct_m *main)
{
	double moveSpeed = 0.07;
	double rotSpeed = 0.07;
    if (main->keys.W)
    {
        if(main->place.cubemap[(int)(main->Ray.posY)][(int)(main->Ray.posX + main->Ray.dirX * moveSpeed)] != '1')
            main->Ray.posX += main->Ray.dirX * moveSpeed;
        if(main->place.cubemap[(int)(main->Ray.posY + main->Ray.dirY * moveSpeed)][(int)(main->Ray.posX)] != '1')
            main->Ray.posY += main->Ray.dirY * moveSpeed;
    }
    if (main->keys.S)
    {
        if(main->place.cubemap[(int)(main->Ray.posY)][(int)(main->Ray.posX - main->Ray.dirX * moveSpeed)] != '1')
            main->Ray.posX -= main->Ray.dirX * moveSpeed;
        if(main->place.cubemap[(int)(main->Ray.posY - main->Ray.dirY * moveSpeed)][(int)(main->Ray.posX)] != '1')
            main->Ray.posY -= main->Ray.dirY * moveSpeed;        
    }
    if (main->keys.D)
    {
        double oldDirX = main->Ray.dirX;

        main->Ray.dirX = main->Ray.dirX * cos(rotSpeed) - main->Ray.dirY * sin(rotSpeed);
        main->Ray.dirY = oldDirX * sin(rotSpeed) + main->Ray.dirY * cos(rotSpeed);

        double oldplanex = main->Ray.planeX;
                            
        main->Ray.planeX = main->Ray.planeX * cos(rotSpeed) - main->Ray.planeY * sin(rotSpeed);
        main->Ray.planeY = oldplanex * sin(rotSpeed) + main->Ray.planeY * cos(rotSpeed);        
    }
    if (main->keys.A)
    {
        //both camera direction and camera plane must be rotated
        double olddirx = main->Ray.dirX;

        main->Ray.dirX = main->Ray.dirX * cos(-rotSpeed) - main->Ray.dirY * sin(-rotSpeed);
        main->Ray.dirY = olddirx * sin(-rotSpeed) + main->Ray.dirY * cos(-rotSpeed);

        double oldplanex = main->Ray.planeX;
                            
        main->Ray.planeX = main->Ray.planeX * cos(-rotSpeed) - main->Ray.planeY * sin(-rotSpeed);
        main->Ray.planeY = oldplanex * sin(-rotSpeed) + main->Ray.planeY * cos(-rotSpeed);        
    }
    if (main->keys.LEF)
    {
        //both camera direction and camera plane must be rotated
        double olddirx = main->Ray.dirX;

        main->Ray.dirX = main->Ray.dirX * cos(-rotSpeed) - main->Ray.dirY * sin(-rotSpeed);
        main->Ray.dirY = olddirx * sin(-rotSpeed) + main->Ray.dirY * cos(-rotSpeed);

        double oldplanex = main->Ray.planeX;
                            
        main->Ray.planeX = main->Ray.planeX * cos(-rotSpeed) - main->Ray.planeY * sin(-rotSpeed);
        main->Ray.planeY = oldplanex * sin(-rotSpeed) + main->Ray.planeY * cos(-rotSpeed);        
    }
        if (main->keys.RIG)
    {
        double oldDirX = main->Ray.dirX;

        main->Ray.dirX = main->Ray.dirX * cos(rotSpeed) - main->Ray.dirY * sin(rotSpeed);
        main->Ray.dirY = oldDirX * sin(rotSpeed) + main->Ray.dirY * cos(rotSpeed);

        double oldplanex = main->Ray.planeX;
                            
        main->Ray.planeX = main->Ray.planeX * cos(rotSpeed) - main->Ray.planeY * sin(rotSpeed);
        main->Ray.planeY = oldplanex * sin(rotSpeed) + main->Ray.planeY * cos(rotSpeed);        
    }
    return (0);
}