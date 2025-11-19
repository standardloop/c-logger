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

release_local_github: download_release move_files

build_release:
	@$(CC) $(CC_FLAGS) \
	$(SOURCE_FILES) \
	-O3 \
	-dynamiclib \
	-current_version $(RELEASE_VERSION) \
	-o $(DYLIB_NAME)

move_files:
	@sudo mv $(DYLIB_NAME) $(DYLIB_PATH)
	@sudo cp logger.h $(DYLIB_INCLUDE_PATH)


# local testing
download_release:
	mkdir -p tmp && \
	cd tmp && \
	curl -O -J -L https://github.com/standardloop/c-logger/releases/download/v0.0.1/libstandardloop-logger.zip && \
	unzip libstandardloop-logger.zip && \
	sudo mv libstandardloop-logger.dylib /usr/local/lib/standardloop/ && \
	sudo mv logger.h /usr/local/include/standardloop/ && rm libstandardloop-logger.zip

.PHONY: lab FORCE

lab: FORCE
	@$(CC) $(CC_FLAGS) \
	lab.c \
	-L/usr/local/lib/standardloop \
	-lstandardloop-logger \
	-o lab

FORCE:

clean_release:
	sudo rm /usr/local/lib/standardloop/libstandardloop-logger.dylib
	sudo rm /usr/local/include/standardloop/logger.h
