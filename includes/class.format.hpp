/* -------------------------------------------------------------------------- */
/*                              class.format.hpp                              */
/* -------------------------------------------------------------------------- */

#ifndef CLASS_FORMAT_HPP
# define CLASS_FORMAT_HPP

#include <string>
#include <sstream>

class Format {

 private:
	std::string	_content;
	std::string _fg;
	std::string _bg;
	std::string _bold;
	std::string _underline;

 public:
/* ------------------------------ constructors ------------------------------ */

	Format(const std::string &content) : _content(content), _fg(""), _bg("") {};

	~Format() {};

/* -------------------------------- accessors ------------------------------- */


	std::string get(void) const {
		return (_fg + _bg + _bold + _underline + _content + getFormatCode("0"));
	};

	Format black(void) {
		_fg = getFormatCode("30");
		return *this;
	}
	Format red(void) {
		_fg = getFormatCode("31");
		return *this;
	}
	Format green(void) {
		_fg = getFormatCode("32");
		return *this;
	}
	Format yellow(void) {
		_fg = getFormatCode("33");
		return *this;
	}
	Format blue(void) {
		_fg = getFormatCode("34");
		return *this;
	}
	Format magenta(void) {
		_fg = getFormatCode("35");
		return *this;
	}
	Format cyan(void) {
		_fg = getFormatCode("36");
		return *this;
	}
	Format white(void) {
		_fg = getFormatCode("37");
		return *this;
	}

	Format blackBg(void) {
		_bg = getFormatCode("40");
		return *this;
	}
	Format redBg(void) {
		_bg = getFormatCode("41");
		return *this;
	}
	Format greenBg(void) {
		_bg = getFormatCode("42");
		return *this;
	}
	Format yellowBg(void) {
		_bg = getFormatCode("43");
		return *this;
	}
	Format blueBg(void) {
		_bg = getFormatCode("44");
		return *this;
	}
	Format magentaBg(void) {
		_bg = getFormatCode("45");
		return *this;
	}
	Format cyanBg(void) {
		_bg = getFormatCode("46");
		return *this;
	}
	Format whiteBg(void) {
		_bg = getFormatCode("47");
		return *this;
	}

	Format bold(void){
		_bold = getFormatCode("1");
		return *this;
	}
	Format underline(void){
		_underline = getFormatCode("4");
		return *this;
	}
/* ---------------------------- private functions --------------------------- */

 private:

	std::string getFormatCode(std::string code) const {
		return "\033[" + code + "m";
	}

};

/* --------------------------- functions-memebers --------------------------- */

inline std::ostream	&operator<<(std::ostream &output, const Format &instance) {
	output << instance.get();
	return (output);
};

#endif
