/*
 * onoffcore.h
 *
 *  Created on: 28 cze 2020
 *      Author: watchdoge
 */

#ifndef ONOFFCORE_H_
#define ONOFFCORE_H_

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
void onoffcore_set_ON_callback(void *ONcb);

/*
 * this function will be called when signal exceeds hysteresis_up
 * */
void onoffcore_set_OFF_callback(void *OFFcb);

/*
 * this function returns programmed target value
 * */
int onoffcore_read_target(int target);

/*
 * this function returns down tolerance value for controller
 * */
int onoffcore_read_hist_down(int hist_down);

/*
 * this function returns tolerance value for controller
 * */
int onoffcore_read_hist_up(int hist_up);

/*
 * this function returns value controller sees as signal value at the moment
 * */
int onoffcore_read_signal(int signal);

/*
 * this function runs controller logic, this has to be called periodically(i.e. each 1ms)
 * */
void onoffcore_run(void);


#endif /* ONOFFCORE_H_ */
