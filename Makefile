CXX = g++
CPPFLAGS = -std=c++14 -g

lwtnn_infer: lwtnn_infer.cxx
	${CXX} -o lwtnn_infer $^ ${CPPFLAGS} -I/Users/sitongan/rootdev/sofie_benchmarking/lwtnn/include -L/Users/sitongan/rootdev/sofie_benchmarking/lwtnn/build/lib -llwtnn


.phony: clean
clean:
	-rm *.d
	-rm *.o
