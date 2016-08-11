include ../makefile_defs.mk
brent : brent.cc
	g++ -o brent -O -I${MADAI_INSTALLDIR}/include/madai -I${MADAI_GSLPATH}/include -L${MADAI_INSTALLDIR}/lib/madai -L${MADAI_GSLPATH}/lib -lcoral -lcoralutils -lgsl -lgslcblas brent.cc