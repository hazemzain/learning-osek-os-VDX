|=-----=[ Blink example with event  ]=-----=|

This application is  constant of 4 task 
task 1 has name SWC1_Init which have a piese of code which toggle RED led   .
task 2 has name SWC2_Init which have a piese of code which toggle orange led and dactive anathor task SWC1_MainTask   .
task 3 has name SWC1_MainTask which have apiece of code to read the utton and set event 
task 4 has name SWC2_MainTask whih have ahight priorty but it in waiting state becouse it wait for event an will wor when this even is set  
Have a look into "blink.oil" file.





This task is activated by the alarm "blink_blink".
This alarm starts 250ms (ALARMTIME) after "StartOS".
This alarm has a 250ms (CYCLETIME) period.

Configure the application with

`
goil --target=cortex/armv7em/stm32f407/stm32f4discovery --templates=../../../../../../goil/templates/ blink.oil
`
