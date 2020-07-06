cc = gcc
prom = search-cli
deps = search.h stats.h priorityqueue.h
obj = main.o search.o stats.o priorityqueue.o
$(prom): $(obj)
	$(cc) -o $(prom) $(obj)
	 
%.o: %.c $(deps)
	$(cc) -c $< -o $@
clean:
	rm -rf $(obj) $(prom)

