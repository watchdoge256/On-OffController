# OnOffController
This is sample implementation of On Off controller(bang bang controller) for microcontrollers Arduino, STM32 etc...

Principle of operation
===
```
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
```

Library Usage
====

The following code depicts the library basic usage, input and output functions should be provided by end user.
```
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
  // controller initial settings
  onoffcore_set_ON_callback(turnOnCB);
  onoffcore_set_OFF_callback(turnOFFcb);
  onoffcore_set_target(15);
  onoffcore_set_hist_up(5);
  onoffcore_set_hist_down(5);

  while(1){
    // in normal circumstances this function will be called by any interrupt, i.e. ADC reading done
    onoffcore_set_signal(signal);
    
    // this task need to be called periodically i.e. 1ms( could be implemented as OS task.
    onoffcore_run();
    signal+=change;
  }
  return 0;
}
```

## **API:**
### **onoffcore_set_target**
  this function sets target value which controller tries to achieve
  returns: 0- status success
  

### **onoffcore_set_hist_down**
  this function sets down tolerance values for controller
  returns: 0- status success

### **onoffcore_set_hist_up**
this function sets upper tolerance range for controller
returns: 0- status success

### **onoffcore_set_signal**
  this function sets actual value of signal to controller logic
  returns: 0- status success

### **onoffcore_set_ON_callback**
  this function will be called when signal drops bellow hysteresis_down
  returns: 0- status success

### **onoffcore_set_OFF_callback**
  this function will be called when signal exceeds hysteresis_up
  returns: 0- status success

### **onoffcore_read_target**
  this function returns programmed target value
  returns: 0- status success

### **onoffcore_read_hist_down**
  this function returns down tolerance value for controller
  returns: 0- status success
  
### **onoffcore_read_hist_up**
  this function returns tolerance value for controller
  returns: 0- status success

### **onoffcore_read_signal**
  this function returns value controller sees as signal value at the moment
  returns: 0- status success
  
### **onoffcore_run**
  this function runs controller logic, this has to be called periodically(i.e. each 1ms)
  
<meta name="google-site-verification" content="5XBeeN_SbOM_9cyVBWXsLmMMOzu49ADToPEScnca9fk" />
