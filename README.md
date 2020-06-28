# OnOffController
This is sample implementation of On Off controller(bang bang controller) for microcontrollers Arduino, STM32 etc...


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
