/*****************************************************************************
* Model: OregonPlayer.qm
* File:  ./oregonPlayer.h
*
* This code has been generated by QM tool (see state-machine.com/qm).
* DO NOT EDIT THIS FILE MANUALLY. All your changes will be lost.
*
* This program is open source software: you can redistribute it and/or
* modify it under the terms of the GNU General Public License as published
* by the Free Software Foundation.
*
* This program is distributed in the hope that it will be useful, but
* WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
* or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License
* for more details.
*****************************************************************************/
/*${.::oregonPlayer.h} .....................................................*/
#ifndef oregonPlayer_h
#define oregonPlayer_h
#ifdef __cplusplus
extern "C" {
#endif
#include "qhsm.h"    /* include own framework tagunil version */

//Start of h code from diagram
#define HEALTHY 1
#define AGONY 2
#define DEAD 0
#define GHOUL_GOOD 3
#define GHOUL_WOUNDED 4
#define GHOUL_HEALING 5
#define BLESSED 6
#define FLASH_MS 200
#define FLASH_SEC 1010
#define FLASH_1M 60100
#define TIMEOUT_AGONY_S 600
#define TIMEOUT_DEATH_S 15
#define TIMEOUT_RADX_S 900
#define LONG_BEEP_MS 15000
#define MEDIUM_BEEP_MS 3000
#define SHORT_BEEP_MS 500
#define RED 255
#define RED_MEDIUM 127
#define GREEN_MEDIUN 127
#define BLUE_MEDIUM 127
#define DEFAULT_HP 27000
#define GHOUL_HP (DEFAULT_HP/3)
//End of h code from diagram



/*${SMs::OregonPlayer} .....................................................*/
typedef struct {
/* protected: */
    QHsm super;

/* public: */
    unsigned int CharHP;
    QStateHandler StartState;
    unsigned int TimerAgony;
} OregonPlayer;

/* protected: */
QState OregonPlayer_initial(OregonPlayer * const me, QEvt const * const e);
QState OregonPlayer_global(OregonPlayer * const me, QEvt const * const e);
QState OregonPlayer_active(OregonPlayer * const me, QEvt const * const e);
QState OregonPlayer_alive(OregonPlayer * const me, QEvt const * const e);
QState OregonPlayer_immune(OregonPlayer * const me, QEvt const * const e);
QState OregonPlayer_temp_immune(OregonPlayer * const me, QEvt const * const e);
QState OregonPlayer_blessed(OregonPlayer * const me, QEvt const * const e);
QState OregonPlayer_healthy(OregonPlayer * const me, QEvt const * const e);
QState OregonPlayer_agony(OregonPlayer * const me, QEvt const * const e);
QState OregonPlayer_ghoul(OregonPlayer * const me, QEvt const * const e);
QState OregonPlayer_ghoul_good(OregonPlayer * const me, QEvt const * const e);
QState OregonPlayer_ghoul_healing(OregonPlayer * const me, QEvt const * const e);
QState OregonPlayer_wounded(OregonPlayer * const me, QEvt const * const e);
QState OregonPlayer_dead(OregonPlayer * const me, QEvt const * const e);
QState OregonPlayer_test(OregonPlayer * const me, QEvt const * const e);

#ifdef DESKTOP
QState OregonPlayer_final(OregonPlayer * const me, QEvt const * const e);
#endif /* def DESKTOP */



static OregonPlayer oregonPlayer; /* the only instance of the OregonPlayer class */



typedef struct oregonPlayerQEvt {
    QEvt super;
    unsigned int value;
} oregonPlayerQEvt;

enum PlayerSignals {
TICK_SEC_SIG = Q_USER_SIG,

TIME_TICK_1S_SIG,
HEAL_SIG,
RAD_RCVD_SIG,
TIME_TICK_10S_SIG,
TIME_TICK_1M_SIG,
AGONY_SIG,
IMMUNE_SIG,
NOT_IMMUNE_SIG,
BLESSED_SIG,
TEST_TRIGGER_SIG,

PILL_ANY_SIG,
PILL_HEAL_SIG,
PILL_HEALSTATION_SIG,
PILL_BLESS_SIG,
PILL_CURSE_SIG,
PILL_ANTIRAD_SIG,
PILL_RAD_X_SIG,
PILL_GHOUL_SIG,
PILL_REMOVED_SIG,
PILL_RESET_SIG,
PILL_TEST_SIG,
PILL_GHOUL_REMOVED_SIG,

LAST_USER_SIG
};
extern QHsm * const the_oregonPlayer; /* opaque pointer to the oregonPlayer HSM */

/*${SMs::OregonPlayer_ctor} ................................................*/
void OregonPlayer_ctor(
    unsigned int HP,
    unsigned int State,
    unsigned int TimerAgony);

#ifdef __cplusplus
}
#endif
#endif /* oregonPlayer_h */
