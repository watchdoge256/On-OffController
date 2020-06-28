# OnOffController
This is sample implementation of On Off controller(bang bang controller) for microcontrollers Arduino, STM32 etc...



/**************************************************************
*                    ^Signal value                            *
*                    |                                        *
*                    |                                        *
*                    |                                        *
*                    |           X                            *
*                 +----------------------------------------+  *
*   hysteresis up ^  |         X   X           X              *
*                 v  |        X     X         X               *
*          target +----------------------------------------+  *
*                 ^  |      X         X     X                 *
* hysteresis down v  |     X           X   X                  *
*                 +----------------------------------------+  *
*                    |   X               X                    *
*                    |  X                                     *
*                    | X                                      *
*                    |X                                       *
*                    -------------------------------------->  *
*                                                       time  *
***************************************************************/

API:
/*
 * this function sets target value which controller tries to achieve
 * returns: 0- status success
 * */
int onoffcore_set_target(int target);

/*
 * this function sets down tolerance values for controller
 * */
int onoffcore_set_hist_down(int hist_down);

/*
 * this function sets upper tolerance range for controller
 * */
int onoffcore_set_hist_up(int hist_up);

/*
 * this function sets actual value of signal to controller logic
 * */
int onoffcore_set_signal(int signal);

/*
 * this function will be called when signal drops bellow hysteresis_down
 * */
onoffcore_set_ON_callback

/*
 * this function will be called when signal exceeds hysteresis_up
 * */
 onoffcore_set_OFF_callback

/*
 * this function returns programmed target value
 * */
onoffcore_read_target

/*
 * this function returns down tolerance value for controller
 * */
onoffcore_read_hist_down

/*
 * this function returns tolerance value for controller
 * */
onoffcore_read_hist_up

/*
 * this function returns value controller sees as signal value at the moment
 * */
onoffcore_read_signal

/*
 * this function runs controller logic, this has to be called periodically(i.e. each 1ms)
 * */
onoffcore_run
