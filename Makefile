# @file compile cpp source files
# @author hushicai

dir_src = src
dir_out = out

CC = clang++
CFLAGS = 

# 源代码
srcs = $(wildcard $(dir_src)/*.cc)

# 可执行文件
progs = $(patsubst %.cc, ${dir_out}/%, $(notdir $(srcs)))

all: setup $(progs)

.PHONY: clean setup
setup: 
	mkdir -p $(dir_out)

clean: 
	rm -rf $(dir_out)

$(dir_out)/%: $(dir_src)/%.cc
	$(CC) $(CFLAGS) -o $@ $^

# vim: set ft=make ts=4 sw=4 sts=4 tw=120 fdm=syntax: #
