// ruvolan/u/Word.s
#include "../../ruvolan.ref.inc"
#include "../st/Примитив.hpp"
#include "Word.hpp"
namespace u {

    void Word::__vas_auto_debdata(::vas::Debdata::Context &ctx, bool hidden) const {
	if(hidden) {
	    ctx.out << "*(u::Word,#" << ((void*)this) << ')';
	}
	else if(auto h = ctx.find_history(this)) {
	    ctx.out << "*(u::Word,#" << ((void*)this) << ',' << h.relpath(ctx.path) << ')';
	}
	else {
	    std::string prev_indent(ctx.indent());
	    ::vas::Debdata::Level level(ctx);
	    if(ctx.level() < ctx.max_level) {
		ctx.out << "{*u::Word #" << ((void*)this) << '\n';
		std::string indent(ctx.indent());
		ctx.path.back() = "word";
		ctx.out << indent << "word: ";
		ctx.out << (void*)this->word;
		ctx.out << ",\n";
		ctx.out << prev_indent << '}';
	    }
	    else ctx.out << "***LIMITED***";
	}
    }
}
