#include "service.h"

const KeyStroke KeyStrokes[]= {
{    TIME_TICK_1S_SIG,      "TIME_TICK_1S",      't'},
{    HEAL_SIG,              "HEAL",              'h'},
{    RAD_RCVD_SIG,          "RAD_RCVD",          'r'},
{    TIME_TICK_10S_SIG,     "TIME_TICK_10S",     't'},
{    TIME_TICK_1M_SIG,      "TIME_TICK_1M",      't'},
{    AGONY_SIG,             "AGONY",             'a'},
{    IMMUNE_SIG,            "IMMUNE",            'i'},
{    PILL_GHOUL_SIG,        "PILL_GHOUL",        'p'},
{    PILL_REMOVED_SIG,      "PILL_REMOVED",      'p'},
{    NOT_IMMUNE_SIG,        "NOT_IMMUNE",        'n'},
{    BLESSED_SIG,           "BLESSED",           'b'},
{    PILL_RESET_SIG,        "PILL_RESET",        'p'},
{    PILL_TEST_SIG,         "PILL_TEST",         'p'},
{    TEST_TRIGGER_SIG,      "TEST_TRIGGER",      't'},
{    TERMINATE_SIG,               "TERMINATE",                 0x1B   }

};

unsigned int KeyNumber() {
	return sizeof(KeyStrokes)/sizeof(KeyStrokes[0]);
}
