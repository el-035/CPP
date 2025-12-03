#include"whatever.hpp"

int main(void){
	int a = 4;
	int b = 7;
	float af = 0.7f;
	float bf = 7.4f;

	// test SWAP
	swap(a, b);
	std::cout << a << std::endl;
	std::cout << b << std::endl;

	swap(af, bf);
	std::cout << af << std::endl;
	std::cout << bf << std::endl;

	std::cout << min(a, b) << std::endl;
	std::cout << min(af, bf) << std::endl;

	std::cout << max(a, b) << std::endl;
	std::cout << max(af, bf) << std::endl;


}

/* int main( void ) {
int a = 2;
int b = 3;
::swap( a, b );
std::cout << "a = " << a << ", b = " << b << std::endl;
std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
std::string c = "chaine1";
std::string d = "chaine2";
::swap(c, d);
std::cout << "c = " << c << ", d = " << d << std::endl;
std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
return 0;
} */

