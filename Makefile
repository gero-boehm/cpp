MAKEFILES:=$(shell find */ -name Makefile)

clean fclean valgrind:
	@for dir in $(dir $(MAKEFILES)); do \
		echo "$$dir"; \
        make --no-print-directory -C $$dir $@; \
    done

.PHONY:
	clean fclean valgrind