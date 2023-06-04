// ruvolan/ru/винительный_единственное.m
#include "../../ruvolan.macro.ref.inc"
#include "винительный_единственное.hpp"
namespace ru {
    ::Vasek::VasCodeEntityShp винительный_единственное::parse_vas_macro(::Vasek::Parser::Base &parser, ::Vasek::Token::BaseShp name_token) {
	auto form = ([](decltype(parser) &rdr) -> ::Vasek::Token::BaseShp {
	    auto token = rdr.next_skip();
	    if(token->test(::Vasek::Token::tc_Word)) return token;
	    else throw ::vas::Error(::vas::Error::Pos("ruvolan/ru/винительный_единственное.m",
		4), // vas::throw
		::vas::Error::Pos(__FILE__, __LINE__), "parse_vas_macro", (::vas::dss() << "*token:" << *token << " valid:Word").s->str());
	})(parser);
	parser.cmd_end();
	std::cerr << "TODO ruvolan/ru/винительный_единственное.m "
	    "6" // vas::warn
	    " parse_vas_macro " << std::endl << std::flush;
	return Vasek::VasCodeEntityShp();
    }

    void винительный_единственное::__vas_auto_debdata(::vas::Debdata::Context &ctx, bool hidden) const {
	if(hidden) {
	    ctx.out << "*(ru::винительный_единственное,#" << ((void*)this) << ')';
	}
	else if(auto h = ctx.find_history(this)) {
	    ctx.out << "*(ru::винительный_единственное,#" << ((void*)this) << ',' << h.relpath(ctx.path) << ')';
	}
	else {
	    std::string prev_indent(ctx.indent());
	    ::vas::Debdata::Level level(ctx);
	    if(ctx.level() < ctx.max_level) {
		ctx.out << "{*ru::винительный_единственное #" << ((void*)this) << '\n';
		ctx.out << prev_indent << '}';
	    }
	    else ctx.out << "***LIMITED***";
	}
    }
}
