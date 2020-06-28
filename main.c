/*
 * main.c
 *
 *  Created on: 27 cze 2020
 *      Author: watchdoge
 */
#include <stdio.h>
#include "onoffcore.h"

static int signal = 10;
static int change = -1;
void turnOnCB(void)
{
  change = 1;
}

void turnOFFcb(void)
{
  change = -1;
}

int main(void)
{
  // input signal

  // controller initial settings
  onoffcore_set_ON_callback(turnOnCB);
  onoffcore_set_OFF_callback(turnOFFcb);
  onoffcore_set_target(15);
  onoffcore_set_hist_up(5);
  onoffcore_set_hist_down(5);

  while(1){
    onoffcore_set_signal(signal);
    onoffcore_run();
    signal+=change;
  }
  return 0;
}
