/* <timer> */
#include <chrono>
struct timer
{
	std::chrono::time_point<std::chrono::steady_clock> start;
	timer() : start(std::chrono::steady_clock::now()) {}
	void ms() {
		std::chrono::duration<double> diff=std::chrono::steady_clock::now()-start;
		std::cerr << diff.count()*1000 << "ms\n";
	}
};
struct time_scope
{
	std::chrono::time_point<std::chrono::steady_clock> start;
	time_scope() : start(std::chrono::steady_clock::now()) {}
	~time_scope() {
		std::chrono::duration<double> diff=std::chrono::steady_clock::now()-start;
		std::cerr << diff.count()*1000 << "ms\n";
	}
};
/* <timer> */
