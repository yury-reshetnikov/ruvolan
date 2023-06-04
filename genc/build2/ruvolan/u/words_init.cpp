// ruvolan/u/words_init.m
#include "../../ruvolan.macro.ref.inc"
#include "words_init.hpp"
namespace u {
    ::Vasek::VasCodeEntityShp words_init::parse_vas_macro(::Vasek::Parser::Base &parser, ::Vasek::Token::BaseShp name_token) {
	std::cerr << "TODO ruvolan/u/words_init.m "
	    "4" // vas::warn
	    " parse_vas_macro " << std::endl << std::flush;
	return Vasek::VasCodeEntityShp();
    }

    void words_init::__vas_auto_debdata(::vas::Debdata::Context &ctx, bool hidden) const {
	if(hidden) {
	    ctx.out << "*(u::words_init,#" << ((void*)this) << ')';
	}
	else if(auto h = ctx.find_history(this)) {
	    ctx.out << "*(u::words_init,#" << ((void*)this) << ',' << h.relpath(ctx.path) << ')';
	}
	else {
	    std::string prev_indent(ctx.indent());
	    ::vas::Debdata::Level level(ctx);
	    if(ctx.level() < ctx.max_level) {
		ctx.out << "{*u::words_init #" << ((void*)this) << '\n';
		ctx.out << prev_indent << '}';
	    }
	    else ctx.out << "***LIMITED***";
	}
    }
}
