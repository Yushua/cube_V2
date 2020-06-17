#include "cube.h"

void        ft_error(t_struct_m *main)
{
    // main->place.error_c_n++; //makes it so no error isn't given afterwards
    //problem with input
    if (main->place.error_n < 0)
    {
        ft_putstr("Error\n");   
        main->place.error_n = 0;
    }
    if (main->place.error_c == 1)
    {
        ft_putstr("you got double lines, fix your map\n");//putstr
        main->place.check_double = 0;
    }
    else if (main->place.error_c == 2)
        ft_putstr("unknown input in map, or clutter fix your map\n");
    else if (main->place.error_c == 3)
        ft_putstr("unacceptable command in line R, fix your map\n");
    else if (main->place.error_c == 4)
        ft_putstr("unacceptable command in line NO, fix your map\n");
    else if (main->place.error_c == 5)
        ft_putstr("unacceptable command in line EA, fix your map\n");
    else if (main->place.error_c == 6)
        ft_putstr("unacceptable command in line S, fix your map\n");
    else if (main->place.error_c == 7)
        ft_putstr("unacceptable command in line SO, fix your map\n");
    else if (main->place.error_c == 8)
        ft_putstr("unacceptable command in line WE, fix your map\n");
    else if (main->place.error_c == 9)
        ft_putstr("unacceptable command in line F, fix your map\n");
    else if (main->place.error_c == 10)
        ft_putstr("unacceptable command in line C, fix your map\n");
    else if (main->place.error_c == 11)
        ft_putstr("INCORRECT input of position input, fix your map\n");
    else if (main->place.error_c == 12)
        ft_putstr("double inputs after inputs or wrong input, fix your map\n");
    else if (main->place.error_c == 12)
        ft_putstr("wrong input in map, can't read map, fix your map\n");
    else if (main->place.error_c == 13)
        ft_putstr("problem in malloc, try again\n");
    else if (main->place.error_c == 14)
        ft_putstr("problem in functions, line is NULL\n");
    else if (main->place.error_c == 15)
        ft_putstr("map incorrect, not surroudned by 1's, top or bottom wrong\n");
    else if (main->place.error_c == 16)
        ft_putstr("map incorrect, not surroudned by 1's, left side wrong\n");
    else if (main->place.error_c == 17)
        ft_putstr("map incorrect, not surroudned by 1's, right side wrong\n");
    else if (main->place.error_c == 18)
        ft_putstr("map incorrect\n");
    else if (main->place.error_c == 19)
        ft_putstr("link in map file incorrect at NO, fd is -1\n");
    else if (main->place.error_c == 20)
        ft_putstr("link in map file incorrect at SO, fd is -1\n");
    else if (main->place.error_c == 21)
        ft_putstr("link in map file incorrect at WE, fd is -1\n");
    else if (main->place.error_c == 22)
        ft_putstr("link in map file incorrect at EA, fd is -1");
    else if (main->place.error_c == 23)
        ft_putstr("link in map file incorrect at S, fd is -1");
    else if (main->place.error_c == 24)
        ft_putstr("error in fd, read map, fd < 0");
    else if (main->place.error_c == 25)
        ft_putstr("not all information was given, or map is in wrong location");
    else if (main->place.error_c == 26)
        ft_putstr("double R");
    else if (main->place.error_c == 27)
        ft_putstr("first set numbers in R is incorrect");
    else if (main->place.error_c == 28)
        ft_putstr("too many inputs in R, fix R");
    else if (main->place.error_c == 29)
        ft_putstr("double F");
    else if (main->place.error_c == 30)
        ft_putstr("too many inputs in F, fix F");
    else if (main->place.error_c == 31)
        ft_putstr("first set numbers in F is incorrect");
    else if (main->place.error_c == 32)
        ft_putstr("fnot enough inputs in R");
    else if (main->place.error_c == 33)
        ft_putstr("fnot enough inputs in C");
    else if (main->place.error_c == 34)
        ft_putstr("too many inputs in F, fix F");
    else if (main->place.error_c == 35)
        ft_putstr("double C");
    else if (main->place.error_c == 36)
        ft_putstr("double SO");
    else if (main->place.error_c == 37)
        ft_putstr("SO line has info after its link, fix line by removing this information");
    else if (main->place.error_c == 38)
        ft_putstr("double WE");
    else if (main->place.error_c == 39)
        ft_putstr("WE line has info after its link, fix line by removing this information");
    else if (main->place.error_c == 40)
        ft_putstr("double NO");
    else if (main->place.error_c == 41)
        ft_putstr("NO line has info after its link, fix line by removing this information");
    else if (main->place.error_c == 42)
        ft_putstr("double EA");
    else if (main->place.error_c == 43)
        ft_putstr("EA line has info after its link, fix line by removing this information");
    else if (main->place.error_c == 44)
        ft_putstr("double S");
    else if (main->place.error_c == 45)
        ft_putstr("S line has info after its link, fix line by removing this information");
    main->place.error_c = 0;
    //come sin ehre, error shoudl only happen once
}
