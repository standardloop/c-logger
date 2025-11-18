include Makefile.properties

all: build run

clean:
	@rm -f $(EXECUTABLE_NAME)
	@rm -f $(DYLIB_NAME)
	@rm -f $(DYLIB_NAME).zip

build:
	@$(CC) $(CC_FLAGS) \
	main.c \
	$(SOURCE_FILES) \
	-o $(EXECUTABLE_NAME)

run:
	@./$(EXECUTABLE_NAME)

check_leaks:
	@leaks --atExit -- ./$(EXECUTABLE_NAME)

release_local: build_release move_files

# release_local_github: download_release move_files

build_release:
	@$(CC) \
	$(SOURCE_FILES) \
	-O3 \
	-dynamiclib \
	-current_version $(RELEASE_VERSION) \
	-o $(DYLIB_NAME)

move_files:
	@sudo mv $(DYLIB_NAME) $(DYLIB_PATH)
	@sudo cp logger.h $(DYLIB_INCLUDE_PATH)

# download_release:
# 	curl -O -J -L https://github.com/standardloop/c-logger/releases/download/v$(RELEASE_VERSION)/$(DYLIB_NAME).zip
# 	unzip $(DYLIB_NAME).zip
