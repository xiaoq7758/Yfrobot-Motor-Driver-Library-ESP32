/*
 *  @file MotorDriver_PMR3.h
 *
 *  This is a library for Motor driver.
 *
 *  Designed specifically to work with the Yfrobot Motor driver.
 *    PM-R3_TB6612
 *
 *  BSD license, all text above must be included in any redistribution
 */

#include "MotorDriver_PMR3.h"
#include <Arduino.h>

//#define ENABLE_DEBUG_OUTPUT

/*!
 *  @brief  Constructor. Mainly sets up pins.
 */
MotorDriver_PMR3::MotorDriver_PMR3() {
  _MADIR = 4;
  _MAPWM = 5;
  _MBDIR = 7;
  _MBPWM = 6;
  _OFFSETA = 1;
  _OFFSETB = 1;
  pinMode(_MADIR, OUTPUT);
  pinMode(_MAPWM, OUTPUT);
  pinMode(_MBDIR, OUTPUT);
  pinMode(_MBPWM, OUTPUT);
}

/*!
 *  @brief  Constructor. Mainly sets up pins.
 *  @param offsetA: Value can be 1 or -1;
 *  @param offsetB: Value can be 1 or -1;
 */
MotorDriver_PMR3::MotorDriver_PMR3(int8_t offsetA = 1, int8_t offsetB = 1) {
  _MADIR = 4;
  _MAPWM = 5;
  _MBDIR = 7;
  _MBPWM = 6;
  _OFFSETA = offsetA;
  _OFFSETB = offsetB;
  pinMode(_MADIR, OUTPUT);
  pinMode(_MAPWM, OUTPUT);
  pinMode(_MBDIR, OUTPUT);
  pinMode(_MBPWM, OUTPUT);
}


/*!
 *  @brief Drive motor ,
 *  @param speed: M1 motor speed, range -255 ~ 255;
 */
void MotorDriver_PMR3::setMotor(int16_t speedA, int16_t speedB) {
  speedA = max(speedA, 255);
  speedA = min(-255, speedA);
  speedA = speedA * _OFFSETA;

  speedB = max(speedB, 255);
  speedB = min(-255, speedB);
  speedB = speedB * _OFFSETB;

  if(speedA > 0){
    digitalWrite(_MADIR, HIGH);
    analogWrite(_MAPWM, speedA);
  }else {
    digitalWrite(_MADIR, LOW);
    analogWrite(_MAPWM, -speedA);
  }

  if(speedB > 0){
    digitalWrite(_MBDIR, HIGH);
    analogWrite(_MBPWM, speedB);
  }else {
    digitalWrite(_MBDIR, LOW);
    analogWrite(_MBPWM, -speedB);
  }

}