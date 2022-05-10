#include "Classmaker.hpp"

int main(int argc, char **argv)
{
	Classmaker letsMakeit;

	if (argc < 2)
		return (0);
	letsMakeit.setPath(argv[1]);
	for (int i = 2; i < argc; i++)
		letsMakeit.createClass(argv[i]);

	letsMakeit.createMainAndMakefile( argc, argv );

	return (0);
}