# *****************************************************
# Henar Contreras
# Makefile de p6
# *****************************************************
# NOTES: it uses '>' as prefix of my recipes (.RECIPEPREFIX is set in line 11)
# since all actions of every Makefile's rule are identified by tabs and I do not
# use tabs in my file editor. Otherwise, I will get the 'missing separator' error.
#
# To check whether a tab character is used, run: cat -e -t -v Makefile
# It shows the presence of tabs (-t) with ^I and line endings (-e) with $
# *****************************************************

CC = g++
CFLAGS = -Wall -g
.RECIPEPREFIX = >

main: main.o alarm_security.o alarm_sensor.o login.o RGBCamara.o sensor_database.o \
      sensores.o user.o userdatabase.o admin.o AirQuality.o employee.o HumiditySens.o \
      LightSens.o TCamara.o TempSens.o ManejoExcept.o

>$(CC) $(CFLAGS) -o main main.o alarm_security.o alarm_sensor.o login.o RGBCamara.o \
sensor_database.o sensores.o user.o userdatabase.o admin.o AirQuality.o employee.o \
HumiditySens.o LightSens.o TCamara.o TempSens.o ManejoExcept.o


main.o: main.cpp alarm_security.h alarm_sensor.h login.h RGBCamara.h sensor_database.h \
        sensores.h user.h userdatabase.h admin.h AirQuality.h employee.h HumiditySens.h \
        LightSens.h TCamara.h ManejoExcept.h

>$(CC) $(CFLAGS) -c main.cpp

admin.o: admin.cpp admin.h user.h employee.h
>$(CC) $(CFLAGS) -c admin.cpp

AirQuality.o: AirQuality.cpp AirQuality.h sensores.h
>$(CC) $(CFLAGS) -c AirQuality.cpp

alarm_security.o: alarm_security.cpp alarm_security.h
>$(CC) $(CFLAGS) -c alarm_security.cpp

alarm_sensor.o: alarm_sensor.cpp alarm_sensor.h sensor_database.cpp sensor_database.h
>$(CC) $(CFLAGS) -c alarm_sensor.cpp

employee.o: employee.cpp employee.h user.h
>$(CC) $(CFLAGS) -c employee.cpp

HumiditySens.o: HumiditySens.cpp HumiditySens.h sensores.h
>$(CC) $(CFLAGS) -c HumiditySens.cpp

LightSens.o: LightSens.cpp LightSens.h sensores.h
>$(CC) $(CFLAGS) -c LightSens.cpp

login.o: login.cpp login.h userdatabase.h
>$(CC) $(CFLAGS) -c login.cpp

RGBCamara.o: RGBCamara.cpp RGBCamara.h sensores.h
>$(CC) $(CFLAGS) -c RGBCamara.cpp

sensor_database.o: sensor_database.cpp sensor_database.h sensores.h
>$(CC) $(CFLAGS) -c sensor_database.cpp

sensores.o: sensores.cpp sensores.h
>$(CC) $(CFLAGS) -c sensores.cpp

TCamara.o: TCamara.cpp TCamara.h sensores.h
>$(CC) $(CFLAGS) -c TCamara.cpp

TempsSens.o: TempSens.cpp TempSens.h sensores.h
>$(CC) $(CFLAGS) -c TempSens.cpp

user.o: user.cpp user.h
>$(CC) $(CFLAGS) -c user.cpp

userdatabase.o: userdatabase.cpp userdatabase.h
>$(CC) $(CFLAGS) -c userdatabase.cpp

ManejoExcept.o: ManejoExcept.cpp ManejoExcept.h
>$(CC) $(CFLAGS) -c ManejoExcept.cpp

clean:
>rm *.o main

