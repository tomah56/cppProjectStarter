#include "Classmaker.hpp"

Classmaker::Classmaker( void )
{
	std::cout << "Classmaker Constructor called\n";
}

Classmaker::~Classmaker( void )
{
	std::cout << "Classmaker Destructore called\n";
}

static std::string make_upper(const std::string clasname)
{
	int	i;
	char temp[clasname.length()];
	
	for (i = 0; clasname[i]; i++)
	{
		if (clasname[i] <= 'z' && clasname[i] >= 'a')
			temp[i] = (char)toupper(clasname[i]);
		else
			temp[i] = clasname[i];
	}
	temp[i] = '\0';
	return (temp);
}

void Classmaker::setPath( const std::string &str )
{
	this->path = str + "/";
}

const std::string	&Classmaker::getpath() const
{
	return (this->path);
}

void Classmaker::createMainAndMakefile(int argc, char **argv) const
{
	std::ofstream	makefile;
	std::ofstream	mainfile;

	mainfile.open (this->getpath() + "main.cpp");
	for (int i = 2; i < argc; i++)
		mainfile	<< "#include \"" << argv[i] << ".hpp\""		<< std::endl;
	mainfile		<< "\nint	main( void )"					<< std::endl
					<< "{"										<< std::endl;
	for (int i = 2; i < argc; i++)
		mainfile	<< "\t" << argv[i] << "\ttemp" << i <<	";"	<< std::endl;
	mainfile		<< "\n\treturn (0);"						<< std::endl
					<< "}"										<< std::endl;
	mainfile.close();

	makefile.open (this->getpath() + "Makefile");

	makefile		<< "CC := c++"									<< std::endl
					<< "NAME := " << argv[2] 						<< std::endl
					<< "FLAGS := -Wall -Wextra -Werror -std=c++98"	<< std::endl
					<< "SRC := main.cpp "; 
	for (int i = 2; i < argc; i++)
		makefile	<< argv[i] << ".cpp ";
	makefile		<< "\nHEADERS := "; 
	for (int i = 2; i < argc; i++)
		makefile	<< argv[i] << ".hpp ";
	makefile	<< std::endl	<< "\nall: $(NAME)"					<< std::endl
				<< std::endl	<< "$(NAME): $(SRC) $(HEADERS)"		<< std::endl
				<< "\t@$(CC) $(FLAGS) $(SRC) -o $(NAME)"			<< std::endl
				<< std::endl	<< "no: $(SRC) $(HEADERS)"			<< std::endl
				<< "\t@$(CC) $(SRC) -o $(NAME)"						<< std::endl
				<< std::endl	<< "clean:\n\t@rm -f *.o"			<< std::endl
				<< std::endl	<< "fclean: clean\n\t@rm -f $(NAME)"	<< std::endl
				<< std::endl	<< "re: fclean all"					<< std::endl;
	makefile.close();
}

void Classmaker::createClass( const std::string &clasname ) const
{
	std::ofstream cppfile;
	std::ofstream hppfile;
	cppfile.open (this->getpath() + clasname + ".cpp");
	if ( cppfile.fail() )
	{
		std::cout << "Error: Failed to create file!";
		exit(1);
	}
	cppfile	<<	"#include \""	<<	clasname	<<	".hpp\""					<<	std::endl
																				<<	std::endl
			<<	clasname	<<	"::"	<< clasname	<< "( void )"				<<	std::endl
			<<	"{"																<<	std::endl
			<<	"\tstd::cout << \"" << clasname << " Constructor called\\n\";"	<<	std::endl
			<<	"}"																<<	std::endl
																				<<	std::endl
			<<	clasname	<<	"::~" << clasname << "( void )"					<<	std::endl
			<<	"{"																<<	std::endl
			<<	"\tstd::cout << \"" << clasname << " Destructor called\\n\";"	<<	std::endl
			<<	"}"																<<	std::endl
			;
	cppfile.close();

	hppfile.open (this->getpath() + clasname + ".hpp");
	hppfile	<< "#ifndef "	<< make_upper(clasname) << "_H__"	<<	std::endl
			<< "# define "	<< make_upper(clasname) << "_H__"	<<	std::endl
			<< "# include <iostream>\n"				<<	std::endl
			<< "class "		<< clasname << " {"		<<	std::endl
			<< "public:"							<<	std::endl
			<< "\t"	<<	clasname	<< "( void );"	<<	std::endl
			<<	"\t~"	<< clasname	<< "( void );"	<<	std::endl
			<<	"private:"							<<	std::endl
			<<	"};"								<<	std::endl
													<<	std::endl
			<<	"#endif"							<<	std::endl
			;
	hppfile.close();
}