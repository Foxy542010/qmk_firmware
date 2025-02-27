ifeq ($(strip $(OLED_ENABLE)), yes)
    SRC += oled_display.c
endif