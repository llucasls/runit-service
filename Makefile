CC     := gcc
CFLAGS := -Wall -Wextra

SRC_FILES != find src -type f -name '*.c' ! -name 'conf.c'
BIN_FILES := $(patsubst src/%.c,sv/%,$(SRC_FILES))

CONF_FILES != find src -type f -name 'conf.c'
LIB_FILES  := $(patsubst src/%/conf.c,sv/%/libconf.so,$(CONF_FILES))

OUT_FILES  := $(BIN_FILES) $(LIB_FILES)

all: $(OUT_FILES)

$(BIN_FILES): sv/%: src/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -o $@ $<

$(LIB_FILES): sv/%/libconf.so: src/%/conf.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -shared -o $@ $<

clean:
	@rm -rf sv/*
