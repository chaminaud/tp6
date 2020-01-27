
#ifndef __BOMB__
#define __BOMB__


#include <stdlib.h>
#include <stdint.h>
#include "player.h"

typedef struct s_bomb
{
    /* si necessaire à completer */
} t_bomb;


void add_bomb(t_player *);
void bomb_init(void (*func)(t_bomb *b));
void bomb_turn(void);

#endif /* __BOMB__ */