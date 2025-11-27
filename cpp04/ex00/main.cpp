#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

/* int main (void)
{
	Animal one;
	std::cout << one.getType() << std::endl;
	one.makeSound();

	Animal two(one);
	std::cout << two.getType() << std::endl;
	two.makeSound();
	
	Animal three;
	three = one;
	std::cout << three.getType() << std::endl;
	three.makeSound();


	Cat bacco;
	std::cout << bacco.getType() << std::endl;
	bacco.makeSound();

	Cat leda(bacco);
	std::cout << leda.getType() << std::endl;
	leda.makeSound();

	Cat iago;
	iago = bacco;
	std::cout << iago.getType() << std::endl;
	iago.makeSound();


	Dog gina;
	std::cout << gina.getType() << std::endl;
	gina.makeSound();

	Dog cane(gina);
	std::cout << cane.getType() << std::endl;
	cane.makeSound();

	Dog cagna(gina);
	std::cout << cagna.getType() << std::endl;
	cagna.makeSound();
}
 */

int main()
{
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound(); //will output the cat sound!
	j->makeSound();
	meta->makeSound();
	delete meta;
	delete j;
	delete i;
}
/* int main()
{
	const WrongAnimal* meta = new WrongAnimal();
	const WrongAnimal* i = new WrongCat();
	std::cout << i->getType() << " " << std::endl;
	i->makeSound();
	meta->makeSound();

} */