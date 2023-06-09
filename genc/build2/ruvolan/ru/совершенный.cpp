// ruvolan/ru/совершенный.m
#include "../../ruvolan.macro.ref.inc"
#include "совершенный.hpp"
namespace ru {
    ::Vasek::VasCodeEntityShp совершенный::parse_vas_macro(::Vasek::Parser::Base &parser, ::Vasek::Token::BaseShp name_token) {
	auto form = ([](decltype(parser) &rdr) -> ::Vasek::Token::BaseShp {
	    auto token = rdr.next_skip();
	    if(token->test(::Vasek::Token::tc_Word)) return token;
	    else throw ::vas::Error(::vas::Error::Pos("ruvolan/ru/совершенный.m",
		4), // vas::throw
		::vas::Error::Pos(__FILE__, __LINE__), "parse_vas_macro", (::vas::dss() << "*token:" << *token << " valid:Word").s->str());
	})(parser);
	parser.cmd_end();
	Vasek::Data::BaseNamespaceShp uph = parser.main_data.up_lock();
	auto s = Vasek::Data::Struct::shp(uph, form->text, fs::directory_entry());
	s->read_source_state = Vasek::PrDone;
	uph->types.emplace(form->text, s);
	Vasek::Parser::parse_decls(name_token, *s, ":st::Совершенный");
	Vasek::Parser::parse_decls(name_token, *s, (::vas::dss() << "override st::Примитив *main_form() { return new " << (parser.main_data.name) << "(this); }").s->str());
	return Vasek::VasCodeEntityShp();
    }

    void совершенный::__vas_auto_debdata(::vas::Debdata::Context &ctx, bool hidden) const {
	if(hidden) {
	    ctx.out << "*(ru::совершенный,#" << ((void*)this) << ')';
	}
	else if(auto h = ctx.find_history(this)) {
	    ctx.out << "*(ru::совершенный,#" << ((void*)this) << ',' << h.relpath(ctx.path) << ')';
	}
	else {
	    std::string prev_indent(ctx.indent());
	    ::vas::Debdata::Level level(ctx);
	    if(ctx.level() < ctx.max_level) {
		ctx.out << "{*ru::совершенный #" << ((void*)this) << '\n';
		ctx.out << prev_indent << '}';
	    }
	    else ctx.out << "***LIMITED***";
	}
    }
}
