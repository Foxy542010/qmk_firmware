#pragma once

#include_next <mcuconf.h>

#define I2C_DRIVER I2CD1

#undef RP_I2C_USE_I2C1
#define RP_I2C_USE_I2C1 TRUE