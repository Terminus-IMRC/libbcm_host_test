CFLAGS += -I/opt/vc/include -pipe -W -Wall -Wextra -O2
LDLIBS += -L/opt/vc/lib -lbcm_host

.PHONY: all
all: libbcm_host_test

.PHONY: clean
clean:
	$(RM) libbcm_host_test
