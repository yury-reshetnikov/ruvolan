// ruvolan/ru/Программа.s
#include "../../ruvolan.ref.inc"
#include "Программа.hpp"
namespace ru {

    void Программа::__vas_auto_debdata(::vas::Debdata::Context &ctx, bool hidden) const {
	if(hidden) {
	    ctx.out << "*(ru::Программа,#" << ((void*)this) << ')';
	}
	else if(auto h = ctx.find_history(this)) {
	    ctx.out << "*(ru::Программа,#" << ((void*)this) << ',' << h.relpath(ctx.path) << ')';
	}
	else {
	    std::string prev_indent(ctx.indent());
	    ::vas::Debdata::Level level(ctx);
	    if(ctx.level() < ctx.max_level) {
		ctx.out << "{*ru::Программа #" << ((void*)this) << '\n';
		__vas_auto_debdata_fields(ctx);
		ctx.out << prev_indent << '}';
	    }
	    else ctx.out << "***LIMITED***";
	}
    }

    void Программа::__vas_auto_debdata_fields(::vas::Debdata::Context &ctx) const {
	st::Существительное::__vas_auto_debdata_fields(ctx);
    }
}
