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

	Format(const std::string &content);

	~Format();

/* -------------------------------- accessors ------------------------------- */

	std::string get(void) const;
	Format black(void);
	Format red(void);
	Format green(void);
	Format yellow(void);
	Format blue(void);
	Format magenta(void);
	Format cyan(void);
	Format white(void);

	Format blackBg(void);
	Format redBg(void);
	Format greenBg(void);
	Format yellowBg(void);
	Format blueBg(void);
	Format magentaBg(void);
	Format cyanBg(void);
	Format whiteBg(void);

	Format bold(void);
	Format underline(void);

/* ---------------------------- priavte functions --------------------------- */

 private:
	std::string getFormatCode(std::string code)const ;

};

/* --------------------------- functions-memebers --------------------------- */

	Format::Format(const std::string &content) : _content(content), _fg(""), _bg("") {};

	Format::~Format() {};

	std::string Format::get(void) const {
		return (_fg + _bg + _bold + _underline + _content + getFormatCode("0"));
	};

	std::string Format::getFormatCode(std::string code) const {
		return "\033[" + code + "m";
	}

	Format Format::black(void) {
		_fg = getFormatCode("30");
		return *this;
	}
	Format Format::red(void) {
		_fg = getFormatCode("31");
		return *this;
	}
	Format Format::green(void) {
		_fg = getFormatCode("32");
		return *this;
	}
	Format Format::yellow(void) {
		_fg = getFormatCode("33");
		return *this;
	}
	Format Format::blue(void) {
		_fg = getFormatCode("34");
		return *this;
	}
	Format Format::magenta(void) {
		_fg = getFormatCode("35");
		return *this;
	}
	Format Format::cyan(void) {
		_fg = getFormatCode("36");
		return *this;
	}
	Format Format::white(void) {
		_fg = getFormatCode("37");
		return *this;
	}

	Format Format::blackBg(void) {
		_bg = getFormatCode("40");
		return *this;
	}
	Format Format::redBg(void) {
		_bg = getFormatCode("41");
		return *this;
	}
	Format Format::greenBg(void) {
		_bg = getFormatCode("42");
		return *this;
	}
	Format Format::yellowBg(void) {
		_bg = getFormatCode("43");
		return *this;
	}
	Format Format::blueBg(void) {
		_bg = getFormatCode("44");
		return *this;
	}
	Format Format::magentaBg(void) {
		_bg = getFormatCode("45");
		return *this;
	}
	Format Format::cyanBg(void) {
		_bg = getFormatCode("46");
		return *this;
	}
	Format Format::whiteBg(void) {
		_bg = getFormatCode("47");
		return *this;
	}

	Format Format::bold(void){
		_bold = getFormatCode("1");
		return *this;
	}
	Format Format::underline(void){
		_underline = getFormatCode("4");
		return *this;
	}

	std::ostream	&operator<<(std::ostream &output, const Format &instance) {
		output << instance.get();
		return (output);
	};

#endif
