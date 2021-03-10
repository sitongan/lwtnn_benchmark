#include "lwtnn/LightweightGraph.hh"
#include "lwtnn/parse_json.hh"
#include <fstream>
#include <string>
#include <iostream>
#include <chrono>

int main(){

using namespace lwt;

std::ifstream input("linear_event_nn.json");
LightweightGraph graph(parse_json_graph(input));
std::map<std::string, std::map<std::string, double> > inputs;

for (int i = 0; i < 100; i++){
   inputs["node_0"].insert({"variable_" + std::to_string(i), 0.0});
}

auto t1 = std::chrono::high_resolution_clock::now();
std::map<std::string, double> outputs = graph.compute(inputs);
auto t2 = std::chrono::high_resolution_clock::now();
auto duration = std::chrono::duration_cast<std::chrono::microseconds>( t2 - t1 ).count();


for (auto& i: outputs){
   std::cout << i.first << "," <<i.second << "\t";
}
std::cout << std::endl << duration << std::endl;

return 0;
}
