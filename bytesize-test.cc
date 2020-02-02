#include"bytesize.hh"
#include<iostream>
using namespace bytesize::literals;
int main(int argc, char** argv){
	for(size_t i=1; i<argc; i++){
		try{
			auto bs=bytesize::bytesize::parse(argv[i]);
			std::cout<<"#"<<i<<": "<<argv[i]<<" → "<<(size_t)bs<<" → "<<bs.format()<<std::endl;
		} catch(std::exception& e){
			std::cout<<"#"<<i<<": "<<argv[i]<<" [ERROR: "<<e.what()<<"]"<<std::endl;
		}
	}
	std::cout<<5534534_kB<<std::endl;
	std::cout<<(size_t)(10.0_MB)<<std::endl;
}
