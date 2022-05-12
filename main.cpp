#include "Classmaker.hpp"

static int checkPath( char *str )
{
	int i;

	if (str[0] != '.')
		return (1);
	if (str[1] != '/' && (str[1] == '.' && (str[2] != '/')))
		return (1);
	i = 0;
	while ( str[i] )
		i++;
	if (i < 2 && str[i - 1] == '/')
		return (1);
	return (0);
}

int main(int argc, char **argv)
{
	Classmaker letsMakeit;

	if (argc < 2)
		return (0);
	if (checkPath( argv[1] ))
	{
		std::cout << "Sure about that path?\n(./some/some type?)\n";
		return (0);
	}
	

	letsMakeit.setPath(argv[1]);
	for (int i = 2; i < argc; i++)
		letsMakeit.createClass(argv[i]);

	letsMakeit.createMainAndMakefile( argc, argv );

	return (0);
}