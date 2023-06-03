// ruvolan/st/Слово.s
#include "../../ruvolan.ref.inc"
#include "Слово.hpp"
namespace st {

    void Слово::__vas_auto_debdata(::vas::Debdata::Context &ctx, bool hidden) const {
	if(hidden) {
	    ctx.out << "*(st::Слово,#" << ((void*)this) << ')';
	}
	else if(auto h = ctx.find_history(this)) {
	    ctx.out << "*(st::Слово,#" << ((void*)this) << ',' << h.relpath(ctx.path) << ')';
	}
	else {
	    std::string prev_indent(ctx.indent());
	    ::vas::Debdata::Level level(ctx);
	    if(ctx.level() < ctx.max_level) {
		ctx.out << "{*st::Слово #" << ((void*)this) << '\n';
		__vas_auto_debdata_fields(ctx);
		ctx.out << prev_indent << '}';
	    }
	    else ctx.out << "***LIMITED***";
	}
    }

    void Слово::__vas_auto_debdata_fields(::vas::Debdata::Context &ctx) const {
	Примитив::__vas_auto_debdata_fields(ctx);
    }
}
