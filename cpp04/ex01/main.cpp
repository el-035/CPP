#include "Cat.hpp"
#include "Dog.hpp"


int main (void){ //deep copies
	Dog a;
	Dog b = a;

	b.getBrain()->setIdeas(0, "hola");
	a.getBrain()->setIdeas(0, "culo");

	std::cout << b.getBrain()->getideas(0) << std::endl;
	std::cout << a.getBrain()->getideas(0) << std::endl;

	Cat aa;
	Cat bb;
	bb = aa;

	bb.getBrain()->setIdeas(0, "gatto");
	aa.getBrain()->setIdeas(0, "non gattpo");

	std::cout << bb.getBrain()->getideas(0) << std::endl;
	std::cout << aa.getBrain()->getideas(0) << std::endl;

}

/* int main (void) //delete brain in copy ass
{
	Cat gatto;
	Cat a;
	a = gatto;
	Dog cane;
	Dog b;
	b = cane;
} */

/* int main(void){
	Animal* tier[4];

	for(int i = 0; i < 4; i++){
		if (i < 2)
			tier[i] = new Dog();
		else
			tier[i] = new Cat();
	}

	for (int i = 0; i < 4; i++)
	{
		tier[i]->makeSound();
		delete tier[i];
	}
} */


/* int main()	//virtual destructor
{
const Animal* j = new Dog();
const Animal* i = new Cat();
delete j;//should not create a leak
delete i;

return 0;
} */


/* 
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
} */