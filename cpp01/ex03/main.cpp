#include"Weapon.hpp"
#include"HumanA.hpp"
#include"HumanB.hpp"

int main()
{
	{
		Weapon club = Weapon("gun");
		HumanA bob("Human", club);
		bob.attack();
		club.setType("two guns");
		bob.attack();
	}
	std::cout << std::endl;
	{
		Weapon club = Weapon("knife");
		HumanB jim("Not Human");
		jim.setWeapon(club);
		jim.attack();
		club.setType("double knife");
		jim.attack();
	}
	std::cout << std::endl;

	{
		Weapon club = Weapon("crude spiked club");
		HumanA bob("Bob", club);
		bob.attack();
		club.setType("some other type of club");
		bob.attack();
	}
	std::cout << std::endl;

	{
		Weapon club = Weapon("crude spiked club");
		HumanB jim("Jim");
		jim.setWeapon(club);
		jim.attack();
		club.setType("some other type of club");
		jim.attack();
	}
	return 0;
}