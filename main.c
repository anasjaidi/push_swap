#include <stdio.h>


void	func1(char *msg)
{
	printf("%s + 1",msg);
}

void	func2(char *msg)
{
	printf("%s + 1",msg);
}

void	(*function(int x))(char*);
void	(*function(int x))(char*)
{
	if (x == 1)
		return func1;
	else 
		return func2;
}


int main()
{
	void	(*f)(char*);

	f = function(1);
	(*f)("its ok");
}
