#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>

// Temporary map until we have parsing
static char MAP[6][6] = {
    {'1', '1', '1', '1', '1', '1'},
    {'1', '1', '0', '1', '0', '1'},
    {'1', '0', '0', '1', '0', '1'},
    {'1', '0', '0', '0', '0', '1'},
    {'1', '0', 'P', '0', '0', '1'},
    {'1', '1', '1', '1', '1', '1'}
};

typedef struct s_player
{
    double x;
    double y;
    double angle;
} t_player;

#endif
