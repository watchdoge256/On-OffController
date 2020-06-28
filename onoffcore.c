/*
 * onoffcore.c
 *
 *  Created on: 28 cze 2020
 *      Author: watchdoge
 */

static int ctrl_target;
static int ctrl_hysteresis_up;
static int ctrl_hysteresis_down;
static int ctrl_signal;

static void (*ONcallback)(void);
static void (*OFFcallback)(void);

int onoffcore_set_target(int target)
{
  ctrl_target = target;

  return 0;
}


int onoffcore_set_hist_down(int hyst_down)
{
  ctrl_hysteresis_down = hyst_down;

  return 0;
}


int onoffcore_set_hist_up(int hyst_up)
{
  ctrl_hysteresis_up = hyst_up;

  return 0;
}


int onoffcore_set_signal(int signal)
{
  ctrl_signal = signal;

  return 0;
}


int onoffcore_set_ON_callback(void *ONcb)
{
  ONcallback = ONcb;

  return 0;
}


int onoffcore_set_OFF_callback(void *OFFcb)
{
  OFFcallback = OFFcb;

  return 0;
}

int onoffcore_read_target(void)
{
  return ctrl_target;
}

int onoffcore_read_hist_down(void)
{
  return ctrl_hysteresis_down;
}

int onoffcore_read_hist_up(void)
{
  return ctrl_hysteresis_up;
}

int onoffcore_read_signal(void)
{
  return ctrl_signal;
}

void onoffcore_run(void)
{
  if (ctrl_signal < (ctrl_target - ctrl_hysteresis_down)){
    if(ONcallback){
      ONcallback();
    }
  }
  else if (ctrl_signal > (ctrl_target + ctrl_hysteresis_up)) {
    if (OFFcallback){
      OFFcallback();
    }
  }
}
