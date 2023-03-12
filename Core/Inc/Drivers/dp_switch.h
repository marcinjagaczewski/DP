#pragma once

typedef enum dpSwitch_e
{
    DP1,
    DP2,
    DP_MAX,
}dpSwitch_t;

void setDp(dpSwitch_t dp);
