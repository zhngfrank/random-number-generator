#ifndef RAND_H
#define RAND_H

#include <iostream>
#include <ctime>
#include <cmath>



double rand();
int get_seed();
void test_num();

double rand() {
//	for function generator in the form of Xn+1 = (AXn+C)modM
	test_num(); //1
	
	unsigned int iterations = get_seed() * 0.5;
	test_num(); // 2
	
	unsigned int a = get_seed() % 20;
	test_num(); //3
	
	double increment = get_seed() % 100;
	increment = sqrt((double)increment);
	test_num(); //4
	
//	unsigned int c = (a + 20) * (get_seed() % 20); 
	unsigned int c = 10;
	test_num(); //5
	
//	unsigned int m = get_seed() * a;
	unsigned int m = 10;
	test_num();//6
	
	unsigned int random = get_seed();
	
	if (random == 0) {
		random ++;
	} 
	
	std::cout << "formula used: Xn+1 = (" << a << "*Xn+" << c << ")" << "mod" 
			  << m << std::endl;
			  
	std::cout << "and seed is" << random << std::endl;
	std::cout << "and increment is: "<< increment << 
				 "along with max iterations: " << iterations << std::endl;
	
	for (double i = 0; i<iterations; i+= increment) {
		random = (a * random + c) % m;
	}
	
//	for (int i = 0; i < 10; i++) {
//		random = (a * random + c) % m;
//		
//		std::cout << "random = " << random << std::endl; 
//	}
	std::cout << m << std::endl;
	
	double finalrand = (double)random / m;
	
	std::cout << "exiting rand w/ rand = " << finalrand << std::endl;
	return finalrand;

}

int get_seed() {
	time_t seconds;

	time(&seconds);
	
	if (seconds < 0) {
		seconds = -1 * seconds;
	}
	if (seconds == 0) {
		seconds = 1;
	}
	std::cout << "current time is " << seconds << std::endl;
	
	
	
	return seconds;
	
}

void test_num() {
	static int i = 1;
	
	std::cout << "current position: " << i << std::endl;
	
	i++;
}

#endif
