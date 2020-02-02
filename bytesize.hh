#pragma once

#include<string>
#include<regex>
#include<iomanip>
#include<sstream>

namespace bytesize {
	class bytesize{
		// number of bytes
		size_t bytes;
	public:
		// construct from number
		bytesize(size_t bytes_): bytes(bytes_){}
		// parse from string
		static bytesize parse(const std::string& str){
			std::regex rx("\\s*(\\d+|\\d+[.]|\\d?[.]\\d+)\\s*((|ki|Mi|Gi|Ti|Pi|k|M|G|T|P)[Bb]?)\\s*");
			std::smatch m;
			if(!std::regex_match(str,m,rx)) throw std::runtime_error("Unable to parse '"+str+"' as size.");
			double d=std::stod(m[1].str());
			size_t mult=1;
			if(m[3]=="") mult=1;
			else if(m[3]=="ki") mult=1L<<10;
			else if(m[3]=="Mi") mult=1L<<20;
			else if(m[3]=="Gi") mult=1L<<30;
			else if(m[3]=="Ti") mult=1L<<40;
			else if(m[3]=="Pi") mult=1L<<50;
			else if(m[3]=="k") mult=1'000L;
			else if(m[3]=="M") mult=1'000'000L;
			else if(m[3]=="G") mult=1'000'000'000L;
			else if(m[3]=="T") mult=1'000'000'000'000L;
			else if(m[3]=="P") mult=1'000'000'000'000'000L;
			else throw std::logic_error("Unhandled prefix '"+m[2].str()+"'.");
			return bytesize(d*mult);
		}
		// represent as string
		std::string format() const {
			std::ostringstream oss;
			oss<<std::setprecision(3);
			if(bytes<1'000L) oss<<bytes<<" B";
			else if(bytes<1'000'000L) oss<<(bytes*1./1000L)<<" kB";
			else if(bytes<1'000'000'000L) oss<<(bytes*1./1000'000L)<<" MB";
			else if(bytes<1'000'000'000'000L) oss<<(bytes*1./1000'000'000L)<<" GB";
			else if(bytes<1'000'000'000'000'000L) oss<<(bytes*1./1000'000'000'000L)<<" TB";
			else oss<<(bytes*1./1000'000'000'000'000L)<<" PB";
			return oss.str();
		}
		// implicit conversion to size_t
		operator size_t(){ return bytes; }
		// implicit conversion to std::string
		operator std::string(){ return this->format(); }
	};
	// stream output operator
	inline std::ostream& operator<<(std::ostream& os, const bytesize& bs){ os<<bs.format(); return os; }
	// separate namespace for using namespace bytesize::literals;
	namespace literals{
		// bytes only with integer
		bytesize operator"" _B(unsigned long long int num){ return bytesize(num); }
		// floating-point numbers, like 5.5_kB
		bytesize operator"" _kiB(long double num){ return bytesize((size_t)((1L<<10)*num)); }
		bytesize operator"" _MiB(long double num){ return bytesize((size_t)((1L<<20)*num)); }
		bytesize operator"" _GiB(long double num){ return bytesize((size_t)((1L<<30)*num)); }
		bytesize operator"" _TiB(long double num){ return bytesize((size_t)((1L<<40)*num)); }
		bytesize operator"" _PiB(long double num){ return bytesize((size_t)((1L<<50)*num)); }
		bytesize operator"" _kB(long double num){ return bytesize((size_t)(1'000L*num)); }
		bytesize operator"" _MB(long double num){ return bytesize((size_t)(1'000'000L*num)); }
		bytesize operator"" _GB(long double num){ return bytesize((size_t)(1'000'000'000L*num)); }
		bytesize operator"" _TB(long double num){ return bytesize((size_t)(1'000'000'000L*num)); }
		bytesize operator"" _PB(long double num){ return bytesize((size_t)(1'000'000'000'000L*num)); }
		// repeated for integer literals so that e.g. 5_kB works
		bytesize operator"" _kiB(unsigned long long int num){ return bytesize((size_t)((1L<<10)*num)); }
		bytesize operator"" _MiB(unsigned long long int num){ return bytesize((size_t)((1L<<20)*num)); }
		bytesize operator"" _GiB(unsigned long long int num){ return bytesize((size_t)((1L<<30)*num)); }
		bytesize operator"" _TiB(unsigned long long int num){ return bytesize((size_t)((1L<<40)*num)); }
		bytesize operator"" _PiB(unsigned long long int num){ return bytesize((size_t)((1L<<50)*num)); }
		bytesize operator"" _kB(unsigned long long int num){ return bytesize((size_t)(1'000L*num)); }
		bytesize operator"" _MB(unsigned long long int num){ return bytesize((size_t)(1'000'000L*num)); }
		bytesize operator"" _GB(unsigned long long int num){ return bytesize((size_t)(1'000'000'000L*num)); }
		bytesize operator"" _TB(unsigned long long int num){ return bytesize((size_t)(1'000'000'000L*num)); }
		bytesize operator"" _PB(unsigned long long int num){ return bytesize((size_t)(1'000'000'000'000L*num)); }
	}
}
#ifndef BYTESIZE_NO_FMTLIB
	// make bytesize::bytesize known to fmt::format
	#include<fmt/format.h>
	template<> struct fmt::formatter<bytesize::bytesize> {
	  template<typename ParseContext> constexpr auto parse(ParseContext &ctx) { return ctx.begin(); }
	  template<typename FormatContext> auto format(const bytesize::bytesize &bs, FormatContext &ctx) { return format_to(ctx.out(),"{}",bs.format()); }
	};
#endif


