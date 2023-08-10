/*!
 *  @file AMS_OSRAM_AS7343.h

 *  @mainpage AMS OSRAM AS7343 14-Channel Spectral Sensor
 *
 *  @section intro_sec Introduction
 *
 * 	I2C Driver for the Library for the AS7343 14-Channel Spectral Sensor
 *
 * 	This is a library for the Adafruit AS7343 breakout:
 * 	https://www.adafruit.com/product/4698
 *
 * 	Adafruit invests time and resources providing this open source code,
 *  please support Adafruit and open-source hardware by purchasing products from
 * 	Adafruit!
 *
 *  @section dependencies Dependencies
 *  This library depends on the Adafruit BusIO library
 *
 *  @section author Author
 *
 *  Bryan Siepert for Adafruit Industries
 *
 * 	@section license License
 *
 * 	BSD (see license.txt)
 *
 * 	@section  HISTORY
 *
 *     v1.0 - First release
 */

/*
  This library is adapted from an example with the following Copyright and
  Warranty:

  This is a Hello world example code written for the AS7241 XWing Spectral
  Sensor I2C interface with Arduino µC. The main idea is to get fimilar with the
  register configuration. This code helps to learn basic settings and procedure
  to read out raw values with different SMUX configuration. Also defined the
  procedure to set the default flicker detection for 100 and 120 Hz.

  Written by Sijo John @ ams AG, Application Support in October, 2018

  Development environment specifics: Arduino IDE 1.8.5

  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

*/

#ifndef _AMS_OSRAM_AS7343_H
#define _AMS_OSRAM_AS7343_H

#include "Arduino.h"
#include <Adafruit_BusIO_Register.h>
#include <Adafruit_I2CDevice.h>
#include <Wire.h>
#define AS7343_I2CADDR_DEFAULT 0x39 ///< AS7343 default i2c address
#define AS7343_CHIP_ID 0x81         ///< AS7343 default device id from datasheet

#define AS7343_WHOAMI 0x5A ///< Chip ID register

#define AS7343_ASTATUS 0x60     ///< AS7343_ASTATUS (unused)
#define AS7343_CH0_DATA_L_ 0x61 ///< AS7343_CH0_DATA_L (unused)
#define AS7343_CH0_DATA_H_ 0x62 ///< AS7343_CH0_DATA_H (unused)
#define AS7343_ITIME_L 0x63     ///< AS7343_ITIME_L (unused)
#define AS7343_ITIME_M 0x64     ///< AS7343_ITIME_M (unused)
#define AS7343_ITIME_H 0x65     ///< AS7343_ITIME_H (unused)
#define AS7343_CONFIG 0x70 ///< Enables LED control and sets light sensing mode
#define AS7343_STAT 0x71   ///< AS7343_STAT (unused)
#define AS7343_EDGE 0x72   ///< AS7343_EDGE (unused)
#define AS7343_GPIO 0x73   ///< Connects photo diode to GPIO or INT pins
#define AS7343_LED 0xCD    ///< LED Register; Enables and sets current limit
#define AS7343_ENABLE                                                          \
  0x80 ///< Main enable register. Controls SMUX, Flicker Detection, Spectral
       ///< Measurements and Power
#define AS7343_ATIME 0x81       ///< Sets ADC integration step count
#define AS7343_WTIME 0x83       ///< AS7343_WTIME (unused)
#define AS7343_SP_LOW_TH_L 0x84 ///< Spectral measurement Low Threshold low byte
#define AS7343_SP_LOW_TH_H                                                     \
  0x85 ///< Spectral measurement Low Threshold high byte
#define AS7343_SP_HIGH_TH_L                                                    \
  0x86 ///< Spectral measurement High Threshold low byte
#define AS7343_SP_HIGH_TH_H                                                    \
  0x87                    ///< Spectral measurement High Threshold low byte
#define AS7343_AUXID 0x58 ///< AS7343_AUXID (unused)
#define AS7343_REVID 0x59 ///< AS7343_REVID (unused)
#define AS7343_ID 0x92    ///< AS7343_ID (unused)
#define AS7343_STATUS                                                          \
  0x93 ///< Interrupt status registers. Indicates the occourance of an interrupt
#define AS7343_ASTATUS_ 0x94   ///< AS7343_ASTATUS, same as 0x60 (unused)
#define AS7343_CH0_DATA_L 0x95 ///< ADC Channel Data
#define AS7343_CH0_DATA_H 0x96 ///< ADC Channel Data
#define AS7343_CH1_DATA_L 0x97 ///< ADC Channel Data
#define AS7343_CH1_DATA_H 0x98 ///< ADC Channel Data
#define AS7343_CH2_DATA_L 0x99 ///< ADC Channel Data
#define AS7343_CH2_DATA_H 0x9A ///< ADC Channel Data
#define AS7343_CH3_DATA_L 0x9B ///< ADC Channel Data
#define AS7343_CH3_DATA_H 0x9C ///< ADC Channel Data
#define AS7343_CH4_DATA_L 0x9D ///< ADC Channel Data
#define AS7343_CH4_DATA_H 0x9E ///< ADC Channel Data
#define AS7343_CH5_DATA_L 0x9F ///< ADC Channel Data
#define AS7343_CH5_DATA_H 0xA0 ///< ADC Channel Data
#define AS7343_CH6_DATA_L 0xA1 ///< ADC Channel Data
#define AS7343_CH6_DATA_H 0xA2 ///< ADC Channel Data
#define AS7343_CH7_DATA_L 0xA3 ///< ADC Channel Data
#define AS7343_CH7_DATA_H 0xA4 ///< ADC Channel Data
#define AS7343_CH8_DATA_L 0xA5 ///< ADC Channel Data
#define AS7343_CH8_DATA_H 0xA6 ///< ADC Channel Data
#define AS7343_CH9_DATA_L 0xA7 ///< ADC Channel Data
#define AS7343_CH9_DATA_H 0xA8 ///< ADC Channel Data
#define AS7343_CH10_DATA_L 0xA9 ///< ADC Channel Data
#define AS7343_CH10_DATA_H 0xAA ///< ADC Channel Data
#define AS7343_CH11_DATA_L 0xAB ///< ADC Channel Data
#define AS7343_CH11_DATA_H 0xAC ///< ADC Channel Data
#define AS7343_CH12_DATA_L 0xAD ///< ADC Channel Data
#define AS7343_CH12_DATA_H 0xAE ///< ADC Channel Data
#define AS7343_CH13_DATA_L 0xAF ///< ADC Channel Data
#define AS7343_CH13_DATA_H 0xB0 ///< ADC Channel Data
#define AS7343_CH14_DATA_L 0xB1 ///< ADC Channel Data
#define AS7343_CH14_DATA_H 0xB2 ///< ADC Channel Data
#define AS7343_CH15_DATA_L 0xB3 ///< ADC Channel Data
#define AS7343_CH15_DATA_H 0xB4 ///< ADC Channel Data
#define AS7343_CH16_DATA_L 0xB5 ///< ADC Channel Data
#define AS7343_CH16_DATA_H 0xB6 ///< ADC Channel Data
#define AS7343_CH17_DATA_L 0xB7 ///< ADC Channel Data
#define AS7343_CH17_DATA_H 0xB8 ///< ADC Channel Data

#define AS7343_STATUS2 0x90 ///< Measurement status flags; saturation, validity
#define AS7343_STATUS3                                                         \
  0x91 ///< Spectral interrupt source, high or low threshold
#define AS7343_STATUS5 0xBB ///< AS7343_STATUS5 (unused)
#define AS7343_STATUS4 0xBC ///< AS7343_STATUS6 (unused)
#define AS7343_CFG0                                                            \
  0xBF ///< Sets Low power mode, Register bank, and Trigger lengthening
#define AS7343_CFG1 0xC6 ///< Controls ADC Gain
#define AS7343_CFG3 0xC7 ///< AS7343_CFG3 (unused)
#define AS7343_CFG6 0xF5 ///< Used to configure Smux
#define AS7343_CFG8 0xC9 ///< AS7343_CFG8 (unused)
#define AS7343_CFG9                                                            \
  0xCA ///< Enables flicker detection and smux command completion system
       ///< interrupts
#define AS7343_CFG10 0x65 ///< AS7343_CFG10 (unused)
#define AS7343_CFG12                                                           \
  0x66 ///< Spectral threshold channel for interrupts, persistence and auto-gain
#define AS7343_CFG20 0xD6 //< FIFO and auto SMUX
#define AS7343_PERS                                                            \
  0xCF ///< Number of measurement cycles outside thresholds to trigger an
       ///< interupt
#define AS7343_GPIO2                                                           \
  0x6B ///< GPIO Settings and status: polarity, direction, sets output, reads
       ///< input
#define AS7343_ASTEP_L 0xD4      ///< Integration step size ow byte
#define AS7343_ASTEP_H 0xD5      ///< Integration step size high byte
#define AS7343_AGC_GAIN_MAX 0xD7 ///< AS7343_AGC_GAIN_MAX (unused)
#define AS7343_AZ_CONFIG 0xDE    ///< AS7343_AZ_CONFIG (unused)
#define AS7343_FD_TIME1 0xE0 ///< Flicker detection integration time low byte
#define AS7343_FD_TIME2 0xE2 ///< Flicker detection gain and high nibble
#define AS7343_FD_CFG0 0xDF  ///< AS7343_FD_CFG0 (unused)
#define AS7343_FD_STATUS                                                       \
  0xE3 ///< Flicker detection status; measurement valid, saturation, flicker
       ///< type
#define AS7343_INTENAB 0xF9  ///< Enables individual interrupt types
#define AS7343_CONTROL 0xFA  ///< Auto-zero, fifo clear, clear SAI active
#define AS7343_FIFO_MAP 0xFC ///< AS7343_FIFO_MAP (unused)
#define AS7343_FIFO_LVL 0xFD ///< AS7343_FIFO_LVL (unused)
#define AS7343_FDATA_L 0xFE  ///< AS7343_FDATA_L (unused)
#define AS7343_FDATA_H 0xFF  ///< AS7343_FDATA_H (unused)

#define AS7343_SPECTRAL_INT_HIGH_MSK                                           \
  0b00100000 ///< bitmask to check for a high threshold interrupt
#define AS7343_SPECTRAL_INT_LOW_MSK                                            \
  0b00010000 ///< bitmask to check for a low threshold interrupt


/**
 * @brief Allowable gain multipliers for `setGain`
 *
 */
typedef enum {
  AS7343_GAIN_0_5X,
  AS7343_GAIN_1X,
  AS7343_GAIN_2X,
  AS7343_GAIN_4X,
  AS7343_GAIN_8X,
  AS7343_GAIN_16X,
  AS7343_GAIN_32X,
  AS7343_GAIN_64X,
  AS7343_GAIN_128X,
  AS7343_GAIN_256X,
  AS7343_GAIN_512X,
  AS7343_GAIN_1024X,
  AS7343_GAIN_2048X,
} AS7343_gain_t;

/**
 * @brief Available SMUX configuration commands
 *
 */
typedef enum {
  AS7343_SMUX_CMD_ROM_RESET, ///< ROM code initialization of SMUX
  AS7343_SMUX_CMD_READ,      ///< Read SMUX configuration to RAM from SMUX chain
  AS7343_SMUX_CMD_WRITE, ///< Write SMUX configuration from RAM to SMUX chain
} AS7343_smux_cmd_t;
/**
 * @brief ADC Channel specifiers for configuration
 *
 */
typedef enum {
  AS7343_ADC_CHANNEL_0,
  AS7343_ADC_CHANNEL_1,
  AS7343_ADC_CHANNEL_2,
  AS7343_ADC_CHANNEL_3,
  AS7343_ADC_CHANNEL_4,
  AS7343_ADC_CHANNEL_5,
} AS7343_adc_channel_t;
/**
 * @brief Spectral Channel specifiers for configuration and reading
 *
 */
typedef enum {
  AS7343_CHANNEL_450_FZ,
  AS7343_CHANNEL_555_FY,
  AS7343_CHANNEL_600_FXL,
  AS7343_CHANNEL_855_NIR,
  AS7343_CHANNEL_CLEAR_1,
  AS7343_CHANNEL_FD_1,
  AS7343_CHANNEL_425_F2,
  AS7343_CHANNEL_475_F3,
  AS7343_CHANNEL_515_F4,
  AS7343_CHANNEL_640_F6,
  AS7343_CHANNEL_CLEAR_0,
  AS7343_CHANNEL_FD_0,
  AS7343_CHANNEL_405_F1,
  AS7343_CHANNEL_550_F5,
  AS7343_CHANNEL_690_F7,
  AS7343_CHANNEL_745_F8,
  AS7343_CHANNEL_CLEAR,
  AS7343_CHANNEL_FD,
} AS7343_color_channel_t;

/**
 * @brief The number of measurement cycles with spectral data outside of a
 * threshold required to trigger an interrupt
 *
 */
typedef enum {
  AS7343_INT_COUNT_ALL, ///< 0
  AS7343_INT_COUNT_1,   ///< 1
  AS7343_INT_COUNT_2,   ///< 2
  AS7343_INT_COUNT_3,   ///< 3
  AS7343_INT_COUNT_5,   ///< 4
  AS7343_INT_COUNT_10,  ///< 5
  AS7343_INT_COUNT_15,  ///< 6
  AS7343_INT_COUNT_20,  ///< 7
  AS7343_INT_COUNT_25,  ///< 8
  AS7343_INT_COUNT_30,  ///< 9
  AS7343_INT_COUNT_35,  ///< 10
  AS7343_INT_COUNT_40,  ///< 11
  AS7343_INT_COUNT_45,  ///< 12
  AS7343_INT_COUNT_50,  ///< 13
  AS7343_INT_COUNT_55,  ///< 14
  AS7343_INT_COUNT_60,  ///< 15
} AS7343_int_cycle_count_t;

/**
 * @brief Pin directions to set how the GPIO pin is to be used
 *
 */
typedef enum {
  AS7343_GPIO_OUTPUT, ///< THhe GPIO pin is configured as an open drain output
  AS7343_GPIO_INPUT,  ///< The GPIO Pin is set as a high-impedence input
} AS7343_gpio_dir_t;

/**
 * @brief Wait states for async reading
 */
typedef enum {
  AS7343_WAITING_START, //
  AS7343_WAITING_LOW,   //
  AS7343_WAITING_HIGH,  //
  AS7343_WAITING_DONE,  //
} AS7343_waiting_t;

class AMS_OSRAM_AS7343;

/*!
 *    @brief  Class that stores state and functions for interacting with
 *            the AS7343 11-Channel Spectral Sensor
 */
class AMS_OSRAM_AS7343 {
public:
  AMS_OSRAM_AS7343();
  ~AMS_OSRAM_AS7343();

  bool begin(uint8_t i2c_addr = AS7343_I2CADDR_DEFAULT, TwoWire *wire = &Wire,
             int32_t sensor_id = 0);

  bool setASTEP(uint16_t astep_value);
  bool setATIME(uint8_t atime_value);
  bool setGain(AS7343_gain_t gain_value);

  uint16_t getASTEP();
  uint8_t getATIME();
  AS7343_gain_t getGain();

  long getTINT();
  float toBasicCounts(uint16_t raw);

  bool readAllChannels(void);
  bool readAllChannels(uint16_t *readings_buffer);
  void delayForData(int waitTime = 0);
  uint16_t readChannel(AS7343_adc_channel_t channel);
  uint16_t getChannel(AS7343_color_channel_t channel);

  bool startReading(void);
  bool checkReadingProgress();
  bool getAllChannels(uint16_t *readings_buffer);

  uint16_t detectFlickerHz(void);

  void setup_F1F4_Clear_NIR(void);
  void setup_F5F8_Clear_NIR(void);

  void powerEnable(bool enable_power);
  bool enableSpectralMeasurement(bool enable_measurement);

  bool setHighThreshold(uint16_t high_threshold);
  bool setLowThreshold(uint16_t low_threshold);

  uint16_t getHighThreshold(void);
  uint16_t getLowThreshold(void);

  bool enableSpectralInterrupt(bool enable_int);
  bool enableSystemInterrupt(bool enable_int);

  bool setAPERS(AS7343_int_cycle_count_t cycle_count);
  bool setSpectralThresholdChannel(AS7343_adc_channel_t channel);

  uint8_t getInterruptStatus(void);
  bool clearInterruptStatus(void);

  bool spectralInterruptTriggered(void);
  uint8_t spectralInterruptSource(void);
  bool spectralLowTriggered(void);
  bool spectralHighTriggered(void);

  bool enableLED(bool enable_led);
  bool setLEDCurrent(uint16_t led_current_ma);
  uint16_t getLEDCurrent(void);

  void disableAll(void);

  bool getIsDataReady();
  bool setBank(bool low); // low true gives access to 0x60 to 0x74

  AS7343_gpio_dir_t getGPIODirection(void);
  bool setGPIODirection(AS7343_gpio_dir_t gpio_direction);
  bool getGPIOInverted(void);
  bool setGPIOInverted(bool gpio_inverted);
  bool getGPIOValue(void);
  bool setGPIOValue(bool);

  bool digitalSaturation(void);
  bool analogSaturation(void);
  bool clearDigitalSaturationStatus(void);
  bool clearAnalogSaturationStatus(void);

protected:
  virtual bool _init(int32_t sensor_id);
  uint8_t last_spectral_int_source =
      0; ///< The value of the last reading of the spectral interrupt source
         ///< register

  Adafruit_I2CDevice *i2c_dev = NULL; ///< Pointer to I2C bus interface

private:
  bool enableSMUX(void);
  bool enableFlickerDetection(bool enable_fd);
  void FDConfig(void);
  int8_t getFlickerDetectStatus(void);
  bool setSMUXCommand(AS7343_smux_cmd_t command);
  void writeRegister(byte addr, byte val);
  void setSMUXLowChannels(bool f1_f4);
  uint16_t _channel_readings[18];
  AS7343_waiting_t _readingState;
};

#endif
