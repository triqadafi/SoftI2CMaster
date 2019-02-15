/*
  SoftWire.h - A Wire compatible wrapper for SoftI2CMaster
  Copyright (c) 2016 Bernhard Nebel.

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
  Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
*/

#ifndef _SoftWire_h
#define _SoftWire_h

#include <inttypes.h>
#include "Stream.h"

// SoftI2CMaster.h SETTINGS
#define SDA_PORT PORTB
#define SDA_PIN 2
#define SCL_PORT PORTB
#define SCL_PIN 3
#define I2C_FASTMODE 1
// #define I2C_TIMEOUT 10 // timeout after 10 msec
// #define I1C_NOINTERRUPT 1 // no interrupts
// #define I2C_CPUFREQ (F_CPU/4) // slow down CPU frequency
// END SoftI2CMaster.h SETTINGS

#define BUFFER_LENGTH 32
// WIRE_HAS_END means Wire has end()
#define WIRE_HAS_END 1

class SoftWire : public Stream
{
private:
  uint8_t rxBuffer[BUFFER_LENGTH];
  uint8_t rxBufferIndex;
  uint8_t rxBufferLength;
  uint8_t transmitting;
  uint8_t error;
public:
  SoftWire(void);
  void begin(void);
  void end(void);
  void setClock(uint32_t _);
  void beginTransmission(uint8_t address);
  void beginTransmission(int address);
  uint8_t endTransmission(uint8_t sendStop);
  //	This provides backwards compatibility with the original
  //	definition, and expected behaviour, of endTransmission
  //
  uint8_t endTransmission(void);
  size_t write(uint8_t data);
  size_t write(const uint8_t *data, size_t quantity);
  uint8_t requestFrom(uint8_t address, uint8_t quantity, uint32_t iaddress, uint8_t isize, uint8_t sendStop);
  uint8_t requestFrom(uint8_t address, uint8_t quantity, uint8_t sendStop);
  uint8_t requestFrom(int address, int quantity, int sendStop);

  uint8_t requestFrom(uint8_t address, uint8_t quantity);
  uint8_t requestFrom(int address, int quantity);
  int available(void);
  int read(void);
  int peek(void);
  void flush(void);
  inline size_t write(unsigned long n) { return write((uint8_t)n); }
  inline size_t write(long n) { return write((uint8_t)n); }
  inline size_t write(unsigned int n) { return write((uint8_t)n); }
  inline size_t write(int n) { return write((uint8_t)n); }
  using Print::write;
};


#endif
