
#include "actions.h"
#include "player.h"
#include "param.h"
#include "world.h"
#include "bomb.h"

#define  DASH_LENGTH 8

static void (*pf_actions[ACTION_NUMBER])(t_player* p_player) = {0};

/* ------------------------------------------------------------------------- */
/*                                                                           */
/* ------------------------------------------------------------------------- */
void action_still(t_player *p_player)
{
    p_player->credits--;
}

/* ------------------------------------------------------------------------- */
/*                                                                           */
/* ------------------------------------------------------------------------- */
void action_move_l(t_player *p_player)
{
    p_player->x = (p_player->x == 0) ? MAP_SIZE - 1 : p_player->x - 1;
    p_player->credits--;
#ifdef DEBUG
    printf("ml%d\n", p_player->x);
#endif
    world_paint_spot(p_player->x, p_player->y, p_player->id);
}

/* ------------------------------------------------------------------------- */
/*                                                                           */
/* ------------------------------------------------------------------------- */
void action_move_r(t_player *p_player)
{
}

/* ------------------------------------------------------------------------- */
/*                                                                           */
/* ------------------------------------------------------------------------- */
void action_move_u(t_player *p_player)
{

}

/* ------------------------------------------------------------------------- */
/*                                                                           */
/* ------------------------------------------------------------------------- */
void action_move_d(t_player *p_player)
{

}

/* ------------------------------------------------------------------------- */
/*                                                                           */
/* ------------------------------------------------------------------------- */
void action_dash_l(t_player *p_player)
{

}

/* ------------------------------------------------------------------------- */
/*                                                                           */
/* ------------------------------------------------------------------------- */
void action_dash_r(t_player *p_player)
{
}

/* ------------------------------------------------------------------------- */
/*                                                                           */
/* ------------------------------------------------------------------------- */
void action_dash_u(t_player *p_player)
{
    /*DASH_LENGTH */

}

/* ------------------------------------------------------------------------- */
/*                                                                           */
/* ------------------------------------------------------------------------- */
void action_dash_d(t_player *p_player)
{
}

/* ------------------------------------------------------------------------- */
/*                                                                           */
/* ------------------------------------------------------------------------- */
void action_teleport_l(t_player *p_player)
{

}

/* ------------------------------------------------------------------------- */
/*                                                                           */
/* ------------------------------------------------------------------------- */
void action_teleport_r(t_player *p_player)
{

}

/* ------------------------------------------------------------------------- */
/*                                                                           */
/* ------------------------------------------------------------------------- */
void action_teleport_u(t_player *p_player)
{

}

/* ------------------------------------------------------------------------- */
/*                                                                           */
/* ------------------------------------------------------------------------- */
void action_teleport_d(t_player *p_player)
{

}

/* ------------------------------------------------------------------------- */
/*                                                                           */
/* ------------------------------------------------------------------------- */
void action_splash(t_player *p_player)
{

}

/* ------------------------------------------------------------------------- */
/*                                                                           */
/* ------------------------------------------------------------------------- */
void action_bomb(t_player *p_player)
{
    add_bomb(p_player);
    p_player->credits -= 9 ;
}

/* ------------------------------------------------------------------------- */
/*                                                                           */
/* ------------------------------------------------------------------------- */
void actions_init(void)
{
    pf_actions[ACTION_STILL] =  action_still;
    pf_actions[ACTION_MOVE_L] = action_move_l;
    /* a completer */
}

/* ------------------------------------------------------------------------- */
/*                                                                           */
/* ------------------------------------------------------------------------- */
void actions_do(t_player *p_player, enum action act_id)
{
    if (pf_actions[act_id] != NULL)
        pf_actions[act_id](p_player);
}
