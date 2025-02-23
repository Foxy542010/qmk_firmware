LTO_ENABLE = yes

OS_DETECTION_ENABLE = yes
SPACE_CADET_ENABLE = no
GRAVE_ESC_ENABLE = no 
MAGIC_ENABLE = no

OLED_DRIVER = ssd1306
OLED_TRANSPORT = i2c

ifeq ($(strip $(OLED_ENABLE)), yes)
    SRC += oled_display.c
endif