// ruvolan/u/words_init.m
#include "../../ruvolan.macro.ref.inc"
#include "words_init.hpp"
namespace u {
    ::Vasek::VasCodeEntityShp words_init::parse_vas_macro(::Vasek::Parser::Base &parser, ::Vasek::Token::BaseShp name_token) {
	auto root = parser.main_data.root_lock();
	auto exp = Vasek::Exp::Manual::shp(std::string());
	root->deferred_parse.emplace(Vasek::Root::DefaultDeferredPriority, [root, exp]() -> void {
	    std::stringstream txt;
	    bool first = true;
	    Vasek::Data::NamespaceShp ru = root->checked_lookup_names({"ru"})->exp_type();
	    for(auto &&w : ru->types) {
		if(w.second->is_struct()) {
		    std::string lc = w.first;
		    vas::utf8_ru_lc(lc);
		    if(first) {
			first = false;
		    }
		    else {
			txt << ',';
		    }
		    txt << "\n\t{\"" << lc << "\",[]() -> st::Примитив * { return new ru::" << w.first << "; }}";
		    exp->refs.emplace_back(Vasek::Data::BaseNamespace::RefsCategory::refs_code, dynamic_cast<Vasek::Data::BaseNamespace * >(w.second.get()));
		}
	    }
	    if(!first) {
		txt << '\n';
		exp->text = txt.str();
	    }
	});
	return exp;
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
