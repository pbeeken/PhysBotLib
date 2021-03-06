/***********************************************************************
 * Exp8_1_AccelerometerRead -- RedBot Experiment 8.1
 *
 * Measuring speed, velocity, and acceleration are all key
 * components to robotics. This first experiment will introduce
 * you to using the Accelerometer sensor on the RedBot.
 *
 * Hardware setup:
 * You'll need to attach the RedBot Accelerometer board to hader on the upper
 * right side of the mainboard. See the manual for details on how to do this.
 *
 * This sketch was written by SparkFun Electronics, with lots of help from
 * the Arduino community. This code is completely free for any use.
 *
 * 8 Oct 2013 M. Hord
 * Revised, 31 Oct 2014 B. Huang
 *
 * 8 Oct 2013 M. Hord
 *
 * This experiment was inspired by Paul Kassebaum at Mathworks, who made
 * one of the very first non-SparkFun demo projects and brought it to the
 * 2013 Open Hardware Summit in Boston. Thanks Paul!
 ***********************************************************************/
#include <Streaming.h>
#include <PhysBotLib.h>
#include <PhysBotAccel.h>

PhysBotMotors motors;

// The RedBot library includes support for the accelerometer. We've tried
// to make using the accelerometer as easy as to use as possible.

// Set a timer to stop after a while
unsigned long startTime = 0L;

PhysBotAccel accelerometer;

void setup(void)
{
	Serial.begin(115200);
	startTime = millis();
	accelerometer.enableBump();
	Serial << endl;
	accelerometer.setZero();
}

void loop(void)
{
	accelerometer.update(); // updates the x, y, and z axis readings on the acceleromter

	if ( millis() < startTime + 10*1000 ) { // For 5 seconds we output

	  // Display out the X, Y, and Z - axis "acceleration" measurements and also
	  // the relative angle between the X-Z, Y-Z, and X-Y vectors. (These give us
	  // the orientation of the RedBot in 3D space.

		Serial << "{{ " << accelerometer.getRawX();
		Serial << ",\t" << accelerometer.getRawY();
		Serial << ",\t" << accelerometer.getRawZ() << "}, ";

		Serial << "{ "  << accelerometer.getAccelX();
		Serial << ",\t" << accelerometer.getAccelY();
		Serial << ",\t" << accelerometer.getAccelZ() << "}, ";

		Serial << "{ "  << _FLOAT( accelerometer.getAngleXZ(), 1 );
		Serial << ",\t" << _FLOAT( accelerometer.getAngleYZ(), 1 );
		Serial << ",\t" << _FLOAT( accelerometer.getAngleXY(), 1 ) << "}},";


		Serial << endl;
		}

	// short delay (is required) between readings.  Accelerometer can't handle anything higher than 20Hz
	delay(100);

	if ( millis() > startTime + 10000 ) {
		if ( accelerometer.checkBump() )
		    Serial << "--BUMP!---" << endl;

  	}



}
