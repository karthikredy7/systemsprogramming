#Make file for compiling the source code 


all:clean hw3_sgoturi

clean:
	rm -fr hw3_sgoturi

hw3_sgoturi:
	gcc   entery_point.c put_list.c dopath.c copy_args.c -o hw3_sgoturi
