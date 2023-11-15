CC     := gcc
CFLAGS := -Wall -Wextra

SRC_FILES != find src/ -maxdepth 2 -type f -name '*.c' ! -name 'conf.c'
BIN_FILES := $(patsubst src/%.c,sv/%,$(SRC_FILES))

SRC_LOGS != find src/ -mindepth 3 -type f -name '*.c' ! -name 'conf.c'
BIN_LOGS := $(patsubst src/%.c,sv/%,$(SRC_LOGS))

CONF_FILES != find src -type f -name 'conf.c'
LIB_FILES  := $(patsubst src/%/conf.c,sv/%/libconf.so,$(CONF_FILES))

OUT_FILES  := $(BIN_FILES) $(LIB_FILES)

all: $(OUT_FILES)

$(BIN_FILES): sv/%: src/%.c
	@install -dm 755 $(@D)
	$(CC) $(CFLAGS) -o $@ $<

$(LIB_FILES): sv/%/libconf.so: src/%/conf.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -shared -o $@ $<

clean:
	@rm -rf sv/*
