#pragma once

#include <sstream>

#define debug(args...) { std::cerr << "line " << __LINE__ << ": "; std::string _s = #args; std::replace(_s.begin(), _s.end(), ',', ' '); std::stringstream _ss(_s); std::istream_iterator<std::string> _it(_ss); _err(std::cerr, _it, args); }

template<typename T, typename S>
std::ostream& operator<<(std::ostream&o,const std::pair<T,S>&v) {
	o<<v.first<<","<<v.second; return o;
}
template<typename T, typename S>
std::ostream& operator<<(std::ostream&o,const std::map<T,S>&v) {
	o<<'\n'<<'{'; for(auto&& e:v) o<<e.first<<"->"<<e.second<<' '; o<<'}'; return o;
}
template<typename T>
std::ostream& operator<<(std::ostream&o,const std::set<T>&v) {
	o<<'\n'<<'{'; for(auto&& e:v)  o<<e<<' '; o<<'}'; return o;
}
template<typename T>
std::ostream& operator<<(std::ostream&o,const std::vector<T>&v) {
	o<<'\n'<<'['; for(int i=0;i<v.size();i++) o<<v[i]<<","[i==v.size()-1]; o<<']'; return o;
}

void _err(std::ostream& cerr,std::istream_iterator<std::string> it) { cerr << '\n'; }
template<typename T, typename... Args>
void _err(std::ostream& cerr, std::istream_iterator<std::string> it, T a, Args... args) {
	cerr << *it << " = " << a << "  ";
	_err(cerr,++it, args...);
}
