# Makefile Definitions
include makedefs

# Name of the project
PROJ_NAME = main

# Paths to other makefiles
CONCURRENCY_MAKEFILE := $(SRC)/threading/makefile
GAME_MAKEFILE := $(SRC)/makefile
MAIN_MAKEFILE := $(SRC)/makefile

# Compiler and linker
CC = g++

# Command used at clean target
RM = rm -rf

# Default target
all: build

# Object files
OBJ = $(OBJDIR)/main.o $(wildcard $(OBJDIR)/*.o)

# Creates Main executable
$(PROJ_NAME): $(OBJ)
	@echo 'Building binary using GCC linker: $@'
	$(CC) $^ $(LIBS) -o $@
	@echo 'Finished building binary: $@'
	@echo ' '

build: compileSource
	@$(MAKE) -s $(PROJ_NAME)

compileSource:
	@mkdir -p $(OBJDIR)
	@$(MAKE) -s -C $(SRC) -f $(GAME_MAKEFILE)
	@$(MAKE) -s -C $(SRC)/threading -f $(CONCURRENCY_MAKEFILE)
	@$(MAKE) -s -C $(SRC) -f $(MAIN_MAKEFILE)

clean:
	@$(MAKE) -s -C $(SRC)/threading -f $(CONCURRENCY_MAKEFILE) clean
	@$(MAKE) -s -C $(SRC) -f $(GAME_MAKEFILE) clean
	@rm -rf $(PROJ_NAME) $(OBJDIR) *~

.PHONY: all clean
