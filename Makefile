CC := gcc
CFLAGS := -Wall -Wextra

SRC_FILES != find src -type f -name '*.c'
OUT_FILES := $(patsubst src/%.c,sv/%,$(SRC_FILES))

all: $(SRC_FILES)
	@$(MAKE) --no-print-directory $(OUT_FILES)

sv/%: src/%.c
	-@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -o $@ $<

clean:
	@rm -rf sv/*
