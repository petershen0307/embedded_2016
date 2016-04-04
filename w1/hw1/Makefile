CC ?= gcc
CFLAGS_common ?= -Wall -std=gnu99
CFLAGS_orig = -O0
CFLAGS_opt  = -O0

EXEC = phonebook_orig phonebook_mini phonebook_hash_linked_list phonebook_hash_array
all: $(EXEC)

INC_common =  phonebook_util.h
SRCS_common = main.c

phonebook_orig: $(SRCS_common) $(INC_common) phonebook_orig.c phonebook_orig.h
	$(CC) $(CFLAGS_common) $(CFLAGS_orig) \
		-DIMPL="\"$@.h\"" -o $@ \
		$(SRCS_common) $@.c

phonebook_mini: $(SRCS_common) $(INC_common) phonebook_mini.c phonebook_mini.h
	$(CC) $(CFLAGS_common) $(CFLAGS_orig) -DOPT -DMINI \
		-DIMPL="\"$@.h\"" -o $@ \
		$(SRCS_common) $@.c

phonebook_hash_linked_list: $(SRCS_common) $(INC_common) phonebook_hash_linked_list.c phonebook_hash_linked_list.h
	$(CC) $(CFLAGS_common) $(CFLAGS_opt) -DOPT -DLINKED_LIST \
		-DIMPL="\"$@.h\"" -o $@ \
		$(SRCS_common) $@.c

phonebook_hash_array: $(SRCS_common) $(INC_common) phonebook_hash_array.c phonebook_hash_array.h
	$(CC) $(CFLAGS_common) $(CFLAGS_opt) -DOPT -DARRAY \
		-DIMPL="\"$@.h\"" -o $@ \
		$(SRCS_common) $@.c

run: $(EXEC)
	echo 3 | sudo tee /proc/sys/vm/drop_caches
	watch -d -t "./phonebook_orig && echo 3 | sudo tee /proc/sys/vm/drop_caches"

cache-test: $(EXEC)
	perf stat --repeat 100 \
		-e cache-misses,cache-references,instructions,cycles \
		./phonebook_orig
	perf stat --repeat 100 \
		-e cache-misses,cache-references,instructions,cycles \
		./phonebook_mini
	perf stat --repeat 100 \
		-e cache-misses,cache-references,instructions,cycles \
		./phonebook_hash_array
#	perf stat --repeat 100 \
#		-e cache-misses,cache-references,instructions,cycles \
#		./phonebook_hash_linked_list

output.txt: cache-test calculate
	./calculate

plot: output.txt
	gnuplot scripts/runtime.gp

calculate: calculate.c
	$(CC) $(CFLAGS_common) $^ -o $@

.PHONY: clean
clean:
	$(RM) $(EXEC) *.o perf.* \
	      	calculate orig.txt opt.txt output.txt runtime.png
