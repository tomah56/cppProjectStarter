#ifndef CLASSMAKER_H__
# define CLASSMAKER_H__

# include <iostream>
# include <fstream>
# include <string>

class Classmaker {
public:
	// Classmaker( const std::string &clasname );
	Classmaker( void );
	~Classmaker( void );
	const std::string	&getpath() const;
	void				setPath( const std::string &str );
	void createClass(const std::string &clasname ) const;
	void createMainAndMakefile(int argc, char **argv) const;
private:
	std::string	path;
};

#endif
