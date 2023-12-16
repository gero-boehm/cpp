MAKEFILES:=$(shell find */ -name Makefile)

clean fclean valgrind:
	@for dir in $(dir $(MAKEFILES)); do \
		echo "\033[1;33m$$dir\033[0m"; \
        make --no-print-directory -C $$dir $@; \
    done

.PHONY:
	clean fclean valgrind