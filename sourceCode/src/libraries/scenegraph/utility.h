#include <iostream>
#include "type.h"

void print_vertex_stream(vertex_stream<float> v){
  for(auto &v : v){
	for(auto &v1 : v){
	  std::cout << v1 << " ";
	}
	std::cout << std::endl;
  }
}
