// ruvolan/st/Форма.s
#include "../../ruvolan.ref.inc"
#include "Форма.hpp"
namespace st {

    void Форма::__vas_auto_debdata(::vas::Debdata::Context &ctx, bool hidden) const {
	if(hidden) {
	    ctx.out << "*(st::Форма,#" << ((void*)this) << ')';
	}
	else if(auto h = ctx.find_history(this)) {
	    ctx.out << "*(st::Форма,#" << ((void*)this) << ',' << h.relpath(ctx.path) << ')';
	}
	else {
	    std::string prev_indent(ctx.indent());
	    ::vas::Debdata::Level level(ctx);
	    if(ctx.level() < ctx.max_level) {
		ctx.out << "{*st::Форма #" << ((void*)this) << '\n';
		__vas_auto_debdata_fields(ctx);
		ctx.out << prev_indent << '}';
	    }
	    else ctx.out << "***LIMITED***";
	}
    }

    void Форма::__vas_auto_debdata_fields(::vas::Debdata::Context &ctx) const {
	Примитив::__vas_auto_debdata_fields(ctx);
    }
}
