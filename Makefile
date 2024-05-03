SRC_FILES = $(shell find -name '*.ц')
EXT_FILES = extension.cpp
TARGET_NAME = цільфетч

all: build

.PHONY: clean

build: $(TARGET_NAME)

$(TARGET_NAME):
	ціль $(TARGET_NAME) сплавити $(SRC_FILES) $(EXT_FILES)

clean:
	$(RM) $(TARGET_NAME)
