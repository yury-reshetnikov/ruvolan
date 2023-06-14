// ruvolan/ru/Составлять.s
#include "../../ruvolan.ref.inc"
#include "Составлять.hpp"
namespace ru {
    Составлять::Составлять()
	: st::Глагол()
    {
    }

    Составлять::Составлять(Примитив *actual_form)
	: st::Глагол(actual_form)
    {
    }

    void Составлять::__vas_auto_debdata(::vas::Debdata::Context &ctx, bool hidden) const {
	if(hidden) {
	    ctx.out << "*(ru::Составлять,#" << ((void*)this) << ')';
	}
	else if(auto h = ctx.find_history(this)) {
	    ctx.out << "*(ru::Составлять,#" << ((void*)this) << ',' << h.relpath(ctx.path) << ')';
	}
	else {
	    std::string prev_indent(ctx.indent());
	    ::vas::Debdata::Level level(ctx);
	    if(ctx.level() < ctx.max_level) {
		ctx.out << "{*ru::Составлять #" << ((void*)this) << '\n';
		__vas_auto_debdata_fields(ctx);
		ctx.out << prev_indent << '}';
	    }
	    else ctx.out << "***LIMITED***";
	}
    }

    void Составлять::__vas_auto_debdata_fields(::vas::Debdata::Context &ctx) const {
	st::Глагол::__vas_auto_debdata_fields(ctx);
    }
}
