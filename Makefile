CC := gcc
RM := rm -f
CFLAGS := -I/opt/vc/include -I/opt/vc/include/interface/vcos/pthreads -I/opt/vc/include/interface/vmcs_host/linux
LDLIBS := -L/opt/vc/lib -lbcm_host

all: libbcm_host_test

libbcm_host_test: libbcm_host_test.o

.PHONY: clean
clean:
	$(RM) libbcm_host_test
	$(RM) libbcm_host_test.o

.PHONY: run
run: libbcm_host_test
	./$<
