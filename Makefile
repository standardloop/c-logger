include Makefile.properties

all: build run

clean:
	@rm $(EXECUTABLE_NAME)

build:
	@$(CC) $(CC_FLAGS) \
	main.c \
	$(SOURCE_FILES) \
	-o $(EXECUTABLE_NAME)

run:
	@./$(EXECUTABLE_NAME)

check_leaks:
	@leaks --atExit -- ./$(EXECUTABLE_NAME)

release: build_release move_files

build_release:
	@$(CC) \
	$(SOURCE_FILES) \
	-O3 \
	-dynamiclib \
	-current_version 1.0.0 \
	-o $(DYLIB_NAME)

move_files:
	@sudo mv $(DYLIB_NAME) $(DYLIB_PATH)
	@sudo cp logger.h $(DYLIB_INCLUDE_PATH)
