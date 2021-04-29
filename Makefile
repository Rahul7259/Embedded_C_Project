PROJ_NAME = Embedded_C_Project
ELFFILE = $(PROJ_NAME).elf
BUILD_DIR = Build


SRC = SeatHeatingApp.c\
src/Activity_1.c\
src/Activity_2.c\
src/Activity_3.c


INC = -I inc

ifdef OS	# All configurations for Windwos OS
   RM = rm -rf
   FixPath = $(subst /,\,$1)
   CC = avr-gcc.exe
   AVR_OBJ_CPY = avr-objcopy
else #All configurations for Linux OS
   ifeq ($(shell uname), Linux)
      RM = rm -rf			
      FixPath = $1				
	  CC = avr-gcc
	  AVR_OBJ_CPY = avr-objcopy 
   endif
endif

# Command to make to consider these names as targets and not as file names in folder
.PHONY:all analysis clean doc

all:$(BUILD_DIR)
	$(CC) -g -Wall -Os -mmcu=atmega328  $(INC) $(SRC) -o $(call FixPath,$(BUILD_DIR)/$(PROJ_NAME).elf)

$(BUILD_DIR):
	mkdir $(BUILD_DIR)

hexfile:
	$(AVR_OBJ_CPY) -O ihex $(BUILD_DIR)/$(ELFFILE) $(BUILD_DIR)/$(PROJ_NAME).hex

analysis: $(SRC)
	cppcheck --enable=all $^

doc:
	make -C documentation

clean:
	$(RM) $(call FixPath,$(BUILD_DIR))
	make -C documentation clean
