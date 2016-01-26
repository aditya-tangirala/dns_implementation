include ../Make.defines

PROGS =	tcpcli01 tcpserv01 str_echo\

all:	${PROGS}
tcpcli01:	tcpcli01.o
		${CC} ${CFLAGS} -o $@ tcpcli01.o ${LIBS}

tcpserv01:	tcpserv01.o
		${CC} ${CFLAGS} -o $@ tcpserv01.o ${LIBS}
tcpserv02:	tcpserv02.o
		${CC} ${CFLAGS} -o $@ tcpserv02.o ${LIBS}


clean:
		rm -f ${PROGS} ${CLEANFILES}
