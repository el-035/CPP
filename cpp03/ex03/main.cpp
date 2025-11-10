#include "DiamondTrap.hpp"

int main(void)
{
	DiamondTrap dio("DIO");
	DiamondTrap jj;
	jj = dio;
	std::cout << std::endl;

	jj.printPoints();
	jj.whoAmI();
	jj.attack("jiji");
	/* dio.printPoints();
	dio.whoAmI();
	///dio.attack("na");
	std::cout << std::endl; */
	std::cout << std::endl;


	DiamondTrap god(dio);
	//god = dio;
	std::cout << std::endl;

	god.printPoints();
	god.whoAmI();
	god.attack("jiji");
	std::cout << std::endl;

}