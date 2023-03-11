pp=g++
cc=gcc
lib=lwiringPi
exe=.out

LED_example_target=led_example

pwm_example_target=pwm_ex



all : 

	
$(LED_example_target)1 : 01_Example.cpp
	$(cc) -o $@$(exe) -DDEBUG=1 $^ -$(lib)
	sudo ./$@$(exe)

$(LED_example_target)2 : 01_Example.cpp
	$(cc) -o $@$(exe) -DDEBUG=2 $^ -$(lib)
	sudo ./$@$(exe)

$(LED_example_target)3 : 01_Example.cpp
	$(cc) -o $@$(exe) -DDEBUG=3 $^ -$(lib)
	sudo ./$@$(exe)
	
$(LED_example_target)4 : 01_Example.cpp
	$(cc) -o $@$(exe) -DDEBUG=4 $^ -$(lib)
	sudo ./$@$(exe)
	
PWM_EX01 : 02_PWM_EX01.cpp
	$(cc) -o $@$(exe) $^ -$(lib)
	
PWM_EX02 : 03_PWM_EX02.cpp
	$(cc) -o $@$(exe)$^ -$(lib)
	
PWM_EX03 : 04_PWM_EX03.cpp
	$(cc) -o $@$(exe) $^ -$(lib)
	
Buzzer_ex01 : 05_PWM_BUZZER_EX01.cpp
	$(cc) -o $@$(exe) $^ -$(lib)
	
Buzzer_ex02 : 06_PWM_BUZZER_EX02.cpp
	$(cc) -o $@$(exe) $^ -$(lib)
	
Servo_ex01 : 07_PWM_SERVO_EX01.cpp
	$(cc) -o $@$(exe) $^ -$(lib)
	sudo ./$@$(exe)
	
$(pwm_example_target)1 : 08_PWM_Example.cpp
	$(cc) -o $@$(exe) -DDEBUG=1 $^ -$(lib)
	sudo ./$@$(exe)

$(pwm_example_target)2 : 08_PWM_Example.cpp
	$(cc) -o $@$(exe) -DDEBUG=2 $^ -$(lib)


DREX1 : 09_DigitalRead_EX01.cpp
	$(cc) -o $@$(exe) $^ -$(lib)
	sudo ./$@$(exe)

DREX2 : 10_DigitalRead_EX02.cpp
	$(cc) -o $@$(exe) $^ -$(lib)
	sudo ./$@$(exe)



DRExample01 : 11_DigitalRead_Example01.cpp
	$(cc) -o $@$(exe) $^ -$(lib)
	sudo ./$@$(exe)

DRExample02 : 12_DigitalRead_Example02.cpp
	$(cc) -o $@$(exe) $^ -$(lib)
	sudo ./$@$(exe)


removeAll : 
	rm -rf *${exe}
