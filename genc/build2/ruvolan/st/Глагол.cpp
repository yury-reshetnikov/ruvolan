// ruvolan/st/Глагол.s
#include "../../ruvolan.ref.inc"
#include "Глагол.hpp"
namespace st {
    Глагол::Глагол()
	: Слово()
    {
    }

    Глагол::Глагол(Примитив *actual_form)
	: Слово(actual_form)
    {
    }

    void Глагол::__vas_auto_debdata(::vas::Debdata::Context &ctx, bool hidden) const {
	if(hidden) {
	    ctx.out << "*(st::Глагол,#" << ((void*)this) << ')';
	}
	else if(auto h = ctx.find_history(this)) {
	    ctx.out << "*(st::Глагол,#" << ((void*)this) << ',' << h.relpath(ctx.path) << ')';
	}
	else {
	    std::string prev_indent(ctx.indent());
	    ::vas::Debdata::Level level(ctx);
	    if(ctx.level() < ctx.max_level) {
		ctx.out << "{*st::Глагол #" << ((void*)this) << '\n';
		__vas_auto_debdata_fields(ctx);
		ctx.out << prev_indent << '}';
	    }
	    else ctx.out << "***LIMITED***";
	}
    }

    void Глагол::__vas_auto_debdata_fields(::vas::Debdata::Context &ctx) const {
	Слово::__vas_auto_debdata_fields(ctx);
    }
}
